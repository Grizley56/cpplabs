#pragma once
#include <string>
#include <ostream>

class Card
{


public:
	enum class Suit : wchar_t 
	{ 
		SPADE = L'\u2660', HEART = L'\u2665', DIAMOND = L'\u2666', CLUB = L'\u2663' 
	};

	Card(const Suit suit, const int value, const wchar_t* name = nullptr);
	Card();
	~Card();


	friend std::wostream& operator<<(std::wostream& os, const Card& obj)
	{
		return os << obj._name  << static_cast<wchar_t>(obj._suit);
	}

	std::wstring toStringw() const;
	int getValue() const;
	Suit getSuit() const;
	std::wstring getName() const;

private:
	int _value;
	Suit _suit;
	std::wstring _name;
};

