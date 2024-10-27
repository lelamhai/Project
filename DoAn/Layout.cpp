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
    choice = 0;

    thread t1(&Layout::templateMenu, this);
    Sleep(200);
    thread t2(&Layout::templateConent, this);

    t1.join();
    t2.join();
}

void Layout::templateMenu()
{
    char menu[5][50] = { "Gioi Thieu", "Lop", "Sinh Vien", "Mon Hoc", "Cau Hoi" };
    int hover = 0;
    int active = 0;
    int posY = 10;
    
    while (true)
    {
        for (int i = 0; i < 5; i++)
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

        int key = _getch();
        int input = keyArrow(key);
        switch (input)
        {
        case UP:
            hover -= 1;
            break;
        case DOWN:
            hover += 1;
            break;
        default:
            break;
        }

        if (ENTER == key && active != hover)
        {
            active = hover;
            choice = hover;
        }

        Sleep(100);
    }
}

void Layout::templateConent()
{
    int lastChoice = -1;
    while (true)
    {
        if (choice == lastChoice)
        {
            continue;
        }

        if (choice == ABOUT)
        {
            showCur(0);
            cleanContent();
            About* a = new About();
            a->displayContent();
            delete a;
        }

        if (choice == STUDENT)
        {
            showCur(0);
            cleanContent();
            Student* s = new Student();
            s->displayContent();
            delete s;
        }

        if (choice == CLASSROOM)
        {
            showCur(0);
            cleanContent();
            Classroom* c = new Classroom();
            c->displayContent();
            delete c;
        }

        if (choice == SUBJECT)
        {
            showCur(0);
            cleanContent();
            Subject* s = new Subject();
            s->displayContent();
            delete s;
        }

        if (choice == QUESTION)
        {
            showCur(0);
            cleanContent();
            Question* q = new Question();
            q->displayContent();
            delete q;
        }

        lastChoice = choice;
        Sleep(200);
    }
}

void Layout::cleanContent()
{
    string blankFill;
    blankFill.resize(WIDTH_CONTENT, ' ');
    for (int i = 0; i < HEIGHT_CONTENT; i++)
    {
        gotoXY(34, 10 + i);
        cout << blankFill;
    }
}