#ifndef _MYSTRINGTIER1_H_
#define _MYSTRINGTIER1_H_
#pragma once
#include "mystring.h"

class MyStringTier1 : public MyString
{
public:
	MyStringTier1() : MyString(){};
	MyStringTier1(const MyString& string) : MyString(string) {};
	MyStringTier1(const MyStringTier1& string) : MyString(string) {};
	MyStringTier1(const char* const string) : MyString(string) { };
	MyStringTier1(const std::string& std_string) : MyString(std_string) { };
	MyStringTier1(const size_t count, const char symbol) : MyString(count, symbol) {};
	MyStringTier1(const char* const cchar_array, const size_t count) : MyString(cchar_array, count) { };
	MyStringTier1(const int value);
	MyStringTier1(const float value);
	MyStringTier1(MyStringTier1 &&str);


	using MyString::operator[];
	using MyString::operator=;
	using MyString::operator+;
	using MyString::operator<;
	using MyString::operator>;
	using MyString::operator<=;
	using MyString::operator>=;
	using MyString::operator==;
	using MyString::operator!=;
	using MyString::operator+=;
	MyStringTier1& operator=(MyString &&string);

	int FindAhoCorasick(vector <MyStringTier1> &keywords, int k);


private:
	void FromIntToChar(const int value, const unsigned int count, const unsigned int index);
	int BuildMatchingMachine(vector<MyStringTier1>& arr, int k, int g[MyName::cMaxS][MyName::cMaxC], int out[], int f[] /*int *out, int* f*/);
	int findNextState(int currentState, char nextInput, int g[MyName::cMaxS][MyName::cMaxC], int f[]);
	void searchWords(vector <MyStringTier1> &arr, int k, int g[MyName::cMaxS][MyName::cMaxC], int out[], int f[] /*int *out, int* f*/);
	
};



#endif