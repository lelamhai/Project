#include "TemplateContent.h"

TemplateContent::TemplateContent()
{
	templateHeader();
	templateSidebar();
    menu();
	templateFooter();
}

TemplateContent::~TemplateContent()
{

}

void TemplateContent::main()
{
   
	_getch();
}

void TemplateContent::menu()
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