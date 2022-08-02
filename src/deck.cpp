#include "deck.h"
#include "card.h"
#include "raymath.h"
#include <vector>

Deck::Deck()
{
	// build up 20 cards of each suit
	for (int i = 0; i < 20; i++)
	{
		Cards.emplace_back(Card{ Vector2Zero(),Card::CardSuit::Circle ,i + 1, false });
		Cards.emplace_back(Card{ Vector2Zero(),Card::CardSuit::Square,i + 1, false });
	}
}
