#include <iostream>
#include <locale>
#include <io.h>
#include <fcntl.h>
#include "Game.h"
#include "IFormattable.h"
#include "DeckAdapter.h"
#include "DeckAdapter2.h"

void prettyPrint(const IFormattable& object);


int main()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	
	Game* game = new Game();
	game->run();

	delete game;

	//Deck* deck = new Deck(Deck::DeckType::SMALL_DECK);
	//IFormattable* iformattable = new DeckAdapter(*deck);
	//prettyPrint(*iformattable);

	//IFormattable* iformattable2 = new DeckAdapter2();
	//prettyPrint(*iformattable2);

	return 0;
}



void prettyPrint(const IFormattable& object)
{
	std::wcout << object.format();
}
