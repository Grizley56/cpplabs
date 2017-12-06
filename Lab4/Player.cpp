#include "Player.h"



Player::Player(unsigned startMoney)
{
	_money = startMoney;
}


Player::~Player()
{
	for (auto hand : _hands)
		delete hand;
}

int Player::getTotalMoney() const
{
	return _money;
}

void Player::splitHand(size_t index)
{
	Hand* hand = _hands[index];
	_hands.push_back(hand->split());
}

void Player::clearHands()
{
	for (auto hand : _hands)
	{
		hand->clearHand();
		delete hand;
	}

	_hands.clear();

	_hands.push_back(new Hand());
}

void Player::clearHand(size_t index)
{
	if (index > handsCount() - 1)
		throw std::out_of_range("index");

	_hands[index]->clearHand();
}


Hand& Player::getHand(size_t index) const
{
	if (index > handsCount() - 1)
		throw std::out_of_range("index");

	return *(_hands[index]);
}

bool Player::allHandsStand()
{
	for (auto hand : _hands)
		if (!hand->getStand() && !hand->isBust())
			return false;

	return true;
}

void Player::pay(int count)
{
	_money += count;
}
