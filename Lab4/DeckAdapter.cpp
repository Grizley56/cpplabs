#include "DeckAdapter.h"
#include "Deck.h"

DeckAdapter::DeckAdapter(Deck& deck)
{
	_adaptee = &deck;
}


DeckAdapter::~DeckAdapter()
{
}

std::wstring DeckAdapter::format() const
{
	std::wstring result;
	for (auto card : *_adaptee)
		result += L"*" + card->toStringw() + L"*\n";
	return result;
}
