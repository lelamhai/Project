#include "Layout.h"

Layout::Layout()
{
	layoutHeader();
	layoutSidebar();
	layoutFooter();
}

Layout::~Layout()
{
}

void Layout::main()
{
    choice = 1;
    templateMenu();
    templateConent();
}

void Layout::templateConent()
{
    while (true)
    {
        if (choice == ABOUT)
        {
            About* a = new About();
            a->displayContent();
            delete a;
        }

        if (choice == STUDENT)
        {
            Student* s = new Student();
            s->displayContent();
            delete s;
        }
    }
}

void Layout::templateMenu()
{
    char menu[8][50] = { "Gioi Thieu", "Lop Hoc", "Sinh Vien", "Mom Hoc", "Cau Hoi", "Thi", "Dang Xuat", "Thoat" };

    int posY = 11;
    for (int i = 0; i < 8; i++)
    {
        gotoXY(8, posY);
        cout << menu[i];
        posY += 3;
    }
}