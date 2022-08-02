#pragma once

#include "vector"
#include "card.h"
#include "deck.h"

// a stack of card pointers, used for things like draw decks and things that draw as card stack.
class Stack
{
public:
	// where the stack origin is on screen
	Vector2 Pos = { 0 };
	std::vector<Card*> Cards;

	void FromDeck(Deck& deck);

	// swaps the location of two cards
	void Swap(size_t a, size_t b);

	// swaps random cards for factor * card count to try and shuffle the stack.
	void Shuffle(size_t factor = 4);

	Card* Top();
	Card* PopTop();
	void Draw();
};

