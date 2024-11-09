#include "ContentAbout.h"

ContentAbout::ContentAbout()
{
}

ContentAbout::~ContentAbout()
{
}

void ContentAbout::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	title();
	content();
}

void ContentAbout::title()
{
	gotoXY(34, 10);
	cout << "Gioi Thieu";
}

void ContentAbout::content()
{
	gotoXY(34, 12);
	cout << "- Phan mem thi trac nghiem la cong cu ho tro dac luc cho viec on luyen va danh gia kien thuc. Voi kho cau hoi phong phu, giao dien truc quan va tinh nang cham diem tu";
	gotoXY(34, 13);
	cout << "dong, phan mem giup ban tu tin hon khi buoc vao cac ky thi.";
	gotoXY(34, 15);
	cout << "- Phan mem thi trac nghiem la giai phap hoan hao de ban tu kiem tra kien thuc mot cach nhanh chong va hieu qua. Chi voi vai thao tac don gian, ban co the tao ra cac";
	gotoXY(34, 16);
	cout << "bai thi theo y muon va nhan ket qua ngay lap tuc.";


	gotoXY(34, 20);
	cout << "* Huong Dan Su Dung Menu";
	gotoXY(34, 22);
	cout << "1) PGUP|PGDOWN.";
	gotoXY(34, 24);
	cout << "2) Mau xanh la cay la muc ban chon.";
	gotoXY(34, 26);
	cout << "3) Mau xanh nuoc bien la muc ban dang lua chon.";


	gotoXY(34, 30);
	cout << "* Phim Nong";
	gotoXY(34, 32);
	cout << "- F1: Chuc nang";
	gotoXY(34, 34);
	cout << "- F2: Chuc nang";
	gotoXY(34, 36);
	cout << "- F3: Chuc nang";
}