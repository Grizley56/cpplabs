#pragma once
#include "Card.h"
#include <ostream>
#include <vector>
#include "Hand.h"
#include <iostream>

class Player
{
public:
	explicit Player(unsigned startMoney = 1000);
	~Player();

	int getTotalMoney() const;

	friend std::wostream& operator<<(std::wostream& os, const Player& obj)
	{
		bool multiplyHands = obj._hands.size() > 1;
		size_t handIndex = 0;

		for (auto hand : obj._hands)
		{
			if (multiplyHands)
				std::wcout << L"\nHand " + std::to_wstring(++handIndex) + L": ";

			std::wcout << *hand;
		}

		return os;
	}

	void splitHand(size_t index);
	void clearHands();
	void clearHand(size_t index);
	Hand& getHand(size_t index = 0) const;

	const std::vector<Hand*>& getHands() const { return _hands; }
	size_t handsCount() const { return _hands.size(); }
	bool handSplitted() const { return _hands.size() > 1; }
	bool allHandsStand();
	void pay(int count);

private:
	int _money;
	std::vector<Hand*> _hands;
};

