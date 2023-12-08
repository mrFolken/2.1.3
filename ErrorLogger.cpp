#include "ErrorLogger.h"

bool ErrorLogger::fileOpenChecker(bool buf)
{
	try
	{
		if (!buf)
			throw ERROR_OPEN_FILE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		this->haveError = 1;
		_getch();
		return 0;
	}
	return 1;
}

bool ErrorLogger::checkName(string buf)
{
	try
	{
		if (buf == "")
			throw ERROR_STRUCT_FILE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		this->haveError = 1;
		_getch();
		return 0;
	}
	return 1;
}

bool ErrorLogger::checkDate(tm buf)
{
	try
	{
		if (!(buf.tm_year >= 1 && buf.tm_year <= 2023))
			throw ERROR_STRUCT_FILE;
		if (!(buf.tm_mon >= 1 && buf.tm_mon <= 12))
			throw ERROR_STRUCT_FILE;
		if (!(buf.tm_mday >= 1 && buf.tm_mday <= 31))
			throw ERROR_STRUCT_FILE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		this->haveError = 1;
		_getch();
		return 0;
	}
	return 1;
}

bool ErrorLogger::checkDate(string buf)
{
	try
	{
		if (!(buf.size() == 10))
			throw ERROR_STRUCT_FILE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		this->haveError = 1;
		_getch();
		return 0;
	}
	return 1;
}

bool ErrorLogger::checkRadius(double buf)
{
	try
	{
		if (!(buf >= 0))
			throw ERROR_STRUCT_FILE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		this->haveError = 1;
		_getch();
		return 0;
	}
	return 1;
}