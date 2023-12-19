#include "pch.h"
#include "CppUnitTest.h"
#include "..\Planet.h"
#include "..\Planet.cpp"
#include "..\ErrorLogger.h"
#include "..\ErrorLogger.cpp"
#include "..\main.h"
#include "..\main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSetNamePlanet)
		{
			Planet buf;
			string str = "Марс";
			buf.setNamePlanet(str);

			Assert::IsTrue(buf.getNamePlanet() == str);
		}

		TEST_METHOD(TestSetRadius)
		{
			Planet buf;
			double a = 62;
			buf.setRadius(a);

			Assert::IsTrue(buf.getRadius() == a);
		}
		
		TEST_METHOD(TestStringToTm)
		{
			Planet buf;
			string str = "1980.01.01";
			tm *a = NULL;
			a = new tm;
			a->tm_hour = 0;
			a->tm_isdst = 0;
			a->tm_min = 0;
			a->tm_sec = 0;
			a->tm_yday = 0;
			a->tm_wday = 0;

			a->tm_year = 1980;
			a->tm_mon = 1;
			a->tm_mday = 1;
			Assert::IsTrue(stringToTm(str).tm_year == a->tm_year && stringToTm(str).tm_mon == a->tm_mon && stringToTm(str).tm_mday == a->tm_mday);	

			str = "160.01.01";
			Assert::IsTrue(stringToTm(str).tm_year != a->tm_year && stringToTm(str).tm_mon != a->tm_mon && stringToTm(str).tm_mday != a->tm_mday);
		}
		
		TEST_METHOD(TestSetOpenDate)
		{
			Planet buf;
			buf.setOpenDate(stringToTm("1980.01.01"));

			Assert::IsTrue(buf.getOpenDate().tm_year == 1980 && buf.getOpenDate().tm_mon == 1 && buf.getOpenDate().tm_mday == 1);
		}

		TEST_METHOD(TestEnterFileName)
		{
			string str = "Планеты.txt";
			Assert::IsTrue(enterFileName() == str);
		}
	};
}
