#pragma once
#include <string>
#include "ErrorLogger.h"

using namespace std;

class Planet
{
private:
	string namePlanet;
	tm openDate;
	double radius;
public:
	ErrorLogger ErrorSearcher;

	void setNamePlanet(string);
	void setOpenDate(tm);
	void setRadius(double);

	string getNamePlanet(void);
	tm getOpenDate(void);
	double getRadius(void);

	Planet(void);
	~Planet(void);
};

