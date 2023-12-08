#pragma once
#include <string>
#include <iostream>

using namespace std;

class ErrorLogger
{
private:
	const string ERROR_OPEN_FILE = "������ �������� �����!";
	const string ERROR_NAME_PLANET = "������ ������� �����(��������)!";
	const string ERROR_DATE = "������ ������� �����(����)!";
	const string ERROR_RADIUS = "������ ������� �����(������)!";
	const string ERROR_STRUCT = "������ ��������� �����!";

public:
	void fileOpenChecker(bool);
	void checkName(string);
	void checkDate(tm);
	void checkDate(string);
	void checkRadius(double);
};