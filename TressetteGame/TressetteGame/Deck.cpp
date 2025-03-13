#include "Deck.hpp"
#include <iostream>

using namespace std;

Deck::Deck()
{
	deck.reserve(40);

	for (Cards::Rank r = Cards::TWO; r <= Cards::ACE; r = static_cast<Cards::Rank>(static_cast<int>(r)+1) ) 
	{
		for (Cards::Suit s = Cards::COPPE;s <= Cards::BASTONI; s = static_cast<Cards::Suit>(static_cast<int>(s) + 1))
		{
			deck.push_back(new Cards(r, s));
			Cards* card = new Cards(r, s);
			card->PrintCard();
		}
	}
}

Deck::~Deck()
{
	for (Cards* card : deck)
	{
		delete card;
	}
}
