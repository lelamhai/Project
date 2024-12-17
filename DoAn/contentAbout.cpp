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
	setColorText(ColorCode_Green);
	cout << "Gioi Thieu";
	setColorText(ColorCode_White);
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

	string tutorialMenu[] = {
		"* Huong Dan Su Dung Menu",
		"- PGUP|PGDN: Di chuyen menu",
		"- Tab: Chon menu"
	};

	string hotKey[] = {
		"* Phim Nong",
		"- F1: Chuc nang chon du lieu trong bang",
		"- F2: Chuc nang chinh sua du lieu",
		"- F3: Chuc nang tim kiem",
		"- F12: Xem huong dan",
		"- Ins: Chuc nang them du lieu",
		"- Del: Chuc nang xoa du lieu",
		"- ESC: Tro ve trang truoc",
		"- Phim mui ten: Tren|Duoi|Trai|Phai"
	};

	int posYMenu = 20;
	for (int i = 0; i < 3; i++)
	{
		gotoXY(34, posYMenu + i * 2);
		setColorText(ColorCode_White);
		if (i == 0)
		{
			setColorText(ColorCode_Green);
		}
		cout << tutorialMenu[i];
	}
	

	int posYKey = 27;
	for (int i = 0; i < 9; i++)
	{
		gotoXY(34, posYKey + i * 2);
		setColorText(ColorCode_White);
		if (i == 0)
		{
			setColorText(ColorCode_Green);
		}
		cout << hotKey[i];
	}
	
	while (true)
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				return;
			}
		}
		Sleep(100);
	}
}