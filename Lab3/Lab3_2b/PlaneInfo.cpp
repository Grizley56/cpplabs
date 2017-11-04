#include "PlaneInfo.h"



PlaneInfo::PlaneInfo(std::string model) : model(model)
{
	accidentsCount = 0;
	peoplesSurvivedSummary = 0;
	planesCount = 1;
	accidents = new std::vector<AccidentInfo*>();
}

PlaneInfo::PlaneInfo(const PlaneInfo & plane)
{
	model = plane.getModel();
	planesCount = plane.getPlanesCount();
	peoplesSurvivedSummary = plane.getPeoplesSurvivedSummary();
	accidentsCount = plane.getAccidentsCount();
}

PlaneInfo::~PlaneInfo() { }


std::string PlaneInfo::getModel() const
{
	return model;
}

int PlaneInfo::getPlanesCount() const
{
	return planesCount;
}

int PlaneInfo::getPeoplesSurvivedSummary() const
{
	return peoplesSurvivedSummary;
}

int PlaneInfo::getAccidentsCount() const
{
	return accidentsCount;
}

void PlaneInfo::planeCrash(int survCount, int flyCount)
{
	++accidentsCount;
	peoplesSurvivedSummary += survCount;

	time_t timeInSecs;
	struct tm * timeinfo;
	time(&timeInSecs);
	timeinfo = localtime(&timeInSecs);
	AccidentInfo* info = new AccidentInfo(timeinfo, survCount, flyCount);

	accidents->insert(accidents->end(), info);
}

std::vector<AccidentInfo*>* PlaneInfo::getAccidents()
{
	return accidents;
}

PlaneInfo & PlaneInfo::operator++()
{
	planesCount++;
	return *this;
}

PlaneInfo PlaneInfo::operator++(int)
{
	PlaneInfo plane(*this);
	planesCount++;
	return plane;
}

