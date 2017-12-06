#include "DeckAdapter2.h"



DeckAdapter2::DeckAdapter2(DeckType type) : Deck(type) { }


DeckAdapter2::~DeckAdapter2() { }

std::wstring DeckAdapter2::format() const
{
	std::wstring result;
	for (auto card : *this)
		result += L"*" + card->toStringw() + L"*\n";
	return result;
}
