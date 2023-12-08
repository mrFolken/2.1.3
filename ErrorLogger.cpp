#include "ErrorLogger.h"

void ErrorLogger::fileOpenChecker(bool buf)
{
	try
	{
		if (!buf)
			throw ERROR_OPEN_FILE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		exit(0);
	}
}

void ErrorLogger::checkName(string buf)
{
	try
	{
		if (buf == "")
			throw ERROR_NAME_PLANET;
	}
	catch (const string err)
	{
		cerr << err << endl;
		exit(0);
	}
}

void ErrorLogger::checkDate(tm buf)
{
	try
	{
		if (!(buf.tm_year >= 1 && buf.tm_year <= 2023))
			throw ERROR_DATE;
		if (!(buf.tm_mon >= 1 && buf.tm_mon <= 12))
			throw ERROR_DATE;
		if (!(buf.tm_mday >= 1 && buf.tm_mday <= 31))
			throw ERROR_DATE;
	}
	catch (const string err)
	{
		cerr << err << endl;
		exit(0);
	}
}

void ErrorLogger::checkDate(string buf)
{
	try
	{
		if (!(buf.size() == 10))
			throw ERROR_STRUCT;
	}
	catch (const string err)
	{
		cerr << err << endl;
		exit(0);
	}
}

void ErrorLogger::checkRadius(double buf)
{
	try
	{
		if (!(buf >= 0))
			throw ERROR_RADIUS;
	}
	catch (const string err)
	{
		cerr << err << endl;
		exit(0);
	}

}