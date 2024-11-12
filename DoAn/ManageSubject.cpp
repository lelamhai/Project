#include "ManageSubject.h"

ManageSubject::ManageSubject()
{
    loadFromFile();
}

ManageSubject::~ManageSubject()
{
}

PTRSUBJECT ManageSubject::getListSubject()
{
    return subjectList;
}

// ----------------------- PUBLIC METHOD --------------------------//
// Thêm môn học mới
bool ManageSubject::addSubject(const char* code, const string& name) {
    PTRSUBJECT subjectFound = searchSubject(subjectList, code);
    if (subjectFound != nullptr) return false;
    PTRSUBJECT newNode = new SubjectNode;
    strcpy_s(newNode->info.subjectCode, code);
    newNode->info.subjectName = name;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1;

    if (subjectList == nullptr) {
        subjectList = newNode;
    }
    else {
        subjectList = insertBalance(subjectList, newNode);
    }
    saveToFile();
    return true;
}

// Tìm kiếm môn học theo mã môn học
PTRSUBJECT ManageSubject::getSubject(const char* code) {
    return searchSubject(subjectList, code);
}

// Thêm câu hỏi vào môn học
bool ManageSubject::addQuestion(const char* subjectCode, const string& content,
    const string& optionA, const string& optionB,
    const string& optionC, const string& optionD, char answer) {

    // Tìm kiếm môn học dựa trên mã môn học
    PTRSUBJECT subject = getSubject(subjectCode);

    if (subject) {
        // Nếu tìm thấy môn học, thêm câu hỏi
        addQuestionToSubject(subject, content, optionA, optionB, optionC, optionD, answer);
        saveToFile();
        return true;
    }
    return false;
}

// In danh sách tất cả các môn học
void ManageSubject::printAllSubjects() {
    printSubjects(subjectList);
}

int ManageSubject::getCountSubjects()
{
    return countSubjectsInRoot(subjectList);
}



// Hàm tính tổng số câu hỏi của một môn học dựa trên mã môn học
int ManageSubject::countQuestionsInSubject(const char* subjectCode) {
    PTRSUBJECT subject = getSubject(subjectCode);
    if (subject) {
        return getCountQuestionInList(subject->info.listQuestion);
    }
    else {
        cout << "Subject not found!" << endl;
        return 0;
    }
}

void ManageSubject::saveToFile() {
    json j;  // Tạo đối tượng JSON để lưu dữ liệu môn học

    // Duyệt cây nhị phân theo chiều sâu (DFS)
    saveSubjectToJson(subjectList, j);

    // Ghi đối tượng JSON vào file
    ofstream file("subjects.json");
    if (file.is_open()) {
        file << j.dump(4);  // Lưu với định dạng đẹp (indent = 4)
        file.close();
        cout << "Data saved successfully in JSON format." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }
}

// Hàm hỗ trợ duyệt cây nhị phân và lưu vào JSON
void ManageSubject::saveSubjectToJson(PTRSUBJECT node, json& j) {
    if (node == nullptr) return;

    // Tạo đối tượng JSON cho môn học
    json subjectData;
    subjectData["subjectCode"] = node->info.subjectCode;
    subjectData["subjectName"] = node->info.subjectName;

    // Mảng câu hỏi của môn học
    subjectData["questions"] = json::array();
    PTRQUESTION questionPtr = node->info.listQuestion;
    int questionIndex = 0;
    while (questionPtr != nullptr) {
        json questionData;
        questionData["questionId"] = questionPtr->info.questionId;
        questionData["content"] = questionPtr->info.content;
        questionData["optionA"] = questionPtr->info.optionA;
        questionData["optionB"] = questionPtr->info.optionB;
        questionData["optionC"] = questionPtr->info.optionC;
        questionData["optionD"] = questionPtr->info.optionD;
        questionData["answer"] = questionPtr->info.answer;

        subjectData["questions"][questionIndex++] = questionData;
        questionPtr = questionPtr->next;
    }

    // Thêm môn học vào mảng môn học trong JSON
    j["subjects"].push_back(subjectData);

    // Tiếp tục duyệt cây nhị phân
    saveSubjectToJson(node->left, j);
    saveSubjectToJson(node->right, j);
}

