#include "Text.h"

Text::Text()
{
}

Text::~Text()
{
}

int Text::getLenString()
{
	return content.length();
}

void Text::setContent(string newContent)
{ 
	content = newContent;
}


void Text::display()
{
	cout << content;
}