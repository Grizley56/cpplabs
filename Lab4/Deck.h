#pragma once
#include "Card.h"
#include <vector>


class Deck
{
public:
	using iterator = std::vector<Card*>::iterator;
	using const_iterator = std::vector<Card*>::const_iterator;

  enum class DeckType : int { FULL_DECK_WITHOUT_JOKERS = 2, SMALL_DECK = 6 };

	iterator begin() { return _cards->begin(); }
	iterator end() { return _cards->end(); }
	const_iterator begin() const { return _cards->begin(); }
	const_iterator end() const { return _cards->end(); }
	const_iterator cbegin() const { return _cards->cbegin(); }
	const_iterator cend() const { return _cards->cend(); }

	Deck(DeckType type);
	Deck();	
	~Deck();

	Card& getCard() const;
	void shuffle() const;
	size_t cardsCount() const;

private:
	std::vector<Card*>* _cards;
	std::vector<Card*>* _cardsOut;
	//Card** _cards;
	const Card::Suit _suits[4] = { Card::Suit::CLUB, Card::Suit::DIAMOND, Card::Suit::HEART, Card::Suit::SPADE };
};

