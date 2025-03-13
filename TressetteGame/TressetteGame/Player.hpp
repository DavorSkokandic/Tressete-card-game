#pragma once
#include <vector>
#include "Cards.hpp"
#include "Deck.hpp"

using namespace std;
class Player
{
public:
	Player();
	~Player();

	void PrintPlayerHand();
	void PlayCard();
	void DrawCard(Deck &deck);
	

private:
	vector <Cards*> hand;
};