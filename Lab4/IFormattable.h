#pragma once
#include <string>

class IFormattable
{
public:
	virtual std::wstring format() const = 0;
};

