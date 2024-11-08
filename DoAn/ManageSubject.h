#pragma once
#include "StrucData.h"
#include "ManageQuestion.h"
#include <fstream> 

class ManageSubject
{
private:
	PTRSUBJECT subjectList;

    // Hàm giúp tạo SubjectNode mới
    PTRSUBJECT createSubjectNode(const char* code, const string& name);

    void insertSubject(const Subject& subject);
    
    PTRSUBJECT insertBalance(PTRSUBJECT root, PTRSUBJECT newNode);

    int getBalance(PTRSUBJECT node);

    int getHeight(PTRSUBJECT node);

    PTRSUBJECT rotateRight(PTRSUBJECT z);

    PTRSUBJECT rotateLeft(PTRSUBJECT z);

    // Hàm tìm kiếm môn học theo mã môn
    PTRSUBJECT searchSubject(PTRSUBJECT root, const char* code);

    // Hàm thêm câu hỏi vào môn học
    void addQuestionToSubject(PTRSUBJECT subjectNode, const string& content,
        const string& optionA, const string& optionB,
        const string& optionC, const string& optionD, char answer);

    // Hàm in tất cả các môn học (traversal cây nhị phân)
    void printSubjects(PTRSUBJECT root);

    // Hàm giải phóng bộ nhớ khi xóa môn học
    void deleteSubject(PTRSUBJECT root);

    // Đếm số môn học
    int countSubjectsInRoot(PTRSUBJECT root);

    // Lưu dưới dạng json
    void saveSubjectToJson(PTRSUBJECT node, json& j);
public:
	ManageSubject();
	~ManageSubject();

    PTRSUBJECT getListSubject();

    // Thêm môn học mới
    bool addSubject(const char* code, const string& name);

    // Tìm kiếm môn học theo mã môn học
    PTRSUBJECT getSubject(const char* code);

    // Thêm câu hỏi vào môn học
    bool addQuestion(const char* subjectCode, const string& content, const string& optionA, const string& optionB, const string& optionC, const string& optionD, char answer);

    // In danh sách tất cả các môn học
    void printAllSubjects();

    int getCountSubjects();

    int countQuestionsInSubject(const char* subjectCode);

   
    void saveToFile();

    void loadFromFile();
};
