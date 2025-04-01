#include "Game.hpp"
#include <vector>
#include <iostream>

class Player;

Game::Game()
{
	player1 = new Player();
	player2 = new Player();
	currentPlayer = player1; //player1 starts first
	player1Score = 0;
	player2Score = 0;
	roundNumber = 1;

	deck.Shuffle();
	DealCards();

}

Game::~Game()
{
	delete player1;
	delete player2;
	for (Cards* card : playedCards)
	{
		delete card;
	}
}

void Game::StartGame()
{
	vector<Cards*> hand = player2->getHand();
	
	for (int i = 0; i <20; i++)
	{
		PlayRound();
	}
	Player* winner = DetermineWinner();
	cout << "The winner is: " << (winner == player1 ? "Player 1" : "Player 2") << endl;
	cout << "Final score: " << endl;
	DisplayScore();

}

void Game::PlayRound()
{
	playedCards.clear();
	player1->sortHand();
	player2->sortHand();
	cout << "Round " << roundNumber << endl;
	cout << endl;
	
	cout << "Player 1 turn: " << endl;
	player1->PrintPlayerHand();
	player1->PlayCard();
	Cards* playedCard1 = player1->GetLastPlayedCard();
	cout << "Player 1 played: ";
	cout << endl;
	playedCard1->PrintCard();
	cout << endl;
	if (playedCard1)
	{
		playedCards.push_back(playedCard1);
	}
	cout << endl;
	cout << "Player 2 turn: " << endl;
	player2->PrintPlayerHand();
	bool hasMatchingSuit = false;

	// **Check if Player 2 has a card with the same suit as Player 1's played card**
	for (Cards* card : player2->getHand())
	{
		if (card->getSuit() == playedCard1->getSuit())
		{
			hasMatchingSuit = true;
			break;
		}
	}

	// **Player 2 must choose a valid card based on the rule**
	while (true)
	{
		player2->PlayCard();
		Cards* playedCard2 = player2->GetLastPlayedCard();

		// If Player 2 has a matching suit but didn't play it, ask them to choose again
		if (hasMatchingSuit && playedCard2->getSuit() != playedCard1->getSuit())
		{
			cout << "You have a card of the same suit as Player 1. You must play it!" << endl;
			player2->AddCardToHand(playedCard2); // Return the invalid card to hand
			player2->PrintPlayerHand();
			continue;
		}

		// Valid play
		cout << "Player 2 played: ";
		cout << endl;
		playedCard2->PrintCard();
		cout << endl;
		playedCards.push_back(playedCard2);
		break;
	}
	//Cards* playedCard2 = player2->GetLastPlayedCard();
	//cout << "Player 2 played: ";
	//playedCard2->PrintCard();
	//cout << endl;
	//if (playedCard2)
	//{
	//	playedCards.push_back(playedCard2);
	//}

	Player* roundWinner = EvaluateRound();
	DisplayScore();
	cout << "Round winner: " << (roundWinner == player1 ? "Player 1" : "Player 2") << endl;
	currentPlayer = roundWinner;

	if (roundNumber <= 10)
	{
		Cards* card1 = deck.DrawCard();
		player1->AddCardToHand(card1);
		if (card1)
		{
			cout << "Player 1 drew: ";
			card1->PrintCard();
			cout << endl;
		}

		Cards* card2 = deck.DrawCard();
		player2->AddCardToHand(card2);
		if (card2)
		{
			cout << "Player 2 drew: ";
			card2->PrintCard();
			cout << endl;
		}
	}

	roundNumber++;
}

Player* Game::EvaluateRound()
{
	if (playedCards.size() < 2)
	{
		return nullptr; // No winner if both players haven't played
	}

	Cards* firstCard = playedCards[0];
	Cards* secondCard = playedCards[1];

	// Strength values for different ranks
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


	int strength1 = getCardStrength(firstCard);
	int strength2 = getCardStrength(secondCard);

	Player* roundWinner = nullptr;

	// Check if player 2 played the same suit as player 1
	bool player2HasSameSuit = false;
	if (secondCard->getSuit() == firstCard->getSuit())
	{
		player2HasSameSuit = true;
	}

	// If player 2 did not play the same suit, player 1 wins
	if (!player2HasSameSuit)
	{
		roundWinner = player1;
		
	}

	// If both players played the same suit, compare strength
	else if (secondCard->getSuit() == firstCard->getSuit())
	{
		roundWinner = (strength1 > strength2) ? player1 : player2;
		(strength1 > strength2) ? player1 : player2;
	}
	else
	{
		roundWinner = currentPlayer;
		//return currentPlayer;
	}

	double roundPoints = 0.0;
	 for (Cards* card: playedCards)
	 {
		 roundPoints += CalculateCardPoints(card);
	 }
	 if(roundWinner == player1)
	 {
		 player1Score += roundPoints;
	 }
	 if (roundWinner == player2)
	 {
		 player2Score += roundPoints;
	 }
	 if(roundNumber == 18)
	 {
		 if (roundWinner == player1)
			 player1Score += 1;
		 else
			 player2Score += 1;
	 }
	 currentPlayer = roundWinner;

	 return roundWinner;
}

void Game::NextTurn()
{
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

void Game::DisplayScore()
{
	auto displayFraction = [](double score)
		{
			int whole = static_cast<int>(score);
			double decimal = score - whole;

			if (decimal == 0)
			{
				cout << whole << " ";
			}
			else if (decimal == 1.0/3.0)
			{
				cout << whole << " " << "1/3 ";
			}
			else if (decimal == 2.0 / 3.0)
			{
				cout << whole << " " << "2/3 ";
			}
			else
			{
				cout << score;
			}
	};
	cout << "Player 1 score: ";
	displayFraction(player1Score);
	cout << endl;
	cout << "Player 2 score: ";
	displayFraction(player2Score);
	cout << endl;
}

void Game::UpdateScore(Player* roundWinner)
{
	if (!roundWinner) 
	{
		cout << "No points awarded" << endl;
		return;
	}

	double roundPoints = 0.0;
	for (Cards* card : playedCards)
	{
		roundPoints += CalculateCardPoints(card);
	}

	if (roundWinner == player1)
	{
		player1Score += roundPoints;
	}
	else if (roundWinner == player2)
	{
		player2Score += roundPoints;
	}

	cout << "Updated score: " << endl;
	DisplayScore();

	// Add 1 extra point for the player who wins the last round
	if (roundNumber == 19)
	{
		if (roundWinner == player1)
			player1Score += 1;
		else
			player2Score += 1;
	}
}

Player* Game::DetermineWinner()
{
	return (player1Score > player2Score)? player1 : player2;
}

double Game::CalculateCardPoints(Cards* card)
{
	switch (card->getRank())
	{
	case Cards::ACE:   return 1.0;
	case Cards::THREE: return 1.0 / 3.0;
	case Cards::TWO:   return 1.0 / 3.0;
	case Cards::KING:  return 1.0 / 3.0;
	case Cards::HORSE: return 1.0 / 3.0;
	case Cards::FANAT: return 1.0 / 3.0;
	default: return 0.0;
	}
}



void Game::DealCards()
{
	for (int i = 0; i < 10; i++)
	{
		Cards* card1 = deck.DrawCard();
		Cards* card2 = deck.DrawCard();

		if (card1) 
		{
			player1->AddCardToHand(card1);
			cout << "Player 1 drew: ";
			card1->PrintCard();
			cout << endl;
		}
		if (card2)
		{
			player2->AddCardToHand(card2);
			cout << "Player 2 drew: ";
			card2->PrintCard();
			cout << endl;
		}
	}

}
