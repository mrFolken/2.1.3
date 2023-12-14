#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class ErrorLogger
{
private:
	const string ERROR_OPEN_FILE = "������ �������� �����!\npress any key";
	const string ERROR_STRUCT_FILE = "������ ��������� �����!\npress any key";

public:
	bool haveError;

	bool fileOpenChecker(bool);
	bool checkName(string);
	bool checkDate(tm);
	bool checkDate(string);
	bool checkRadius(double);
};