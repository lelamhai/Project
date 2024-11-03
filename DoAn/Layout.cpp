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
    isRun = true;

    thread t1(&Layout::templateMenu, this);
    Sleep(200);
    thread t2(&Layout::templateContent, this);

    t1.join();
    t2.join();
}

void Layout::templateMenu()
{
    string menu[] = {
        "Gioi Thieu",
        "Lop Hoc",
        "Sinh Vien",
        "Mon Hoc",
        "Cau Hoi",
        "Thi",
        "Dang Xuat",
        "Thoat"
    };

    int posY = 10;
    int active = choice;
    int hover = choice;
    int lastHover = -1;

    showCur(0);
    while (isRun)
    {
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            hover -= 1;
            Sleep(50);
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            hover += 1;
            Sleep(50);
        }
        
        if (lastHover != hover)
        {
            for (int i = 0; i < 8; i++)
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
        }
        lastHover = hover;

        if (GetAsyncKeyState(VK_RETURN) & 0x8000 && active != hover)
        {
            int count = sizeof(menu) / sizeof(menu[0]);
            if (hover == count - 2)
            {
                isRun = false;
                return;
            }

            if (hover == count-1)
            {
                clrscr();
                gotoXY(0, 0);
                setColorText(ColorCode_DarkWhite);
                exit(0);
            }

            active = hover;
            choice = hover;
            lastHover = -1;
        }

        Sleep(100);
    }
}

void Layout::templateContent()
{
    int lastChoice = -1;
    while (isRun)
    {
        //if (choice == lastChoice)
        //{
        //    continue;
        //}

        //if (choice == ABOUT)
        //{
        //    showCur(0);
        //    cleanContent();
        //    About* a = new About();
        //    a->displayContent();
        //    delete a;
        //}
        //if (choice == STUDENT)
        //{
        //    showCur(0);
        //    cleanContent();
        //  /*  Student* s = new Student();
        //    s->displayContent();
        //    delete s;*/
        //}
        //if (choice == CLASSROOM)
        //{
        //    showCur(0);
        //    cleanContent();
        //    Classroom* c = new Classroom();
        //    c->displayContent();
        //    delete c;
        //}
        //if (choice == SUBJECT)
        //{
        //    showCur(0);
        //    cleanContent();
        //    Subject* s = new Subject();
        //    s->displayContent();
        //    delete s;
        //}
        //if (choice == QUESTION)
        //{
        //    showCur(0);
        //    cleanContent();
        //    Question* q = new Question();
        //    q->displayContent();
        //    delete q;
        //}

        //if (choice == EXAM)
        //{
        //    showCur(0);
        //    cleanContent();
        //    Exam* e = new Exam();
        //    e->displayContent();
        //    delete e;
        //}

        //lastChoice = choice;
        //Sleep(200);
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