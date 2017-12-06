#pragma once
#include <exception>
#include <string>

class BustException: public std::exception
{
public:
	BustException();
	BustException(const char* const str);
	~BustException();
};

