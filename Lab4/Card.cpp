#include "Card.h"
#include <string>

Card::Card(const Suit suit, const int value, const wchar_t* name) : _value(value), _suit(suit)
{
	if (value > 99 || value < 0)
		throw std::invalid_argument("value");

	if (name)
		_name = name;
	else
		_name = std::to_wstring(value);
}

Card::Card() {};

Card::~Card() { }

std::wstring Card::toStringw() const
{
	return _name + static_cast<wchar_t>(_suit);
}

int Card::getValue() const
{
	return _value;
}

Card::Suit Card::getSuit() const
{
	return _suit;
}

std::wstring Card::getName() const
{
	return _name;
}
