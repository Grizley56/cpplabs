#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"

class Game
{
public:
	explicit Game(Deck::DeckType = Deck::DeckType::FULL_DECK_WITHOUT_JOKERS);
	~Game();

	bool checkForInstaBlackJack(int playerBid);
	void run();

private:
	Player* _player;
	Dealer* _dealer;
	Shoe* _shoe;
	bool _isGameRunning;
	wchar_t* _tmp_action_input = new wchar_t[3];


	void printHands();
	void printDecks();
	int getUserInput(int minValue, int maxValue) const;
	unsigned getPlayerBid();
	void calculateBids(unsigned bid);
};