void ManageSubject::loadFromFile() {
    ifstream file("subjects.json");

    if (!file.is_open()) {
        cout << "Unable to open file for loading." << endl;
        return;
    }

    json j;
    file >> j;  // Đọc dữ liệu từ file vào đối tượng JSON
    file.close();

    // Kiểm tra dữ liệu JSON có hợp lệ không
    if (j.contains("subjects") && j["subjects"].is_array()) {
        // Duyệt qua mảng môn học trong JSON và thêm vào cây nhị phân
        for (const auto& subjectData : j["subjects"]) {
            Subject newSubject;

            // Kiểm tra và lấy subjectCode
            if (subjectData.contains("subjectCode") && subjectData["subjectCode"].is_string()) {
                strcpy_s(newSubject.subjectCode, subjectData["subjectCode"].get<string>().c_str());
            }

            // Kiểm tra và lấy subjectName
            if (subjectData.contains("subjectName") && subjectData["subjectName"].is_string()) {
                newSubject.subjectName = subjectData["subjectName"].get<string>();
            }

            // Xử lý danh sách câu hỏi
            PTRQUESTION lastQuestion = nullptr;
            if (subjectData.contains("questions") && subjectData["questions"].is_array()) {
                for (const auto& questionData : subjectData["questions"]) {
                    Question newQuestion;
                    newQuestion.questionId = questionData["questionId"];
                    newQuestion.content = questionData["content"];
                    newQuestion.optionA = questionData["optionA"];
                    newQuestion.optionB = questionData["optionB"];
                    newQuestion.optionC = questionData["optionC"];
                    newQuestion.optionD = questionData["optionD"];

                    // Kiểm tra answer và lấy ký tự đầu tiên
                    //if (questionData.contains("answer") && questionData["answer"].is_string()) {
                    //    newQuestion.answer = questionData["answer"].get<string>()[0];
                    //}
                    newQuestion.answer = questionData["answer"].get<char>();

                    // Chèn câu hỏi vào danh sách câu hỏi của môn học
                    PTRQUESTION questionNode = new NodeQuestion;
                    questionNode->info = newQuestion;
                    questionNode->next = nullptr;

                    if (!newSubject.listQuestion) {
                        newSubject.listQuestion = questionNode;
                    }
                    else {
                        lastQuestion->next = questionNode;
                    }
                    lastQuestion = questionNode;
                }
            }

            // Thêm môn học vào cây nhị phân cân bằng
            insertSubject(newSubject);
        }
    }

    cout << "Data loaded successfully from JSON format." << endl;
}

// Hàm in ra tất cả câu hỏi của một môn học
void ManageSubject::printQuestionList(const char* subjectCode) {

    PTRQUESTION a = getSubject(subjectCode)->info.listQuestion;
    if (a == nullptr) {
        cout << "No questions available for this subject." << endl;
        return;
    }

    // Duyệt qua danh sách câu hỏi và in ra thông tin
    while (a != nullptr) {
        cout << "Question ID: " << a->info.questionId << endl;
        cout << "Content: " << a->info.content << endl;
        cout << "A. " << a->info.optionA << endl;
        cout << "B. " << a->info.optionB << endl;
        cout << "C. " << a->info.optionC << endl;
        cout << "D. " << a->info.optionD << endl;
        cout << "Answer: " << a->info.answer << endl << endl;
        a = a->next; // Di chuyển đến câu hỏi tiếp theo
    }
}

int* ManageSubject::getRandomQuestion(int n, const char* subjectCode) { //truyền vào số câu hỏi thi và mã môn học
    int totalQuestion = countQuestionsInSubject(subjectCode);
    if (n > totalQuestion) {
        cout << "Số lượng câu hỏi vượt quá tổng kho câu hỏi " << endl;
        return nullptr;
    }
    
    // Tạo mảng để lưu tất cả các questionId của môn học
    int* questionID = new int[totalQuestion];
    PTRSUBJECT subject = searchSubject(subjectList, subjectCode);
    PTRQUESTION listQuestion = subject->info.listQuestion;

    // Lưu từng questionId của môn học vào mảng
    for (int i = 0; i < totalQuestion; i++) {
        questionID[i] = listQuestion->info.questionId;
        listQuestion = listQuestion->next;       
    }

    // trộn ngẫu nhiên mảng
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = totalQuestion - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(questionID[i], questionID[j]);
    }

    // Tạo mảng kết quả và sao chép n câu hỏi đầu tiên trong mảng đã trộn
    int* randomQuestion = new int[n];
    for (int i = 0; i < n; i++) {
        randomQuestion[i] = questionID[i];
    }

    // Giải phóng bộ nhớ của questionID
    delete[] questionID;

    // Trả về mảng chứa n câu hỏi ngẫu nhiên
    return randomQuestion;
}

// ----------------------- PRIVATE METHOD --------------------------//
// Hàm giúp tạo SubjectNode mới
PTRSUBJECT ManageSubject::createSubjectNode(const char* code, const string& name) {
    PTRSUBJECT newNode = new SubjectNode;
    strcpy_s(newNode->info.subjectCode, code);
    newNode->info.subjectName = name;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1;  // Khởi tạo chiều cao của cây nhị phân
    newNode->info.listQuestion = nullptr; // Danh sách câu hỏi bắt đầu là trống
    return newNode;
}

