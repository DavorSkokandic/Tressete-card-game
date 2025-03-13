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


private:
	std::vector<Cards*> deck;

};