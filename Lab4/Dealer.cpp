#include "Dealer.h"



Dealer::Dealer()
{
	_hand = new Hand();
}


Dealer::~Dealer()
{
	delete _hand;
}