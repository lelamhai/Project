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
	cout << "1) PGUP|PGDOWN: Di chuyen menu";
	gotoXY(34, 24);
	cout << "2) Spacebar: Chon menu";


	gotoXY(34, 28);
	cout << "* Phim Nong";
	gotoXY(34, 30);
	cout << "- F1: Chuc nang chon du lieu trong bang";
	gotoXY(34, 32);
	cout << "- F2: Chuc nang chinh sua du lieu";
	gotoXY(34, 34);
	cout << "- F3: Chuc nang tim kiem";
	gotoXY(34, 36);
	cout << "- Ins: Chuc nang them du lieu";
	gotoXY(34, 38);
	cout << "- Del: Chuc nang xoa du lieu";
	gotoXY(34, 40);
	cout << "- Phim mui ten: Tren|Duoi|Trai|Phai";

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			return;
		}
		Sleep(150);
	}
}