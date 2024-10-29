#include "Text.h"

Text::Text()
{
}

Text::~Text()
{
}

void Text::setContent(string newContent)
{ 
	content = newContent;
}


void Text::display()
{
	cout << content;
}