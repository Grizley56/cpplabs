#include "Deck.h"
#include "Card.h"
#include <algorithm>

Deck::Deck(DeckType type)
{
	size_t firstNumCard = static_cast<int>(type);
	_cards = new std::vector<Card*>();
	_cardsOut = new std::vector<Card*>();

	for each (Card::Suit suit in _suits)
	{
		for (size_t i = firstNumCard; i <= 10; i++)
			_cards->push_back(new Card(suit, i));

		_cards->push_back(new Card(suit, 10, L"J"));
		_cards->push_back(new Card(suit, 10, L"Q"));
		_cards->push_back(new Card(suit, 10, L"K"));
		_cards->push_back(new Card(suit, 11, L"A"));
	}
}

Deck::Deck()
{
}

Deck::~Deck()
{
	delete _cards;
	delete _cardsOut;
}

Card& Deck::getCard() const
{
	Card* card = (*_cards).back();
	_cards->pop_back();
	_cardsOut->push_back(card);
	return *card;
}

void Deck::shuffle() const
{
	_cards->insert(_cards->end(), _cardsOut->begin(), _cardsOut->end());
	_cardsOut->clear();
	random_shuffle(_cards->begin(), _cards->end());
}

size_t Deck::cardsCount() const
{
	return _cards->size();
}

