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
	
	for (int i = 0; i <19; i++)
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
	cout << "Round " << roundNumber << endl;
	
	cout << "Player 1 turn: " << endl;
	player1->PrintPlayerHand();
	player1->PlayCard();
	Cards* playedCard1 = player1->GetLastPlayedCard();
	cout << "Player 1 played: ";
	playedCard1->PrintCard();
	cout << endl;
	if (playedCard1)
	{
		playedCards.push_back(playedCard1);
	}

	cout << "Player 2 turn: " << endl;
	player2->PrintPlayerHand();
	player2->PlayCard();
	Cards* playedCard2 = player2->GetLastPlayedCard();
	cout << "Player 2 played: ";
	playedCard2->PrintCard();
	cout << endl;
	if (playedCard2)
	{
		playedCards.push_back(playedCard2);
	}

	Player* roundWinner = EvaluateRound();
	cout << "Round winner: " << (roundWinner == player1 ? "Player 1" : "Player 2") << endl;
	currentPlayer = roundWinner;

	if (roundNumber < 10)
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

	// Check if player 2 has the same suit as player 1
	bool player2HasSameSuit = false;
	for (Cards* card : player2->getHand())
	{
		if (card->getSuit() == firstCard->getSuit())
		{
			player2HasSameSuit = true;
			break;
		}
	}

	// If player 2 does not have the same suit, player 1 wins
	if (!player2HasSameSuit)
	{
		return player1;
	}

	// If both players played the same suit, compare strength
	if (secondCard->getSuit() == firstCard->getSuit())
	{
		return (strength1 > strength2) ? player1 : player2;
	}
	else
	{
		return currentPlayer;
	}
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
				cout << " " << "1/3 ";
			}
			else if (decimal == 2.0 / 3.0)
			{
				cout  << " " << "2/3 ";
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
	if (roundNumber == 20)
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
