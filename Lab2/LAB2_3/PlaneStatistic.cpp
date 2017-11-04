#include "PlaneStatistic.h"
#include "Plane.h"
#include <iostream>

PlaneStatistic::PlaneStatistic()
{
	statistic = new std::map<std::string, PlaneInfo*>;
}


PlaneStatistic::~PlaneStatistic()
{
}

bool PlaneStatistic::addToStatistic(const Plane& plane)
{
	std::string planeModel = plane.GetModel();
	if (statistic->find(planeModel) != statistic->end())
	{
		(*statistic)[planeModel]->operator++();
		return true;
	}
	PlaneInfo* info = new PlaneInfo(planeModel);
	statistic->insert(std::pair<std::string, PlaneInfo*>(planeModel, info));
	return false;
}

void PlaneStatistic::fixAccident(const std::string& model, int survCount, int flyCount)
{
	(*statistic)[model]->planeCrash(survCount, flyCount);
}

void PlaneStatistic::showFull()
{
	int i = 0;
	for (const auto& kv : *statistic)
	{
		std::cout << "-------------------------" << std::endl;
		std::cout << "Plane: " << kv.first << " (summary " 
			<<kv.second->getAccidentsCount() << " accidents)" <<  std::endl;
		if (kv.second->getAccidentsCount() > 0)
		{
			std::cout << "ACCIDENT LIST:" << std::endl;
			for (size_t i = 0; i < kv.second->getAccidentsCount(); ++i)
			{
				std::cout << "Date of accident: " << asctime((*kv.second->getAccidents())[i]->time);
				std::cout << "Flights before the accident: " << 
					(*kv.second->getAccidents())[i]->flyCount << std::endl;
				if ((*kv.second->getAccidents())[i]->survCount > 0)
					std::cout << "Peoples survived: " << (*kv.second->getAccidents())[i]->survCount
					<< std::endl << std::endl;
				else
					std::cout << "No one survived..." << std::endl << std::endl;
			}
		}
		else
			std::cout << "There were no accidents" << std::endl;
	}
}
