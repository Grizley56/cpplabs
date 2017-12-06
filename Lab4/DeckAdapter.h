#pragma once
#include "IFormattable.h"

class Deck;

class DeckAdapter: public IFormattable
{
public:
	DeckAdapter(Deck& deck);
	~DeckAdapter();

	std::wstring format() const override;

private:
	Deck* _adaptee;
};

