#include "Planet.h"

void Planet::setNamePlanet(string buf)
{
	if(ErrorSearcher.checkName(buf))
		namePlanet = buf;
}

void Planet::setOpenDate(tm buf)
{
	if (ErrorSearcher.checkDate(buf))
		openDate = buf;
}

void Planet::setRadius(double buf)
{
	if (ErrorSearcher.checkRadius(buf))
		radius = buf;
}

string Planet::getNamePlanet(void)
{
	return namePlanet;
}

tm Planet::getOpenDate(void)
{
	return openDate;
}

double Planet::getRadius(void)
{
	return radius;
}

Planet::Planet(void)
{
	ErrorSearcher.haveError = 0;
}

Planet::~Planet(void)
{

}
