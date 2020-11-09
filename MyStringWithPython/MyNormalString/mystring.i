/* File : example.i */
%module mystring
#pragma SWIG nowarn=SWIGWARN_IGNORE_OPERATOR_EQ
%{
#include "mystring.h"
%}

%extend MyString
{
char *__str__()
{
	return self->CStr();
}
}
%include "mystring.h"