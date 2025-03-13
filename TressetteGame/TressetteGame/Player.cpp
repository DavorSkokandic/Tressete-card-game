#include "Player.hpp"
#include "Cards.hpp"
#include <iostream>

Player::Player()
{
	hand.reserve(10);
}

Player::~Player()
{
	for (Cards* card : hand)
	{
		delete card;
	}
}

void Player::PrintPlayerHand()
{
	cout << "Player hand: ";
	for (Cards* card : hand)
	{
		card->PrintCard();
		cout << endl;
	}
}


void Player::PlayCard()
{
}

void Player::DrawCard(Deck &deck)
{
	Cards* card = deck.DrawCard();
	if (card != nullptr)
	{
		hand.push_back(card);
	}
}
