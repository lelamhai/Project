#include "ToastMessage.h"

ToastMessage::ToastMessage()
{
}

ToastMessage::~ToastMessage()
{
}

void ToastMessage::open()
{
	content();
	Sleep(TIME_DELAY);
}

void ToastMessage::close()
{
	clean();
}