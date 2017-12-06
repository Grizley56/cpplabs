#pragma once
#include "Deck.h"
#include <random>

class Shoe
{
public:
	Shoe(unsigned decksCount, Deck::DeckType type); 
	~Shoe();

	void shuffle() const;
	Card& getCard() const;
	unsigned cardsTotalCount() const;
	unsigned getDecksCount() const;
	Deck** getDecks() const;
	Deck* getDeck(size_t i);

private:
	unsigned _decksCount;
	Deck** _decks;
	static std::mt19937 _random;
};

