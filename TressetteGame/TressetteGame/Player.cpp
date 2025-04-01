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

void Player::sortHand()
{
	auto getCardStrength = [](Cards* card) -> int
		{
			switch (card->getRank())
			{
			case Cards::THREE: return 10;
			case Cards::TWO:   return 9;
			case Cards::ACE:   return 8;
			case Cards::KING:  return 7;
			case Cards::HORSE: return 6;
			case Cards::FANAT: return 5;
			case Cards::SEVEN: return 4;
			case Cards::SIX:   return 3;
			case Cards::FIVE:  return 2;
			case Cards::FOUR:  return 1;
			default: return 0;
			}
	};

	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j < 10; j++) 
		{
			hand[i]->getSuit();
			if (hand[i]->getSuit() < hand[j]->getSuit())
			{
				Cards* temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}
			else if (hand[i]->getSuit() == hand[j]->getSuit() && getCardStrength(hand[i]) > getCardStrength(hand[j]))
			{
				Cards* temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}	
			
		}
	}


}

 
