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

void Layout::setRunContent(int content)
{
    choice = content;
}

void Layout::main()
{
    thread t1(&Layout::templateMenu, this);
    thread t2(&Layout::templateContent, this);

    t1.join();
    t2.join();
}

void Layout::templateMenu()
{
    vector<string> menu;

    if (Singleton::getInstance()->role != "GV")
    {
        menu = {
           "Gioi Thieu",
           "Mon Hoc",
           "Thi",
           "Dang Xuat",
           "Thoat"
        };
    }
    else {
        menu = {
            "Gioi Thieu",
            "Lop Hoc",
            "Sinh Vien",
            "Mon Hoc",
            "Cau Hoi",
            "Thi",
            "Dang Xuat",
            "Thoat"
        };
    }
    
    int posY = 10;
    int active = choice;
    int hover = choice;
    int lastHover = -1;

    while (true)
    {
        if (GetAsyncKeyState(VK_PRIOR) & 0x0001)
        {
            showCur(0);
            hover -= 1;
            Sleep(50);
            continue;
        }

        if (GetAsyncKeyState(VK_NEXT) & 0x0001)
        {
            showCur(0);
            hover += 1;
            Sleep(50);
            continue;
        }
        
        if (GetAsyncKeyState(VK_RETURN) & 0x0001 && active != hover)
        {
            int count = menu.size();
            if (hover == count - 2)
            {
                choice = hover;
                Sleep(50);
                return;
            }

            if (hover == count - 1)
            {
                clrscr();
                gotoXY(0, 0);
                setColorText(ColorCode_DarkWhite);
                exit(0);
            }

            isLoadContent = true;
            active = hover;
            choice = hover;
            lastHover = -1;
            Sleep(50);
            continue;
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
        }
    }
}

void Layout::templateContent()
{
    while (true)
    {
        // Flag reload content
        if (isLoadContent)
        {
            Sleep(200);
            isLoadContent = false;
            continue;
        }

        if (Singleton::getInstance()->role != "GV")
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
                ContentSubject* s = new ContentSubject();
                s->displayContent();
                delete s;
            }
            if (choice == 2)
            {
                showCur(0);
                cleanContent();
                ContentExam* e = new ContentExam();
                e->displayContent();
                delete e;
            }

            if (choice == 3)
            {
                return;
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
            }
            if (choice == STUDENT)
            {
                showCur(0);
                cleanContent();
                ContentStudent* s = new ContentStudent();
                s->displayContent();
                delete s;
            }
            if (choice == CLASSROOM)
            {
                showCur(0);
                cleanContent();
                ContentClassroom* c = new ContentClassroom();
                c->displayContent();
                delete c;
            }
            if (choice == SUBJECT)
            {
                showCur(0);
                cleanContent();
                ContentSubject* s = new ContentSubject();
                s->displayContent();
                delete s;
            }
            if (choice == QUESTION)
            {
                showCur(0);
                cleanContent();
                ContentQuestion* q = new ContentQuestion();
                q->displayContent();
                delete q;
            }
            if (choice == EXAM)
            {
                showCur(0);
                cleanContent();
                ContentExam* e = new ContentExam();
                e->displayContent();
                delete e;
            }
            if (choice == EXIT)
            {
                return;
            }
        }
    }
}

void Layout::cleanContent()
{
    string blankFill;
    blankFill.resize(WIDTH_CONTENT, ' ');
    for (int i = 0; i < HEIGHT_CONTENT; i++)
    {
        gotoXY(34, 9 + i);
        cout << blankFill;
    }
}