// Hàm chèn môn học vào cây nhị phân cân bằng
void ManageSubject::insertSubject(const Subject& subject) {
    PTRSUBJECT newNode = new SubjectNode;
    newNode->info = subject;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1;

    if (subjectList == nullptr) {
        subjectList = newNode;
    }
    else {
        subjectList = insertBalance(subjectList, newNode);
    }
}

PTRSUBJECT ManageSubject::insertBalance(PTRSUBJECT root, PTRSUBJECT newNode) {
    if (root == nullptr) return newNode;

    if (strcmp(newNode->info.subjectCode, root->info.subjectCode) < 0) {
        root->left = insertBalance(root->left, newNode);
    }
    else {
        root->right = insertBalance(root->right, newNode);
    }

    // Cập nhật chiều cao của cây
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Cân bằng cây nếu cần
    int balance = getBalance(root);

    // Xoay trái nếu cần
    if (balance > 1 && strcmp(newNode->info.subjectCode, root->left->info.subjectCode) < 0) {
        return rotateRight(root);
    }

    // Xoay phải nếu cần
    if (balance < -1 && strcmp(newNode->info.subjectCode, root->right->info.subjectCode) > 0) {
        return rotateLeft(root);
    }

    // Xoay trái-phải
    if (balance > 1 && strcmp(newNode->info.subjectCode, root->left->info.subjectCode) > 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Xoay phải-trái
    if (balance < -1 && strcmp(newNode->info.subjectCode, root->right->info.subjectCode) < 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

PTRSUBJECT ManageSubject::rotateLeft(PTRSUBJECT z) {
    PTRSUBJECT y = z->right;
    PTRSUBJECT T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

PTRSUBJECT ManageSubject::rotateRight(PTRSUBJECT z) {
    PTRSUBJECT y = z->left;
    PTRSUBJECT T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int ManageSubject::getHeight(PTRSUBJECT node) {
    return (node == nullptr) ? 0 : node->height;
}

int ManageSubject::getBalance(PTRSUBJECT node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Hàm tìm kiếm môn học theo mã môn
PTRSUBJECT ManageSubject::searchSubject(PTRSUBJECT root, const char* code) {
    if (root == nullptr || strcmp(root->info.subjectCode, code) == 0)
        return root;
    if (strcmp(code, root->info.subjectCode) < 0)
        return searchSubject(root->left, code);
    return searchSubject(root->right, code);
}

// Hàm thêm câu hỏi vào môn học
void ManageSubject::addQuestionToSubject(PTRSUBJECT subjectNode, const string& content,
    const string& optionA, const string& optionB,
    const string& optionC, const string& optionD, char answer) {
    // Tạo câu hỏi mới
    PTRQUESTION newQuestion = new NodeQuestion;
    // Sinh tự động questionId
    newQuestion->info.questionId = generateUniqueQuestionId(subjectNode->info.listQuestion);

    newQuestion->info.content = content;
    newQuestion->info.optionA = optionA;
    newQuestion->info.optionB = optionB;
    newQuestion->info.optionC = optionC;
    newQuestion->info.optionD = optionD;
    newQuestion->info.answer = answer;
    newQuestion->next = nullptr;
    // Thêm câu hỏi vào danh sách câu hỏi của môn học
    //newQuestion->next = subjectNode->info.listQuestion;
    //subjectNode->info.listQuestion = newQuestion;
    if (subjectNode->info.listQuestion == nullptr) {
        newQuestion->next = nullptr;
        subjectNode->info.listQuestion = newQuestion;
        return;
    }
    PTRQUESTION p = subjectNode->info.listQuestion;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = newQuestion;
    return;
}

// Hàm in tất cả các môn học (traversal cây nhị phân)
void ManageSubject::printSubjects(PTRSUBJECT root) {
    if (!root) return;
    printSubjects(root->left);
    cout << "Subject Code: " << root->info.subjectCode << ", Subject Name: " << root->info.subjectName << endl;
    printSubjects(root->right);
}

// Hàm giải phóng bộ nhớ khi xóa môn học
void ManageSubject::deleteSubject(PTRSUBJECT root) {
    if (!root) return;
    deleteSubject(root->left);
    deleteSubject(root->right);

    // Xóa danh sách câu hỏi
    PTRQUESTION temp = root->info.listQuestion;
    while (temp) {
        PTRQUESTION toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    delete root;
}

int ManageSubject::countSubjectsInRoot(PTRSUBJECT root) {
    // Đếm tổng số môn học
    if (!root) return 0;
    return 1 + countSubjectsInRoot(root->left) + countSubjectsInRoot(root->right);
}



