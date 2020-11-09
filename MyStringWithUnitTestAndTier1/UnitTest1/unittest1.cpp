#include "pch.h"
#include "CppUnitTest.h"
#include "../StringUnitTests/mystring.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(DefaultConstract)
		{
			MyString first;
			Assert::IsTrue(first.CStr()[0] == 0, L"Assert 1");
			Assert::IsTrue(first.Capacity() == 1, L"Assert 2");
			// TODO: Your test code here
		}
		TEST_METHOD(CharStrConstract)
		{
			MyString first = "char";
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 'c');
			Assert::IsTrue(temp[1] == 'h');
			Assert::IsTrue(temp[2] == 'a');
			Assert::IsTrue(temp[3] == 'r');
			Assert::IsTrue(temp[4] == '\0');
			// TODO: Your test code here
		}
		TEST_METHOD(CharStrConstract2)
		{
			MyString first = "";
			char *temp = first.CStr();
			Assert::IsTrue(first.CStr()[0] == '\0', L"Assert 1");
			// TODO: Your test code here
		}
		TEST_METHOD(StdConstract)
		{
			std::string string = "test";
			MyString first = string;
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't');
			Assert::IsTrue(temp[1] == 'e');
			Assert::IsTrue(temp[2] == 's');
			Assert::IsTrue(temp[3] == 't');
			Assert::IsTrue(temp[4] == '\0');
			// TODO: Your test code here
		}
		TEST_METHOD(StdConstract2)
		{

			std::string string = "";
			MyString first = string;
			char *temp = first.CStr();
			Assert::IsNull(first.CStr(), L"Assert 1");
			// TODO: Your test code here
		}
		TEST_METHOD(CharArrayConstract)
		{
			MyString second = { 't', 'e', 's', 't' };
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == 't');
			Assert::IsTrue(temp[1] == 'e');
			Assert::IsTrue(temp[2] == 's');
			Assert::IsTrue(temp[3] == 't');
			Assert::IsTrue(temp[4] == '\0');
			// TODO: Your test code here
		}
		TEST_METHOD(CharStringCount)
		{
			MyString second = { "teststring", 4 };
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == 't');
			Assert::IsTrue(temp[1] == 'e');
			Assert::IsTrue(temp[2] == 's');
			Assert::IsTrue(temp[3] == 't');
			Assert::IsTrue(temp[4] == '\0');
			// TODO: Your test code here
		}
		TEST_METHOD(CharStringCount2)
		{
			MyString second = { "test", 5 };
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == 't');
			Assert::IsTrue(temp[1] == 'e');
			Assert::IsTrue(temp[2] == 's');
			Assert::IsTrue(temp[3] == 't');
			Assert::IsTrue(temp[4] == '\0');
			// TODO: Your test code here
		}
		TEST_METHOD(CharSymbolCount)
		{
			MyString second(5, 'a');
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == 'a', L"END");
			Assert::IsTrue(temp[1] == 'a');
			Assert::IsTrue(temp[2] == 'a');
			Assert::IsTrue(temp[3] == 'a');
			Assert::IsTrue(temp[4] == 'a');
			Assert::IsTrue(temp[5] == '\0', L"END");
			// TODO: Your test code here
		}
		TEST_METHOD(CharSymbolCount2)
		{
			MyString second('a', 0);
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == 0);
			// TODO: Your test code here
		}
		/*TEST_METHOD(IntValueConstract)
		{
			MyString second = 1234;
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == '1');
			Assert::IsTrue(temp[1] == '2');
			Assert::IsTrue(temp[2] == '3');
			Assert::IsTrue(temp[3] == '4');
			Assert::IsTrue(temp[4] == '\0');
			// TODO: Your test code here
		}*/
		/*TEST_METHOD(IntValueConstract2)
		{
			MyString second = 0;
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == '0');
			Assert::IsTrue(temp[1] == '\0');
			// TODO: Your test code here
		}
		TEST_METHOD(FloatValueConstract)
		{
			MyString second = (float)12.345;
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == '1');
			Assert::IsTrue(temp[1] == '2');
			Assert::IsTrue(temp[2] == '.');
			Assert::IsTrue(temp[6] == '\0');
		}
		TEST_METHOD(FloatValueConstract2)
		{
			MyString second = (float)0.0;
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == '0');
			Assert::IsTrue(temp[1] == '.');
			Assert::IsTrue(temp[2] == '0');
			Assert::IsTrue(temp[3] == '\0', L"End");
		}*/
		TEST_METHOD(Length)
		{
			MyString second = "1234567890";
			Assert::IsTrue(second.Length() == 10, L"Assert 1");
			second = "";
			Assert::IsTrue(second.Length() == 0, L"Assert 2");
			const MyString third = "1234567890";
			Assert::IsTrue(third.Length() == 10, L"Assert 3");
		}
		TEST_METHOD(Empty)
		{
			MyString second = "1234567890";
			Assert::IsTrue(!second.Empty(), L"Assert 1");
			second = "";
			Assert::IsTrue(second.Empty(), L"Assert 2");
		}
		TEST_METHOD(Clear)
		{
			MyString second = "1234567890";
			second.Clear();
			//Assert::IsTrue(second.CStr()[0] == '\0', L"Assert 1");
			second.Clear();
			//Assert::IsTrue(second.CStr()[0] == '\0', L"Assert 2");
		}
		TEST_METHOD(CStr)
		{
			MyString second = "test";
			char *temp = second.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assrt1");
			Assert::IsTrue(temp[1] == 'e', L"Assrt2");
			Assert::IsTrue(temp[2] == 's', L"Assrt3");
			Assert::IsTrue(temp[3] == 't', L"Assrt4");
			Assert::IsTrue(temp[4] == '\0', L"Assrt5");
			second.~MyString();
			Assert::IsFalse(temp[0]=='t',  L"Assert7");
			MyString first = "";
			char *test = first.CStr();
			Assert::IsTrue(test[0] == '\0', L"Assert8");
		}
		TEST_METHOD(Data)
		{
			MyString second = "test";
			char *temp = second.Data();
			Assert::IsTrue(temp[0] == 't', L"Assrt1");
			Assert::IsTrue(temp[1] == 'e', L"Assrt2");
			Assert::IsTrue(temp[2] == 's', L"Assrt3");
			Assert::IsTrue(temp[3] == 't', L"Assrt4");
			Assert::IsTrue(temp[4] == '\0', L"Assrt5");
			second.~MyString();
			Assert::IsFalse(temp[0] == 't', L"Assert6");
			MyString first = "";
			char *test = first.CStr();
			Assert::IsTrue(test[0] == '\0', L"Assert7");
		}
		TEST_METHOD(Size)
		{
			MyString second = "1234567890";
			Assert::IsTrue(second.Size() == 10, L"Assert 1");
			second = "";
			Assert::IsTrue(second.Size() == 0, L"Assert 2");
			const MyString third = "1234567890";
			Assert::IsTrue(third.Size() == 10, L"Assert 3");
		}
		TEST_METHOD(Capacity)
		{
			MyString first = "123456";
			unsigned int cap_before = first.Capacity();
			first = "00";
			unsigned int cap_after = first.Capacity();
			Assert::AreEqual(cap_before, cap_after, L"Assert1");

			cap_before = first.Capacity();
			std::string str = "12";
			first = str;
			cap_after = first.Capacity();
			Assert::AreEqual(cap_before, cap_after, L"Assert2");

			first = "123456789";
			unsigned int cap_value = first.Capacity();
			Assert::IsTrue(10 == cap_value, L"Assert3");

			const MyString third = "1234567890";
			Assert::IsTrue(third.Capacity() == 11, L"Assert 4");
		}
		TEST_METHOD(ShrinkToFit)
		{
			MyString first = "123456";
			first = "00";
			unsigned int cap_after = first.Capacity();
			Assert::AreNotEqual(first.Length(), cap_after - 1, L"Assert1");
			first.ShrinkToFit();
			cap_after = first.Capacity();
			Assert::AreEqual(first.Length(), cap_after - 1, L"Assert2");
		}
		TEST_METHOD(EqOperatorMyString)
		{
			MyString first = "check";
			MyString second = "check";
			Assert::IsTrue(first == second, L"Assert1");
			MyString third = "";
			MyString fourth = "";
			Assert::IsTrue(third == fourth, L"Assert2");
			MyString fifth = "checkin";
			MyString sixth = "checkif";
			Assert::IsFalse(fifth == sixth, L"Assert3");
			Assert::IsFalse(sixth == first, L"Assert4");
			Assert::IsFalse(third == first, L"Assert5");
			Assert::IsFalse(first == third, L"Assert6");
		}
		TEST_METHOD(NotEqOperatorMyString)
		{
			MyString first = "check";
			MyString second = "check";
			Assert::IsFalse(first != second, L"Assert1");
			MyString third = "";
			MyString fourth = "";
			Assert::IsFalse(third != fourth, L"Assert2");
			MyString fifth = "checkin";
			MyString sixth = "checkif";
			Assert::IsTrue(fifth != sixth, L"Assert3");
			Assert::IsTrue(sixth != first, L"Assert4");
			Assert::IsTrue(third != first, L"Assert5");
			Assert::IsTrue(first != third, L"Assert6");
		}
		TEST_METHOD(MoreOperatorMyString)
		{
			MyString first = "check";
			MyString second = "check";
			Assert::IsFalse(first > second, L"Assert1");
			MyString third = "";
			MyString fourth = "";
			Assert::IsFalse(third > fourth, L"Assert2");
			MyString fifth = "checkin";
			MyString sixth = "checkif";
			Assert::IsFalse(sixth > fifth, L"Assert3");
			Assert::IsTrue(fifth > sixth, L"Assert4");
			Assert::IsTrue(sixth > first, L"Assert5");
			Assert::IsTrue(first > third, L"Assert6");
			Assert::IsFalse(third > first, L"Assert7");
		}
		TEST_METHOD(LessEqOperatorMyString)
		{
			MyString first = "check";
			MyString second = "check";
			Assert::IsTrue(first <= second, L"Assert1");
			MyString third = "";
			MyString fourth = "";
			Assert::IsTrue(third <= fourth, L"Assert2");
			MyString fifth = "checkin";
			MyString sixth = "checkif";
			Assert::IsTrue(sixth <= fifth, L"Assert3");
			Assert::IsFalse(fifth <= sixth, L"Assert4");
			Assert::IsFalse(sixth <= first, L"Assert5");
			Assert::IsFalse(first <= third, L"Assert6");
			Assert::IsTrue(third <= first, L"Assert7");
		}
		TEST_METHOD(LessOperatorMyString)
		{
			MyString first = "check";
			MyString second = "check";
			Assert::IsFalse(first < second, L"Assert1");
			MyString third = "";
			MyString fourth = "";
			Assert::IsFalse(third < fourth, L"Assert2");
			MyString fifth = "checkin";
			MyString sixth = "checkif";
			Assert::IsTrue(sixth < fifth, L"Assert3");
			Assert::IsFalse(fifth < sixth, L"Assert4");
			Assert::IsFalse(sixth < first, L"Assert5");
			Assert::IsFalse(first < third, L"Assert6");
			Assert::IsTrue(third < first, L"Assert7");
		}
		TEST_METHOD(AssignementOperatorMyString)
		{
			MyString first;
			MyString second = "test";
			first = second;
			Assert::IsTrue(first == second, L"Assert1");


			MyString third;
			MyString fourth = "";
			third = fourth;
			Assert::IsTrue(third == fourth, L"Assert2");



			MyString fifth = "checkin";
			MyString sixth = "checkif";
			fifth = sixth;
			Assert::IsTrue(sixth == fifth, L"Assert3");

			fifth = second;
			Assert::IsTrue(fifth == second, L"Assert4");


			MyString seventh;
			seventh = "1234567890";
			MyString eight = "1234";
			seventh = eight;
			Assert::IsTrue(seventh.Capacity() == 11, L"Assert5");
			Assert::IsTrue(seventh == eight, L"Assert6");
		}
		TEST_METHOD(AssignementOperatorCharString)
		{
			MyString first;
			first = "test";
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			MyString third;
			third = "";
			Assert::IsTrue(third.CStr()[0] == '\0', L"Assert6");
			first = "";
			Assert::IsTrue(first.CStr()[0] == '\0', L"Assert7");

			MyString seventh;
			seventh = "1234567890";
			seventh = "1234";
			MyString eight = "1234";
			Assert::IsTrue(seventh.Capacity() == 11, L"Assert5");
			Assert::IsTrue(seventh == eight, L"Assert6");
		}
		TEST_METHOD(AssignementOperatorStdString)
		{
			MyString first;
			std::string str = "test";
			first = str;
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			MyString third;
			str = "";
			third = str;
			Assert::IsTrue(third.CStr()[0] == 0, L"Assert6");
			first = str;
			Assert::IsTrue(first.CStr()[0] == 0, L"Assert7");

			MyString seventh;
			seventh = "1234567890";
			MyString eight = "1234";
			std::string string = "1234";
			seventh = string;
			Assert::IsTrue(seventh.Capacity() == 11, L"Assert8");
			Assert::IsTrue(seventh == eight, L"Assert9");

		}
		TEST_METHOD(AssignementOperatorCharSymbol)
		{
			MyString first;
			first = 't';
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == '\0', L"Assert2");

			MyString third;
			third = '\0';
			Assert::IsTrue(third.CStr()[0] == '\0', L"Assert6");
			first = '\0';
			Assert::IsTrue(first.CStr()[0] == '\0', L"Assert7");

		}
		TEST_METHOD(OperatorPlusAssigMyString)
		{
			MyString first = "t";
			MyString second = "est";
			first += second;
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			second = "";
			first += second;
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third = "";
			third += first;
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 'e', L"Assert12");
			Assert::IsTrue(temp[2] == 's', L"Assert13");
			Assert::IsTrue(temp[3] == 't', L"Assert14");
			Assert::IsTrue(temp[4] == '\0', L"Assert15");

			MyString fourth;
			MyString fifth;
			fourth += fifth;
			temp = fourth.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert16");


			MyString test = "1234567890";
			test = "123";
			MyString right = "45";
			test += right;
			MyString checkTest = "12345";
			Assert::IsTrue(test.Capacity() == 11, L"Assert19");
			Assert::IsTrue(test == checkTest, L"Assert20");
		}
		TEST_METHOD(OperatorPlusAssigCharString)
		{
			MyString first = "t";
			first += "est";
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			first += "";
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third;
			third += "test";
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 'e', L"Assert12");
			Assert::IsTrue(temp[2] == 's', L"Assert13");
			Assert::IsTrue(temp[3] == 't', L"Assert14");
			Assert::IsTrue(temp[4] == '\0', L"Assert15");

			MyString fourth;
			fourth += nullptr;
			temp = fourth.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert16");

			MyString fifth = "qwertyuiop";
			fifth = "r";
			fifth += "l";
			Assert::IsTrue(fifth.Capacity() == 11, L"Assert17");
			MyString sixth = "rl";
			Assert::IsTrue(fifth == sixth, L"Assert18");


			MyString test = "1234567890";
			test = "123";
			test += "45";
			MyString checkTest = "12345";
			Assert::IsTrue(test.Capacity() == 11, L"Assert19");
			Assert::IsTrue(test == checkTest, L"Assert20");


		}
		TEST_METHOD(OperatorPlusAssigStdString)
		{
			MyString first = "t";
			std::string str = "est";
			first += str;
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			str = "";
			first += str;
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third;
			third += "test";
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 'e', L"Assert12");
			Assert::IsTrue(temp[2] == 's', L"Assert13");
			Assert::IsTrue(temp[3] == 't', L"Assert14");
			Assert::IsTrue(temp[4] == '\0', L"Assert15");

			MyString fourth;
			fourth += str;
			temp = fourth.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert16");
			MyString test = "1234567890";
			test = "123";
			std::string right = "45";
			test += right;
			MyString checkTest = "12345";
			Assert::IsTrue(test.Capacity() == 11, L"Assert19");
			Assert::IsTrue(test == checkTest, L"Assert20");
		}
		TEST_METHOD(OperatorPlusCharString)
		{
			MyString sum;
			MyString first = "t";
			MyString second = "est";
			sum = first + second;
			char *temp = sum.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			MyString third;
			first = sum;
			sum = first + third;
			temp = sum.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString fourth;
			sum = fourth + first;
			temp = sum.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 'e', L"Assert12");
			Assert::IsTrue(temp[2] == 's', L"Assert13");
			Assert::IsTrue(temp[3] == 't', L"Assert14");
			Assert::IsTrue(temp[4] == '\0', L"Assert15");

			MyString fifth;
			sum = fourth + fifth;
			temp = fourth.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert16");
		}
		TEST_METHOD(OperatorPlusMyString)
		{
			MyString first = "t";
			std::string str = "est";
			first += str;
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			str = "";
			first += str;
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third;
			third += "test";
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 'e', L"Assert12");
			Assert::IsTrue(temp[2] == 's', L"Assert13");
			Assert::IsTrue(temp[3] == 't', L"Assert14");
			Assert::IsTrue(temp[4] == '\0', L"Assert15");

			MyString fourth;
			fourth += str;
			temp = fourth.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert16");
		}
		TEST_METHOD(OperatorPlusStdString)
		{
			MyString first = "t";
			std::string str = "est";
			first += str;
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			str = "";
			first += str;
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third;
			third += "test";
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 'e', L"Assert12");
			Assert::IsTrue(temp[2] == 's', L"Assert13");
			Assert::IsTrue(temp[3] == 't', L"Assert14");
			Assert::IsTrue(temp[4] == '\0', L"Assert15");

			MyString fourth;
			fourth += str;
			temp = fourth.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert16");
		}
		TEST_METHOD(InsertIndexCountSymbol)
		{
			MyString first = "tt";
			first.Insert(1, 2, 'e');
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 'e', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");
			first = "tt";
			first.Insert(3, 2, 'e');
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 't', L"Assert7");
			Assert::IsTrue(temp[2] == '\0', L"Assert8");


			MyString second;
			second.Insert(1, 2, 'e');
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert9");
			second.Insert(0, 2, 'e');
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert10");
			Assert::IsTrue(temp[1] == 'e', L"Assert11");
			Assert::IsTrue(temp[2] == '\0', L"Assert12");
		}
		TEST_METHOD(InsertIndexCharString)
		{
			MyString first = "tt";
			char str[] = "es";
			first.Insert(1, str);
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");


			first = "tt";
			first.Insert(3, str);
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 't', L"Assert7");
			Assert::IsTrue(temp[2] == '\0', L"Assert8");


			MyString second;
			second.Insert(1, "es");
			temp = second.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert9");
			second.Insert(0, "es");
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert10");
			Assert::IsTrue(temp[1] == 's', L"Assert11");
			Assert::IsTrue(temp[2] == '\0', L"Assert12");


			MyString null;
			char *nstr = nullptr;
			null.Insert(0, nstr);
			temp = null.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert13");

			second.Insert(0, nstr);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert14");
			Assert::IsTrue(temp[1] == 's', L"Assert15");
			Assert::IsTrue(temp[2] == '\0', L"Assert16");

			MyString test = "1234567890";
			test = "12378";
			test.Insert(3, "456");
			MyString testsec = "12345678";
			Assert::IsTrue(test.Capacity() == 11, L"Assert17");
			Assert::IsTrue(test == testsec, L"Assert18");
		}
		TEST_METHOD(InsertIndexCountCharString)
		{
			MyString first = "tt";
			char str[] = "esaasf";
			first.Insert(1, str, 2);
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");


			first = "tt";
			first.Insert(1, "es", 3);
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third = "tt";
			third.Insert(3, "es", 2);
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 't', L"Assert12");
			Assert::IsTrue(temp[2] == '\0', L"Assert13");



			MyString second;
			second.Insert(1, "es", 3);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert14");
			second.Insert(0, "es", 2);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert15");
			Assert::IsTrue(temp[1] == 's', L"Assert16");
			Assert::IsTrue(temp[2] == '\0', L"Assert17");


			MyString null;
			char *nstr = nullptr;
			null.Insert(0, nstr, 1);
			temp = null.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert18");

			second.Insert(0, nstr, 0);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert19");
			Assert::IsTrue(temp[1] == 's', L"Assert20");
			Assert::IsTrue(temp[2] == '\0', L"Assert21");
		}
		TEST_METHOD(InsertIndexStdString)
		{
			MyString first = "tt";
			std::string str = "es";
			first.Insert(1, str);
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			first = "tt";
			first.Insert(3, str);
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 't', L"Assert7");
			Assert::IsTrue(temp[2] == '\0', L"Assert8");


			MyString second;
			second.Insert(1, str);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert9");
			second.Insert(0, str);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert10");
			Assert::IsTrue(temp[1] == 's', L"Assert11");
			Assert::IsTrue(temp[2] == '\0', L"Assert12");

			MyString null;
			std::string nstr = "";
			null.Insert(0, nstr);
			temp = null.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert13");

			second.Insert(0, nstr);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert10");
			Assert::IsTrue(temp[1] == 's', L"Assert11");
			Assert::IsTrue(temp[2] == '\0', L"Assert12");

		}

		TEST_METHOD(InsertIndexCountStdString)
		{
			MyString first = "tt";
			std::string str = "esaasf";
			first.Insert(1, str, 2);
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert1");
			Assert::IsTrue(temp[1] == 'e', L"Assert2");
			Assert::IsTrue(temp[2] == 's', L"Assert3");
			Assert::IsTrue(temp[3] == 't', L"Assert4");
			Assert::IsTrue(temp[4] == '\0', L"Assert5");

			str = "es";
			first = "tt";
			first.Insert(1, str, 3);
			temp = first.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert6");
			Assert::IsTrue(temp[1] == 'e', L"Assert7");
			Assert::IsTrue(temp[2] == 's', L"Assert8");
			Assert::IsTrue(temp[3] == 't', L"Assert9");
			Assert::IsTrue(temp[4] == '\0', L"Assert10");

			MyString third = "tt";
			third.Insert(3, str, 2);
			temp = third.CStr();
			Assert::IsTrue(temp[0] == 't', L"Assert11");
			Assert::IsTrue(temp[1] == 't', L"Assert12");
			Assert::IsTrue(temp[2] == '\0', L"Assert13");



			MyString second;
			second.Insert(1, str, 3);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert14");
			second.Insert(0, str, 2);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert15");
			Assert::IsTrue(temp[1] == 's', L"Assert16");
			Assert::IsTrue(temp[2] == '\0', L"Assert17");


			MyString null;
			str = "";
			null.Insert(0, str, 1);
			temp = null.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert18");

			second.Insert(0, str, 0);
			temp = second.CStr();
			Assert::IsTrue(temp[0] == 'e', L"Assert19");
			Assert::IsTrue(temp[1] == 's', L"Assert20");
			Assert::IsTrue(temp[2] == '\0', L"Assert21");
		}
		TEST_METHOD(Erase)
		{
			MyString first = "itischarstring";
			first.Erase(0, 11);
			char *temp = first.CStr();
			Assert::IsTrue(temp[0] == 'i', L"Assert1");
			Assert::IsTrue(temp[1] == 'n', L"Assert2");
			Assert::IsTrue(temp[2] == 'g', L"Assert3");

			first = "itischarstring";
			first.Erase(0, 14);
			temp = first.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert4");
			first = "itischarstring";
			MyString second = "itischarstring";
			first.Erase(14, 5);
			Assert::IsTrue(first == second, L"Assert5");
		}
		TEST_METHOD(AppEndCharStr)
		{
			MyString first = "it";
			first.AppEnd("ischar");
			MyString second = "itischar";
			Assert::IsTrue(first == second, L"Assert1");
			
			char *str = nullptr;
			first.AppEnd(str);
			Assert::IsTrue(first == second, L"Assert2");

			MyString third;
			third.AppEnd("itischar");
			Assert::IsTrue(third == second, L"Assert3");

			MyString fourth;
			fourth.AppEnd(str);
			char *temp = fourth.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert4");
		}
		TEST_METHOD(AppEndCountSymbol)
		{
			MyString first = "it";
			first.AppEnd(5, 's');
			MyString second = "itsssss";
			Assert::IsTrue(first == second, L"Assert1");


			MyString third;
			third.AppEnd(5, 's');
			second = "sssss";
			Assert::IsTrue(third == second, L"Assert2");

			MyString fourth;
			fourth.AppEnd(0, 's');
			char *temp = fourth.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert3");
		}
		TEST_METHOD(AppEndCharStringIndexCount)
		{
			MyString first = "it";
			first.AppEnd("bbischarhh", 2, 6);
			MyString second = "itischar";
			Assert::IsTrue(first == second, L"Assert1");

			char *str = nullptr;
			first.AppEnd(str, 0, 2);
			Assert::IsTrue(first == second, L"Assert2");
			first.AppEnd(str, 0, 0);
			Assert::IsTrue(first == second, L"Assert3");

			MyString third;
			third.AppEnd("hhyitischarll", 3, 8);
			Assert::IsTrue(third == second, L"Assert4");

			MyString fourth;
			fourth.AppEnd(str, 0, 9);
			char *temp = fourth.CStr();
			Assert::IsTrue(temp[0] == 0, L"Assert5");
		}
		TEST_METHOD(AppEndStdString)
		{
			std::string str = "ischar";
			MyString first = "it";
			first.AppEnd(str);
			MyString second = "itischar";
			Assert::IsTrue(first == second, L"Assert1");

			str = "";
			first.AppEnd(str);
			Assert::IsTrue(first == second, L"Assert2");

			str = "itischar";
			MyString third;
			third.AppEnd("itischar");
			Assert::IsTrue(third == second, L"Assert3");


			str = "";
			MyString fourth;
			fourth.AppEnd(str);
			char *temp = fourth.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert4");
		}

		TEST_METHOD(AppEndStdStringIndexCount)
		{
			std::string str = "bbischarjhg";
			MyString first = "it";
			first.AppEnd(str, 2, 6);
			MyString second = "itischar";
			Assert::IsTrue(first == second, L"Assert1");

			str = "";
			first.AppEnd(str, 0, 2);
			Assert::IsTrue(first == second, L"Assert2");
			first.AppEnd(str, 0, 0);
			Assert::IsTrue(first == second, L"Assert3");

			str = "hhyitischarll";
			MyString third;
			third.AppEnd(str, 3, 8);
			Assert::IsTrue(third == second, L"Assert4");

			str = "";
			MyString fourth;
			fourth.AppEnd(str, 0, 9);
			char *temp = fourth.CStr();
			Assert::IsTrue(temp[0] == '\0', L"Assert5");
		}
		
		TEST_METHOD(ReplaceIndexCountCharString)
		{
			MyString first = "hello amazing world";
			first.Replace(6, 7, "wonderful");
			MyString second = "hello wonderful world";
			Assert::IsTrue(first == second, L"Assert1");

			first.Replace(6, 9, "char");
			second = "hello charcharc world";
			Assert::IsTrue(first == second, L"Assert2");

			char *nul_str = nullptr;
			first.Replace(6, 9, nul_str);
			Assert::IsTrue(first == second, L"Assert3");

			MyString fifth = "abcde";
			MyString sixth = "abcde";
			fifth.Replace(5, 1, "l");
			Assert::IsTrue(fifth == sixth, L"Assert4");

			fifth.Replace(0, 5, "l");
			sixth = "lllll";
			Assert::IsTrue(fifth == sixth, L"Assert5");


			MyString test = "hello amazing world";
			test.Replace(6, 4, "fu");
			Assert::IsTrue(test.Capacity() == 20, L"Assert6");
			MyString sectest = "hello fufuing world";
			Assert::IsTrue(test == sectest, L"Assert7");
		}

		TEST_METHOD(ReplaceIndexCountStdString)
		{
			std::string str = "wonderful";
			MyString first = "hello amazing world";
			first.Replace(6, 7, str);
			MyString second = "hello wonderful world";
			Assert::IsTrue(first == second, L"Assert1");

			str = "char";
			first.Replace(6, 9, str);
			second = "hello charcharc world";
			Assert::IsTrue(first == second, L"Assert2");

			std::string nul_str = "";
			first.Replace(6, 9, nul_str);
			Assert::IsTrue(first == second, L"Assert3");

			MyString fifth = "abcde";
			MyString sixth = "abcde";
			str = "l";
			fifth.Replace(5, 1, str);
			Assert::IsTrue(fifth == sixth, L"Assert4");

			fifth.Replace(0, 5, str);
			sixth = "lllll";
			Assert::IsTrue(fifth == sixth, L"Assert5");
		}

		TEST_METHOD(SubstringIndex)
		{
			MyString first = "hello amazing world";
			MyString temp = first.Substr(0);
			MyString second = temp.CStr();
			Assert::IsTrue(first == second, L"Assert1");
			second = "world";
			temp = first.Substr(14);
			first = temp.CStr();
			Assert::IsTrue(first == second, L"Assert2");


			first = "test";
			temp = first.Substr(5);
			Assert::IsTrue(temp.Empty(), L"Assert3");

			temp = nullptr;
			first = nullptr;
			temp = first.Substr(0);
			Assert::IsTrue(temp.Empty(), L"Assert4");

		}
		TEST_METHOD(SubstringIndexCount)
		{
			MyString first = "hello amazing world";
			MyString temp = first.Substr(0, 19);
			MyString second = temp.CStr();
			Assert::IsTrue(first == second, L"Assert1");
			
			second = "amazing";
			temp = first.Substr(6, 7);
			first = temp.CStr();
			Assert::IsTrue(first == second, L"Assert2");



			first = "test";
			temp = first.Substr(5, 1);
			Assert::IsTrue(temp.Empty(), L"Assert3");

			temp = nullptr;
			first = nullptr;
			temp = first.Substr(0, 1);
			Assert::IsTrue(temp[0] == 0, L"Assert4");

		}
		TEST_METHOD(FindCharStr)
		{
			MyString string = "hello amazing world";
			int index = string.Find("ll");
			Assert::IsTrue(index == 2, L"Assert1");

			index = string.Find("ld");
			Assert::IsTrue(index == 17, L"Assert2");

			index = string.Find("a");
			Assert::IsTrue(index == 6, L"Assert3");

			index = string.Find("");
			Assert::IsTrue(index == -1, L"Assert4");

			index = string.Find("b");
			Assert::IsTrue(index == -1, L"Assert5");

			string = "";
			index = string.Find("a");
			Assert::IsTrue(index == -1, L"Assert6");

			index = string.Find("");
			Assert::IsTrue(index == -1, L"Assert7");

			char *test = nullptr;
			index = string.Find(test);
			Assert::IsTrue(index == -1, L"Assert8");

			MyString first;
			index = first.Find("");
			Assert::IsTrue(index == -1, L"Assert9");

		}
		TEST_METHOD(FindCharStrIndex)
		{
			MyString string = "hello amazing world";
			int index = string.Find("ll",2);
			Assert::IsTrue(index == 2, L"Assert1");

			index = string.Find("ll", 3);
			Assert::IsTrue(index == -1, L"Assert2");

			index = string.Find("ld", 17);
			Assert::IsTrue(index == 17, L"Assert3");

			index = string.Find("ld", 19);
			Assert::IsTrue(index == -1, L"Assert4");



			index = string.Find("", 0);
			Assert::IsTrue(index == -1, L"Assert5");


			index = string.Find("b", 5);
			Assert::IsTrue(index == -1, L"Assert6");

			string = "";
			index = string.Find("a", 0);
			Assert::IsTrue(index == -1, L"Assert7");

			index = string.Find("", 0);
			Assert::IsTrue(index == -1, L"Assert8");

		}

		TEST_METHOD(FindStdStr)
		{
			MyString string = "hello amazing world";
			std::string substring = "ll";
			int index = string.Find(substring);
			Assert::IsTrue(index == 2, L"Assert1");

			substring = "ld";
			index = string.Find(substring);
			Assert::IsTrue(index == 17, L"Assert2");

			substring = "a";
			index = string.Find(substring);
			Assert::IsTrue(index == 6, L"Assert3");

			substring = "";
			index = string.Find(substring);
			Assert::IsTrue(index == -1, L"Assert4");

			substring = "b";
			index = string.Find(substring);
			Assert::IsTrue(index == -1, L"Assert5");

			substring = "a";
			string = "";
			index = string.Find(substring);
			Assert::IsTrue(index == -1, L"Assert6");

			substring = "";
			index = string.Find(substring);
			Assert::IsTrue(index == -1, L"Assert7");

			MyString first;
			index = first.Find(substring);
			Assert::IsTrue(index == -1, L"Assert8");

			std::string n_str;
			index = string.Find(n_str);
			Assert::IsTrue(index == -1, L"Assert8");

		}

		TEST_METHOD(FindStdStrIndex)
		{
			std::string substring = "ll";
			MyString string = "hello amazing world";
			int index = string.Find(substring, 2);
			Assert::IsTrue(index == 2, L"Assert1");

			index = string.Find(substring, 3);
			Assert::IsTrue(index == -1, L"Assert2");

			substring = "ld";
			index = string.Find(substring, 17);
			Assert::IsTrue(index == 17, L"Assert3");

			index = string.Find(substring, 19);
			Assert::IsTrue(index == -1, L"Assert4");



			substring = "";
			index = string.Find(substring, 0);
			Assert::IsTrue(index == -1, L"Assert5");


			substring = "b";
			index = string.Find(substring, 5);
			Assert::IsTrue(index == -1, L"Assert6");

			substring = "a";
			string = "";
			index = string.Find(substring, 0);
			Assert::IsTrue(index == -1, L"Assert7");

			std::string null_str;
			index = string.Find(null_str, 0);
			Assert::IsTrue(index == -1, L"Assert8");

		}

		/*(TEST_METHOD(FindAchoKorasik)
		{
			vector<MyString> keywords;
			keywords.push_back("er");
			keywords.push_back("lool");
			keywords.push_back("hl");
			MyString first = "aisers";
			int k = 3;
			first.FindAhoCorasick(keywords, k);
			
		}*/
		TEST_METHOD(OperatorIndex)
		{
			MyString first = "simple";
			Assert::IsTrue(first[0] == 's', L"Assert 1");
			first[0] = 'p';
			Assert::IsTrue(first[0] == 'p', L"Assert 2");
			Assert::IsTrue(first[8] == '\0', L"Assert 3");
		}
	};
}