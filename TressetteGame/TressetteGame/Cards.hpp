#pragma once

class Cards 
{
public:
	enum Suit { COPPE = 1, SPADE, DENARI, BASTONI };
	enum Rank { TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, FANAT, HORSE, KING, ACE };

	Cards(Rank rank, Suit suit);
	virtual ~Cards();

	Rank getRank() const;
	Suit getSuit() const;

	virtual int getFaceValue();

	void PrintCard();

private:
	Rank rank;
	Suit suit;
};