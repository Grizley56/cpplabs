#include "Hand.h"
#include "Card.h"
#include "BustException.h"


Hand::Hand()
{

}


Hand::~Hand()
{
}

bool Hand::canSplit()
{
	for(size_t i = 0; i < _hand.size(); ++i)
	{
		for (size_t j = i + 1; j < _hand.size(); ++j)
			if (_hand[i]->getName() == _hand[j]->getName())
				return true;
	}

	return false;
}

Hand* Hand::split()
{
	if (!canSplit())
		return nullptr;

	for (size_t i = 0; i < _hand.size(); ++i)
	{
		for (size_t j = i + 1; j < _hand.size(); ++j)
			if (_hand[i]->getName() == _hand[j]->getName())
			{
				iterator splittedCard = _hand.begin() + j;
				Card* card = *splittedCard;
				_hand.erase(splittedCard);
				Hand* newHand = new Hand();
				newHand->addCard(*card);
				return newHand;
			}
	}
}

void Hand::addCard(Card& card)
{
	_hand.push_back(&card);
	if (isBust())
		throw BustException();
}

void Hand::clearHand()
{
	_hand.clear();
}

bool Hand::isBlackJack() const
{
	if (_hand.size() == 2 && totalValue() == 21)
		return true;

	return false;
}

bool Hand::isBust() const
{
	return totalValue() > 21;
}

int Hand::totalValue() const
{
	int total = 0;
	int acesCount = 0;

	for (auto card : _hand)
	{
		if (card->getName() == L"A")
			++acesCount;
		else
			total += card->getValue();
	}

	if (acesCount == 0)
		return total;

	int with11 = total + 11 + acesCount - 1;

	if (with11 <= 21)
		return with11;

	return total + acesCount;
}

size_t Hand::cardsCount() const
{
	return _hand.size();
}
