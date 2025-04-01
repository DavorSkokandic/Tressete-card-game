#pragma once
#include <vector>
#include "Cards.hpp"
#include "Deck.hpp"
#include "Game.hpp"

using namespace std;
class Player
{
public:
	Player();
	~Player();

	void PrintPlayerHand();
	void PlayCard();
	void DrawCard(Deck &deck);
	void AddCardToHand(Cards* card);
	Cards* GetLastPlayedCard() const;
	const std::vector<Cards*>& getHand() const { return hand; }
	void sortHand();

	

private:
	vector <Cards*> hand;
	Cards* lastPlayedCard;
};