#pragma once
#include <string>
#include <iostream>

using namespace std;

class ErrorLogger
{
private:
	const string ERROR_OPEN_FILE = "Ошибка открытия файла!";
	const string ERROR_NAME_PLANET = "Ошибка формата файла(Название)!";
	const string ERROR_DATE = "Ошибка формата файла(Дата)!";
	const string ERROR_RADIUS = "Ошибка формата файла(Радиус)!";
	const string ERROR_STRUCT = "Ошибка структуры файла!";

public:
	void fileOpenChecker(bool);
	void checkName(string);
	void checkDate(tm);
	void checkDate(string);
	void checkRadius(double);
};