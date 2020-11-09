#include "mystring.h"
#include "mystringtier1.h"
void test()
{
	std::string str = "lol";
	str.~basic_string();
	MyString third = "tt";
	third.Insert(3, "es", 2);
	char *temp = third.CStr();
	third[0] = 'a';

	return;
}


void tier_test()
{
	MyStringTier1 second = 1234;
	MyStringTier1 third = "1234";
	if (second == third)
	{
		cout << "Work1" << endl;
	}
	MyStringTier1 sec = 0;
	char *temp = nullptr;
	if (sec[0] == '\0')
	{
		cout << "Woprk2" << endl;
	}


	MyStringTier1 th = (float)12.345;
	temp = th.CStr();
	if (th[1] == '2' && th[2] == '.')
	{
		cout << "Woprk3" << endl;
	}
	MyStringTier1 lolik = "hello";
	MyStringTier1 next = "hello";

	//CheckFind();
	vector<MyStringTier1> keywords;
	keywords.push_back("er");
	keywords.push_back("lool");
	keywords.push_back("hl");
	//char teststring[] = ;
	MyStringTier1 first = "aisers";
	int k = 3;
	first.FindAhoCorasick(keywords, k);

}

int main()
{
	test();
	tier_test();


char temp[2] = { '\0' };
temp[0] = 'l';
MyString first = "string";
first.Replace(0, 1, temp);
vector <MyString> v;
v.push_back(MyString("string"));
float value = -123456.566;
//MyString test(value);
first.~MyString();
//test.~MyString();
//first.MyString(-1234567);
MyString second = first;
char *sec = nullptr;

MyString third = "mystringcheck";
MyString fourth = sec;
MyString fifth = third;
fifth = "----";
fifth = sec;
std::string string = "@@@@@";
first = string;

first.AppEnd(sec);
first.AppEnd("+++");
second.AppEnd("normal");
first += second;
second = sec;
first += second;
first = "+llll";
third = first + second;
third = second + first;
second = first + first;

fifth = "+++---";
char symbol = fifth[1];
symbol = fifth[7];

MyString sixth;
sixth = string;
fifth = sec;
fifth += "AAA";
fifth += string;
fifth += sec;

sixth = fifth + "BBB";
sixth = sixth + string;
sixth = sixth + sec;
third = "karamba";
fifth = "karamba";
// logic operators check
if (third < fifth)
{
	cout << "ok <" << endl;
}
if (third <= fifth)
{
	cout << "ok <=" << endl;
}
if (third > fifth)
{
	cout << "ok >" << endl;
}
if (third >= fifth)
{
	cout << "ok >=" << endl;
}
if (third == fifth)
{
	cout << "ok ==" << endl;
}
if (third != fifth)
{
	cout << "ok !=" << endl;
}
cout << "Enter string: ";
cin >> first;
cout << first << endl;
first.Insert(1, "++++");
second = sec;
second.Insert(5, "error");
second.Insert(0, "----");
second.Insert(7, "error");
second.Insert(3, 6, '+');
second.Insert(4, "stringchar", 6);
second.Insert(12, "stringchar", 10);
second.Insert(22, "###", 4);
second = sec;
second.Insert(0, string);
second.Insert(5, string);
second.Insert(10, string, 2);
second.Insert(12, string, 5);
string = "###";
second.Insert(10, string, 4);
second.Erase(10, 3);
second.ShrinkToFit();

second.AppEnd("--+++", 2, 3);
second.AppEnd("@@---", 2, 6);
second = sec;
second.AppEnd(7, 'B');
second.AppEnd(string);
second.AppEnd(string, 2, 8);
/*char *s = second.Substr(2);
second.~MyString();
cout << s << endl;
string = "char";
first = "mystringcharandstd";
cout << "Find result: " << first.Find("rand") << endl;
cout << "Find result: " << first.Find("stdl") << endl;
cout << "Find result:" << first.Find(string) << endl;
cout << "Find result:" << first.Find(sec) << endl;
cout << "Find result:" << first.Find("ing", 7) << endl;
cout << "Find result:" << first.Find("ing", 4) << endl;
cout << "Find result:" << first.Find(string, 4) << endl;
cout << "Find result:" << first.Find(string, 9) << endl;
first = "hello amazing world";
first.Replace(6, 7, "wonderful");
first.Replace(6, 9, string);*/
return 0;
}