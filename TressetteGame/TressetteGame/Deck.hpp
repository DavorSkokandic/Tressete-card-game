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



private:
	std::vector<Cards*> deck;

};