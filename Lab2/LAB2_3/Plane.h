#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "PlaneStatistic.h"
#include <random>
#include <ctime>


class Plane
{
	public:
		Plane();
		Plane(std::string, int, int, int);
		~Plane();


	private:
		std::string model;
		int year;
		mutable int* airlines;
		mutable int passengersCount;
		int maxPassengersCount;
		mutable bool canFly;
		mutable int flyCount;

	private:
		void Initialize() const;
		mutable std::string* stringValue;
		static PlaneStatistic* planeStatistic;
		static std::mt19937 random;

	public:
		const int MAX_AIRLINES = 10;

	public:
		std::string GetModel() const;
		void SetModel(const char*);
		int GetYear() const;
		void SetYear(int);
		int GetAirineById(int) const;
		bool RemoveAirlineById(int) const;
		bool AddAirlane(int) const;
		int* GetAirlines() const;
		void ClearAirlines() const;
		int GetPassengersCount() const;
		void SetPassengersCount(int) const;
		int GetMaxPassengersCount() const;
		void SetMaxPassengersCount(int);
		const char* ToString() const;
		double FillingRate() const;

		void Serialize() const;
		void DeSerialize();
		void Serialize(const char* path) const;
		void DeSerialize(const char* path);

		bool Fly() const;

		static int Compare(const void* a, const void* b);
		static void ShowFullStatistic();

		bool operator>(Plane& val);
		bool operator<(Plane& val);
		bool operator==(Plane& val);
		bool operator<=(Plane& val);
		bool operator>=(Plane& val);

};

