#include <random>
#include <ctime>
#include <iostream>
#include "Plane.h"
#include "PassengersPlane.h"
#include "CargoPlane.h"

const short PLANES_COUNT = 1000;

Plane* initializePlane(const char* model);

int main()
{
	//Plane* boing_747 = initializePlane("Boing 747");
	//Plane* A_380 = initializePlane("A380");
	//Plane* Ty_154 = initializePlane("Ty-154");

	CargoPlane cp("cargo#1", 2010, 10000, 20000);
	cp.Fly();
	std::cout << cp.ToString();
	return 0;
}

Plane* initializePlane(const char* model)
{
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> yearUid(2010, 2017);
	std::uniform_int_distribution<> maxPassCountUid(300, 500);
	std::uniform_int_distribution<> airlanesCountUid(0, 10);
	std::uniform_int_distribution<> airlanesIdUid(0, 1000);

	Plane* planes[PLANES_COUNT];

	for (size_t i = 0; i < PLANES_COUNT; ++i)
	{
		int airlanesCount = airlanesCountUid(gen);
		int maxPassCount = maxPassCountUid(gen);

		std::uniform_int_distribution<> passCountUid(150, maxPassCount);

		int passCount = passCountUid(gen);
		int year = yearUid(gen);
		
		//planes[i] = new Plane(model, year, passCount, maxPassCount);

		//for (size_t j = 0; j < airlanesCount; ++j)
		//	planes[i]->AddAirlane(airlanesIdUid(gen));
		for (size_t j = 0; j < 1000; ++j)
			if (!planes[i]->Fly())
				break;
	}
	return *planes;
}