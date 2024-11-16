#include "Content.h"
Content::Content()
{
}

Content::~Content()
{
}
void Content::cleanContent()
{
	string blankFill;
	blankFill.resize(WIDTH_CONTENT, ' ');
	for (int i = 0; i < HEIGHT_CONTENT; i++)
	{
		gotoXY(34, 9 + i);
		cout << blankFill;
	}
}