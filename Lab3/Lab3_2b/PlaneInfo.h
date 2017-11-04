#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "AccidentInfo.h"
class PlaneInfo
{
public:
	PlaneInfo(std::string model);
	PlaneInfo(const PlaneInfo& plane);
	~PlaneInfo();

private:
	std::string model;
	int planesCount;
	int peoplesSurvivedSummary;
	int accidentsCount;
	std::vector<AccidentInfo*>* accidents;
public:
	std::string getModel() const;
	int getPlanesCount() const;
	int getPeoplesSurvivedSummary() const;
	int getAccidentsCount() const;
	void planeCrash(int survCount, int flyCount);
	std::vector<AccidentInfo*>* getAccidents();
	PlaneInfo& operator++();
	PlaneInfo operator++(int);
};