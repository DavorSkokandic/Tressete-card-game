#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "Cards.hpp"

class Deck
{

public:
	Deck();
	~Deck();

	void Shuffle();
	void PrintDeck();
	Cards* DrawCard();


private:
	std::vector<Cards*> deck;

};