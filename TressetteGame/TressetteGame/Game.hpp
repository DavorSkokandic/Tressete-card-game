#pragma once
#include <vector>
#include "Deck.hpp"
#include "Cards.hpp"
#include "Player.hpp"

class Player;

class Game
{
public:
	Game();
	~Game();


	void StartGame();
	void PlayRound();
	void DealCards();
	Player* EvaluateRound();
	void NextTurn();
	void DisplayScore();
	void UpdateScore(Player* roundWinner);
	Player* DetermineWinner();
	double CalculateCardPoints(Cards* card);
	
	

private:
	Deck deck;
	Player* player1;
	Player* player2;
	std::vector <Cards*> playedCards;
	Player* currentPlayer;
	double player1Score;
	double player2Score;
	int roundNumber;

};