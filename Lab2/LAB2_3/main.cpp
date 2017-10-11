#include "Plane.h"
#include <random>
#include <ctime>
#include <iostream>


const short PLANES_COUNT = 3;

int main()
{
	Plane* plane = new Plane("CE1366B", 2017, 400, 450);

	Plane planes[PLANES_COUNT];

	planes[0].SetModel("Boing 747");
	planes[1].SetModel("A380");
	planes[2].SetModel("Ty-154");

	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> yearUid(2010, 2017);
	std::uniform_int_distribution<> maxPassCountUid(300, 500);
	std::uniform_int_distribution<> airlanesCountUid(0, 10);
	std::uniform_int_distribution<> airlanesIdUid(0, 1000);

	for (size_t i = 0; i < PLANES_COUNT; ++i)
	{
		int airlanesCount = airlanesCountUid(gen);
		for (size_t j = 0; j < airlanesCount; ++j)
			planes[i].AddAirlane(airlanesIdUid(gen));


		int maxPassCount = maxPassCountUid(gen);
		planes[i].SetMaxPassengersCount(maxPassCount);

		std::uniform_int_distribution<> passCountUid(150, maxPassCount);
		int passCount = passCountUid(gen);
		planes[i].SetPassengersCount(passCount);

		int year = yearUid(gen);
		planes[i].SetYear(year);
		std::cout << planes[i].ToString() << std::endl;
	}

	std::qsort(planes, 3, sizeof(Plane), Plane::Compare);

	for each (Plane plane in planes)
	{
		std::cout << plane.ToString() << std::endl;
	}

	delete plane;

	return 0;

}