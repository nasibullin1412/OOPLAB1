#ifndef _PYTHSTR_H_
#define _PYTHSTR_H_

#pragma once
#include "mystring.h"


class PythString : public MyString
{
public:



	PythString() {};
	PythString(const PythString& string) : MyString(string) {};
	PythString(const char* const string) : MyString(string) { };
	PythString(const std::string& std_string) : MyString(std_string) { };
	PythString(const size_t count, const char symbol) : MyString(count, symbol) {};
	PythString(const char* const cchar_array, const size_t count) : MyString(cchar_array, count) { };

	using MyString::operator=;
	using MyString::operator+;
	using MyString::operator<;
	using MyString::operator>;
	using MyString::operator<=;
	using MyString::operator>=;
	using MyString::operator==;
	using MyString::operator!=;
	using MyString::operator+=;


	using MyString::AppEnd;
	using MyString::Capacity;
	using MyString::Clear;
	using MyString::CStr;
	using MyString::Data;
	using MyString::Empty;
	using MyString::Erase;
	using MyString::Find;
	using MyString::Insert;
	using MyString::Length;
	using MyString::Replace;
	using MyString::ShrinkToFit;
	using MyString::Size;
	using MyString::Substr;
	~PythString() {};

	//for Python
	const char* __str__();
	void __setitem__(unsigned int i, char symbol);
	char __getitem__(unsigned int i);
};


#endif // _MYSTRINGINPYTHON_H_