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
    choice = content;
}

void Layout::main()
{
    DWORD ID = 0;
    hThread = CreateThread(NULL, 0, templateContent, this, 0, &ID);
    templateMenu();

    if (hThread != NULL) {
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
    }
}

void Layout::templateMenu()
{
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
            "Mon Hoc",
            "Thi",
            "Xem Diem",
            "Dang Xuat",
            "Thoat"
        };
    }

    int posY = 10;
    int active = choice;
    int hover = choice;
    int lastHover = -1;
    SuspendThread(hThread);
    while (true)
    {
        if (Singleton::getInstance()->isExecute)
        {
            continue;
        }

        if (GetAsyncKeyState(VK_PRIOR) & 0x0001)
        {
            showCur(0);
            if (hover > 0)
            {
                hover -= 1;
            }

            Singleton::getInstance()->moveMenu -= 1;
        }

        if (GetAsyncKeyState(VK_NEXT) & 0x0001)
        {
            showCur(0);
            if (hover < menu.size() - 1)
            {
                hover += 1;
            }

            Singleton::getInstance()->moveMenu += 1;
        }

        if (GetAsyncKeyState(VK_TAB) & 0x0001 && active != hover)
        {
            int count = menu.size();
            if (hover == count - 2)
            {
                choice = QUIT;
                Sleep(50);
                return;
            }

            if (hover == count - 1)
            {
                choice = EXIT;
                Sleep(50);
                return;
            }

            active = hover;
            choice = hover;
            lastHover = -1;
            SuspendThread(hThread);
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

DWORD WINAPI Layout::templateContent(LPVOID lpParam) 
{
    while (true)
    {
        if (Singleton::getInstance()->role != "GV")
        {
            if (choice == 0)
            {
                showCur(0);
                cleanContent();
                ContentAbout* a = new ContentAbout();
                a->displayContent();
                delete a;
                Singleton::getInstance()->moveMenu = 0;
            }

            if (choice == 1)
            {
                showCur(0);
                cleanContent();
                ContentExam* e = new ContentExam();
                e->displayContent();
                delete e;
                Singleton::getInstance()->moveMenu = 0;
            }
        }
        else {
            if (choice == ABOUT)
            {
                showCur(0);
                cleanContent();
                ContentAbout* a = new ContentAbout();
                a->displayContent();
                delete a;
                Singleton::getInstance()->moveMenu = 0;
            }

            if (choice == CLASSROOM)
            {
                showCur(0);
                cleanContent();
                ContentClassroom* c = new ContentClassroom();
                c->displayContent();
                delete c;
                Singleton::getInstance()->moveMenu = 0;
            }

            if (choice == SUBJECT)
            {
                showCur(0);
                cleanContent();
                ContentSubject* s = new ContentSubject();
                s->displayContent();
                delete s;
                Singleton::getInstance()->moveMenu = 0;
            }

            if (choice == EXAM)
            {
                showCur(0);
                cleanContent();
                ContentExam* e = new ContentExam();
                e->displayContent();
                delete e;
                Singleton::getInstance()->moveMenu = 0;
            }

            if (choice == FILTERPOINT)
            {
                showCur(0);
                cleanContent();
                ContentFilterPoint* p = new ContentFilterPoint();
                p->displayContent();
                delete p;
                Singleton::getInstance()->moveMenu = 0;
            }
        }

        if (choice == 5)
        {
            showCur(0);
            cleanContent();
            Singleton::getInstance()->moveMenu = 0;
            return 0;
        }

        if (choice == -1)
        {
            showCur(0);
            clrscr();
            gotoXY(0,0);
            setColorText(ColorCode_DarkWhite);
            exit(0);
        }
    }
    return 0;
}