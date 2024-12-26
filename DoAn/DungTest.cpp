#include "DungTest.h"


DungTest::DungTest()
{
}

DungTest::~DungTest()
{
}

void DungTest::main()
{
	ManageSubject subjects;
	ManageClass classes;

	////1. Ham kiem tra xem mon hoc co ton tai
	//bool isSubjectExist = subjects.isSubjectExist("VL");
	//cout << "Mon hoc ton tai " << isSubjectExist << endl;

	////2. Ham kiem tra xem lop co ton tai
	//bool isClassExist = classes.isClassExist("");
	//cout << "Lop hoc ton tai " << isClassExist << endl;

	////3. Ham kiem tra xem hoc sinh da ton tai
	//bool isStudentExist = classes.isStudentExist("");
	//cout << "Hoc sinh ton tai " << isStudentExist << endl;

	////4. Ham kiem tra xem lop co the xoa
	//bool isClassCanDelete = classes.isClassCanDelete("C002");
	//cout << "Lop co the xoa " << isClassCanDelete << endl;

	//// 5. Ham kiem tra xem sinh vien co the xoa 
	//bool isStudentCanDelete = classes.isStudentCanDelete("K23DTCN273");
	//cout << "Hoc sinh co the xoa " << isStudentCanDelete << endl;

	//// 6. Ham kiem tra xem lop co the xoa
	//bool isSubjectCanDelete = subjects.isSubjectCanDelete("CTDL");
	//cout << "Mon hoc Co the xoa " << isSubjectCanDelete << endl;

	//// 7. Ham kiem tra xem cau hoi co the xoa
	//bool isQuestionCanDelete = subjects.isQuestionCanDelete("CSDL", 65098);
	//cout << "Cau hoi co the xoa " << isQuestionCanDelete << endl;

	//subjects.printAllSubjects();
	
	bool isdeleted = subjects.deleteSubject("SDFFSGDF");

	PTRSUBJECT a = subjects.getSubject("SDFFSGDFS");

	subjects.printAllSubjects();
	

}
	
