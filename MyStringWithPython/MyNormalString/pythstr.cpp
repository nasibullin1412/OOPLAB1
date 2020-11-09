#include "pythstr.h"


void PythString::__setitem__(unsigned int i, char symbol)
{
	if (i <= this->Length() && i >= 0)
		this->CStr()[i] = symbol;
}

char PythString::__getitem__(unsigned int i)
{
	char error = '\0';
	if (i > this->Length() || i < 0)
	{
		return error;
	}
	char* temp = this->CStr();
	return temp[i];
}

const char* PythString::__str__()
{
	return this->CStr();
}