#include "Shoe.h"
#include <ctime>


Shoe::Shoe(unsigned decksCount, Deck::DeckType type): _decksCount(decksCount)
{
	_decks = new Deck*[_decksCount];
	for (size_t i = 0; i < _decksCount; ++i)
		_decks[i] = new Deck(type);
}

Shoe::~Shoe()
{
}

void Shoe::shuffle() const
{
	for (size_t i = 0; i < _decksCount; ++i)
		_decks[i]->shuffle();
}

Card& Shoe::getCard() const
{
	std::uniform_int_distribution<> uidDeck(0, _decksCount-1);
	Deck* deck = _decks[uidDeck(_random)];
	return deck->getCard();
}

unsigned Shoe::cardsTotalCount() const
{
	unsigned total = 0;
	for (size_t i = 0; i < _decksCount; ++i)
		total += _decks[i]->cardsCount();
	return total;
}

unsigned Shoe::getDecksCount() const
{
	return _decksCount;
}

Deck** Shoe::getDecks() const
{
	return _decks;
}

Deck* Shoe::getDeck(size_t i)
{
	if (i > _decksCount - 1)
		throw 1; // TBD
	return _decks[i];
}

std::mt19937 Shoe::_random(time(0));
