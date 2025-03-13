#include <SFML/Graphics.hpp>
#include <iostream>
#include "Deck.hpp"



int main()
{
	Deck deck;
	
	deck.Shuffle();
	deck.PrintDeck();
	return 0;
}
