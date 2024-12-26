#pragma once
#include "StrucData.h"
#include "ManageQuestion.h"
#include "ManageClass.h"
#include <fstream> 

const string SUBJECT_FILE_NAME = "SubjectData.json";

struct SubjectPage {
    PTRSUBJECT subjects = new SubjectNode;
    int currentPage; // trang hiện tại
    int numberSubjectPerPage; // tổng số trên 1 trang
    int totalPage; // tổng số trang
    int totalSubject; // tổng số
    int startIndex; // Số thứ tự bắt đầu của trang đó
    int endIndex; // số kết thúc của trang đó
};

class ManageSubject
{
private:
	PTRSUBJECT subjectList;

    // Hàm giúp tạo SubjectNode mới
    PTRSUBJECT createSubjectNode(const char* code, const string& name);

    void insertSubjectHelper(PTRSUBJECT& subjectList, const Subject& subject);

    void insertSubject(const Subject& subject);
    
    // Hàm tìm kiếm môn học theo mã môn
    PTRSUBJECT searchSubject(PTRSUBJECT root, const char* code);

    // Hàm thêm câu hỏi vào môn học
    void addQuestionToSubject(PTRSUBJECT& subjectNode, const string& content,
        const string& optionA, const string& optionB,
        const string& optionC, const string& optionD, char answer);

    // Hàm in tất cả các môn học (traversal cây nhị phân)
    void printSubjects(PTRSUBJECT root);

    void printSubjectsD(PTRSUBJECT root);

    // Hàm giải phóng bộ nhớ khi xóa môn học
    void deleteSubject(PTRSUBJECT root);

    // Đếm số môn học
    int countSubjectsInRoot(PTRSUBJECT root);

    // Lưu dưới dạng json
    void saveSubjectToJson(PTRSUBJECT node, json& j);

    void deleteTree(PTRSUBJECT& root);

    void collectMatchingSubjects(PTRSUBJECT root, PTRSUBJECT& tempTree, const string& keyword);
public:
	ManageSubject();
	~ManageSubject();

    PTRSUBJECT getListSubject();

    // Thêm môn học mới
    bool addSubject(const string code, const string name);

    // Chỉnh sửa một môn học
    bool editSubject(const string code, const string subjectName);

    // Tìm kiếm môn học theo mã môn học
    PTRSUBJECT getSubject(const char* code);

    // Hàm tìm xem môn học có tồn tại theo mã môn
    bool isSubjectExist(const string subjectCode);

    // Thêm câu hỏi vào môn học
    bool addQuestionInSubject(const char* subjectCode, const string& content, const string& optionA, const string& optionB, const string& optionC, const string& optionD, char answer);

    // Chỉnh sửa câu hỏi trong môn học
    bool editQuestionInSubject(const string subjectCode, int questionId, const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer);

    // Ham kiem tra xem co the xoa 1 cau hoi hay khong
    bool isQuestionCanDelete(const string subjectCode, int questionId);

    // Xóa 1 câu hỏi
    bool deleteQuestionInSubject(const string subjectCode, int questionId);

    QuestionPage searchQuestionInSubject(const string subjectCode, const string keyword, int pageNumber);

    // Hàm lấy ra thông tin câu hỏi 
    Question getQuestionBySubjectCodeAndId(const string subjectCode, int questionId);

    void setIsInExamOfQuestion(const char* subjectCode, int questionId);

    // In danh sách tất cả các môn học
    void printAllSubjects();

    // Lấy ra tổng số môn học hiện có
    int getCountSubjects();

    // Đếm số lượng câu hỏi trong môn
    int countQuestionsInSubject(const char* subjectCode);
    
    // Lưu thông tin môn học xuống file
    void saveToFile();

    // Load thông tin từ file lên
    void loadFromFile();

    void printQuestionList(const char* subjectCode);

    ManageQuestion getRandomQuestion(int n, const char* subjectCode);

    SubjectPage getSubjectPerPage(int pageNumber);

    SubjectPage searchSubjects(string keyword, int page);

    void getPageSubject(PTRSUBJECT& result, PTRSUBJECT root, int& count, int startIndex, int endIndex);

    bool isSubjectCanDelete(const string subjectCode);

    bool deleteSubject(string code);

    void reset();

    static string getSubjectNameFromCode(const char* subjectCode);
};

PTRSUBJECT insertBalance(PTRSUBJECT root, PTRSUBJECT newNode);

int getBalance(PTRSUBJECT node);

int getHeight(PTRSUBJECT node);

void updateHeight(PTRSUBJECT node);

PTRSUBJECT rotateRight(PTRSUBJECT z);

PTRSUBJECT rotateLeft(PTRSUBJECT z);

void insertSubjectToTree(PTRSUBJECT& root, string subjectCode, string subjectName);

void printSubjectInAVL(PTRSUBJECT root);

PTRSUBJECT getMinValueNode(PTRSUBJECT node);

void deleteNodeCase3(PTRSUBJECT& root);

bool deleteNode(PTRSUBJECT& root, string code);

int countSubjectsInList(PTRSUBJECT root);