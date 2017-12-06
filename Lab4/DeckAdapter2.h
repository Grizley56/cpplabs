#pragma once
#include "Deck.h"
#include "IFormattable.h"

class DeckAdapter2: public Deck, public IFormattable
{
public:
	DeckAdapter2(DeckType type = DeckType::SMALL_DECK);
	~DeckAdapter2();

	std::wstring format() const override;
};

