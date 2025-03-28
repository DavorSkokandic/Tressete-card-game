#include "Player.hpp"
#include "Cards.hpp"
#include <iostream>
#include "Game.hpp"

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
	int cardIndex;
	Cards* card = nullptr;
	while (true) {
		cout << "Choose a card to play: ";

		cin >> cardIndex;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input choose again" << endl;
			continue;
		}
		if (cardIndex >= 0 && cardIndex < hand.size() )
		{
			lastPlayedCard = hand[cardIndex];
			hand.erase(hand.begin() + cardIndex);
			//cout << "Player played: ";
			lastPlayedCard->PrintCard();
			cout << endl;
			break;
			
		}
		else
		{
			cout << "Invalid card index choose again" << endl;

		}
	}
}

void Player::DrawCard(Deck &deck)
{
	Cards* card = deck.DrawCard();
	if (card != nullptr)
	{
		hand.push_back(card);
	}
}

void Player::AddCardToHand(Cards* card)
{
	hand.push_back(card);
}

Cards* Player::GetLastPlayedCard() const
{
	
	return lastPlayedCard;
}

 
