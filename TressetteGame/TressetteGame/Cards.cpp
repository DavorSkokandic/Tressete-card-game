#include <iostream>
#include "Cards.hpp"

using namespace std;

Cards::Cards(Rank rank, Suit suit)
{
	this->rank = rank;
	this->suit = suit;
}

Cards::~Cards()
{
}

Cards::Rank Cards::getRank() const
{
	return rank;
}

Cards::Suit Cards::getSuit() const
{
	return suit;
}

int Cards::getFaceValue()
{
	if(rank <= SEVEN)
	{
		return static_cast<int>(rank);
	}
	else if (rank == FANAT)
	{
		return 11;
	}
	else if (rank == HORSE)
	{
		return 12;
	}
	else if (rank == KING)
	{
		return 13;
	}
	return 1;
	
}

void Cards::PrintCard()
{	
	if (rank <= 7)
		cout << rank << " ";

	else if (rank == FANAT)
		cout << "Fanat" <<" ";

	else if (rank == HORSE)
		cout << "Horse"<<" ";

	else if (rank == KING)
		cout << "King"<<" ";

	else if (rank == ACE)
		cout << "Ace"<<" ";

	if (suit == COPPE)
		cout << "Coppe";

	else if (suit == SPADE)
		cout << "Spade";

	else if (suit == DENARI)
		cout << "Denari";

	else if (suit == BASTONI)
		cout << "Bastoni";
}
