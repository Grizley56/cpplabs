#pragma once
#include "Deck.h"
#include <ostream>
#include "Player.h"

class Dealer
{
public:
	Dealer();
	~Dealer();


	friend std::wostream& operator<<(std::wostream& os, const Dealer& obj)
	{
		if (obj._hand->cardsCount() == 2 && !obj.getCardVisible())
			return os << **obj._hand->begin() << " ??";

		for (auto card : *obj._hand)
			os << (*card) << L" ";

		return os;
	}

	Hand& getHand() const { return *_hand; }
	void clearHand() const { _hand->clearHand(); _isCardVisible = false; }
	
	bool getCardVisible() const { return _isCardVisible; }
	void setCardVisible(bool value) const { _isCardVisible = value; }

private:
	Hand* _hand;
	mutable bool _isCardVisible = false;
};

