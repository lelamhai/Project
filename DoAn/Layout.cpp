#include "Layout.h"

int Layout::choice = 0;

Layout::Layout()
{
	layoutHeader();
	layoutSidebar();
	layoutFooter();
}

Layout::~Layout()
{
}

void Layout::setRunContent(int content)
{
    //choice = content;
}

void Layout::main()
{
    Singleton::getInstance()->role = "GV";

    DWORD ID = 0;
    HANDLE hThread = CreateThread(NULL, 0, threadContent, this, 0, &ID);

    vector<string> menu;
    if (Singleton::getInstance()->role != "GV")
    {
        menu = {
           "Gioi Thieu",
           "Thi",
           "Dang Xuat",
           "Thoat"
        };
    }
    else {
        menu = {
            "Gioi Thieu",
            "Lop",
            "Sinh Vien",
            "Mon Hoc",
            "Thi",
            "Dang Xuat",
            "Thoat"
        };
    }
    int posY = 10;
    int active = 0;
    int hover = 0;
    int lastHover = -1;
    SuspendThread(hThread);
    while (true)
    {
        if (GetAsyncKeyState(VK_PRIOR) & 0x0001)
        {
            showCur(0);
            hover -= 1;
        }

        if (GetAsyncKeyState(VK_NEXT) & 0x0001)
        {
            showCur(0);
            hover += 1;
        }

        if (GetAsyncKeyState(VK_TAB) & 0x0001 && active != hover)
        {
            choice = hover;
            SuspendThread(hThread);
            lastHover = -1;
        }

        if (lastHover != hover)
        {
            for (int i = 0; i < menu.size(); i++)
            {
                setColorText(ColorCode_DarkWhite);
                if (active == i)
                {
                    setColorText(ColorCode_Green);
                }
                if (hover == i && hover != active)
                {
                    setColorText(ColorCode_Blue);
                }
                gotoXY(8, posY + i * 3);
                cout << menu[i];
            }
            lastHover = hover;
            ResumeThread(hThread);
        }
    }
}

DWORD WINAPI Layout::threadContent(LPVOID lpParam) 
{
    int i = 0;
    while (true)
    {
        if (choice == 0)
        {
            showCur(0);
            cleanContent();
            ContentAbout* a = new ContentAbout();
            a->displayContent();
            delete a;
        }

        if (choice == 1)
        {
            showCur(0);
            cleanContent();
            ContentClassroom* c = new ContentClassroom();
            c->displayContent();
            delete c;
        }

        if (choice == 2)
        {
            showCur(0);
            cleanContent();
            ContentStudent* s = new ContentStudent();
            s->displayContent();
            delete s;
        }

        if (choice == 3)
        {
            showCur(0);
            cleanContent();
            ContentSubject* s = new ContentSubject();
            s->displayContent();
            delete s;
        }

        if (choice == 4)
        {
            showCur(0);
            cleanContent();
            ContentExam* e = new ContentExam();
            e->displayContent();
            delete e;
        }

        /*gotoXY(0,i);
        cout << i;
        i++;
        Sleep(1500);*/
    }
    return 0;
}