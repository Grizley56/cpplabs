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
		Plane(std::string, int);
		virtual ~Plane();


	private:
		std::string model;
		int year;
		void Initialize() const;

	protected:
		mutable int* airlines;
		mutable bool canFly;
		mutable int flyCount;
		static std::mt19937 random;
		mutable std::string* stringValue;

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

		virtual const char* ToString() const = 0;
		virtual double FillingRate() const = 0;
		virtual bool Fly() const = 0;


		void Serialize() const;
		void DeSerialize();
		virtual void Serialize(const char* path) const;
		virtual void DeSerialize(const char* path);

		static int Compare(const void* a, const void* b);

		bool operator>(Plane& val);
		bool operator<(Plane& val);
		bool operator==(Plane& val);
		bool operator<=(Plane& val);
		bool operator>=(Plane& val);
};

