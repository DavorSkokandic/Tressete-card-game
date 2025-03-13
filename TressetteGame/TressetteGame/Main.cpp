#include <SFML/Graphics.hpp>
#include <iostream>
#include "Deck.hpp"
#include "Player.hpp"


int main()
{
	Deck deck;
	Cards* card;
	
	deck.PrintDeck();
	deck.Shuffle();
	deck.PrintDeck();

	Player player1;
	Player player2;

	for (int i = 0; i < 10; i++)
	{
		player1.DrawCard(deck);
		player2.DrawCard(deck);
	}
	
	player1.PrintPlayerHand();
	cout << endl;
	player2.PrintPlayerHand();
	cout << "Cards left in deck"<<endl;
	deck.PrintDeck();
	return 0;
}
