#pragma once
#include <list>
#include <vector>
#include "Card.h"


class Card;

class Hand
{
public:
	Hand();
	~Hand();


	using iterator = std::vector<Card*>::iterator;
	using const_iterator = std::vector<Card*>::const_iterator;

	iterator begin() { return _hand.begin(); }
	iterator end() { return _hand.end(); }
	const_iterator begin() const { return _hand.begin(); }
	const_iterator end() const { return _hand.end(); }
	const_iterator cbegin() const { return _hand.cbegin(); }
	const_iterator cend() const { return _hand.cend(); }

	friend std::wostream& operator<<(std::wostream& os, const Hand& obj)
	{
		for (auto card : obj)
			os << *card << L" ";
		
		return os;
	}

	bool canSplit();
	Hand* split();
	void addCard(Card& card);
	void clearHand();
	bool isBlackJack() const;
	bool isBust() const;
	int totalValue() const;
	size_t cardsCount() const;

	void setStand(bool s) { _isStand = s; };
	bool getStand() const { return _isStand; }
private:
	std::vector<Card*> _hand;
	bool _isStand = false;
};

