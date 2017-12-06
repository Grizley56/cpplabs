#include "Game.h"
#include <iostream>
#include "BustException.h"


Game::Game(Deck::DeckType type): _isGameRunning(true)
{
	_dealer = new Dealer();
	_player = new Player();

	_shoe = new Shoe(4, type);
}

Game::~Game()
{
	delete[] _tmp_action_input;
}

int Game::getUserInput(int minValue, int maxValue) const
{
	int action;
	while (true)
	{
		std::wcout << "You choise: ";
		std::wcin.getline(_tmp_action_input, 3);
		action = _wtoi(_tmp_action_input);
		if (action >= minValue && action <= maxValue)
			break;
	}

	return action;
}

unsigned Game::getPlayerBid()
{
	wchar_t bid[6];

	while(true)
	{
		std::wcout << "Enter your bid: ";
		std::wcin.getline(bid, 6);

		int result = _wtoi(bid);

		if (result <= 0)
		{
			std::wcout << "bid must be more than 0. Please, enter bid again." << std::endl;
			continue;
		}
		if(result > _player->getTotalMoney())
		{
			std::wcout << "Entered bid more than your total " 
								 << "(" <<_player->getTotalMoney() << ")" 
								 << ". Please, enter bid again." 
								 << std::endl;
			continue;
		}

		_player->pay(-result);
		return result;
	}
}

void Game::run()
{
	std::wcout << "Game is start" << std::endl;
	_isGameRunning = true;

	while(_isGameRunning)
	{
		if (_player->getTotalMoney() == 0)
		{
			std::wcout << "You lost all money!" << std::endl;
			_isGameRunning = false;
			break;
		}

		std::wcout << "Your total cash " << _player->getTotalMoney() << std::endl;

		unsigned bid = getPlayerBid();

		std::wcout << "Your bid is " << bid << std::endl;

		_shoe->shuffle();
		_player->clearHands();
		_dealer->clearHand();

		for(size_t i = 0; i < 2; ++i)
		{
			_player->getHand().addCard(_shoe->getCard());
			_dealer->getHand().addCard(_shoe->getCard());
		}

		bool playerInGame = true;

		if (checkForInstaBlackJack(bid))
			continue;

		while(playerInGame)
		{
			for(size_t i = 0; i < _player->handsCount(); ++i)
			{
				Hand& currentHand = _player->getHand(i);

				if (currentHand.getStand() || currentHand.isBust() || currentHand.cardsCount() > 5)
					continue;

				printDecks();
				printHands();

				int maxActions = currentHand.canSplit() ? 3 : 2;

				if (_player->handSplitted())
					std::wcout << "---Action for hand #" << std::to_wstring(i + 1) << "---" << std::endl;


				std::wcout << "1: Hit" << std::endl;
				std::wcout << "2. Stand" << std::endl;

				if (maxActions == 3 && _player->getTotalMoney() >= bid) 
					std::wcout << "3. Split" << std::endl;

				int action = getUserInput(0, maxActions);

				switch (action)
				{
					case 1:
						try {
							currentHand.addCard(_shoe->getCard());
						} catch(BustException) {
							std::wcout << "Hand # " << i + 1 << " is bust! ( " << currentHand << ")" << std::endl;
						}
						break;
					case 2:
						currentHand.setStand(true);
						break;
					case 3:
						_player->splitHand(i);
						_player->pay(-bid);
						i--;
						break;
				}
			}

			if (_player->allHandsStand())
				playerInGame = false;

			std::wcout << std::endl;
		}

		calculateBids(bid);
	}
}

void Game::printDecks()
{
	std::wcout << "Decks:";
	for (size_t i = 0; i < _shoe->getDecksCount(); ++i)
		std::wcout << L" [" << _shoe->getDeck(i)->cardsCount() << L']';
	std::wcout << std::endl;
}

void Game::printHands()
{
	std::wcout << L"---------------------------" << std::endl;
	std::wcout << "Dealer: " << *_dealer << std::endl;
	std::wcout << "You: " << *_player << std::endl;
}

bool Game::checkForInstaBlackJack(int playerBid)
{

	if (_player->getHand(0).isBlackJack())
	{
		printHands();

		int x1_5 = playerBid + playerBid * 1.5;
		int x1 = playerBid * 2;

		_dealer->setCardVisible(true);

		if ((*_dealer->getHand().begin())->getName() == L"A") // visible card is ACE
		{
			std::wcout << "1. Pay out at 1:1" << std::endl;
			std::wcout << "2. Try to get 3:2" << std::endl;

			int action = getUserInput(1, 2);

			std::wcout << "Dealer: " << *_dealer << std::endl;

			if (action == 1)
			{
				std::wcout << "Congrats! you won " << playerBid << "$" << std::endl;
				_player->pay(x1);
			}
			else
			{
				if (_dealer->getHand().isBlackJack())
					std::wcout << "Dealer has Black Jack! You lose!" << std::endl;
				else
				{
					std::wcout << "Congrats! you won " << playerBid * 1.5 << std::endl;
					_player->pay(x1_5);
				}
			}
		}
		else
		{
			if (_dealer->getHand().isBlackJack())
			{
				std::wcout << *_dealer << std::endl << "Dealer has Black Jack!" << std::endl;
				std::wcout << "You have not lost anything" << std::endl;
			}
			else
			{
				std::wcout << "Congratz! You won " << playerBid * 1.5 << "$" << std::endl;
				_player->pay(x1_5);
			}
		}

		return true;
	}

	if (_dealer->getHand().isBlackJack())
	{
		std::wcout << "Dealer has Black Jack! " << *_dealer << std::endl;
		std::wcout << "You lose!" << std::endl;
		return true;
	}


	_dealer->setCardVisible(false);
	return false;
}

void Game::calculateBids(unsigned bid)
{
	Hand& dealerHand = _dealer->getHand();

	while (dealerHand.totalValue() < 17)
		try {
			dealerHand.addCard(_shoe->getCard());
		} catch(BustException e) {
			break;
		}

	_dealer->setCardVisible(true);

	std::wcout << "----------RESULTS----------" << std::endl;
	std::wcout << "Dealer: " << *_dealer << std::endl;

	for (auto hand : _player->getHands())
	{
		if (hand->isBust() || (!dealerHand.isBust() && hand->totalValue() < dealerHand.totalValue()))
			std::wcout << "You lose your bid with hand " << *hand << std::endl;
		else if (dealerHand.isBust() || hand->totalValue() > dealerHand.totalValue())
		{
			std::wcout << "Hand " << *hand << " won " << bid << "$" << std::endl;
			_player->pay(bid * 2);
		}
		else
		{
			std::wcout << "Hand " << *hand << "is push!" << std::endl;
			_player->pay(bid);
		}
	}
}