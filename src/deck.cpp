#include "deck.h"
#include "card.h"
#include "raymath.h"
#include <vector>

Deck::Deck()
{
	Image img = GenImageChecked(100, 200, 25, 25, RED, MAROON);
	Texture cardBack = LoadTextureFromImage(img);
	UnloadImage(img);
	// build up 20 cards of each suit
	for (int i = 0; i < 20; i++)
	{
		Cards.emplace_back(Card{ Vector2Zero(),Card::CardSuit::Circle ,i + 1, false, cardBack });
		Cards.emplace_back(Card{ Vector2Zero(),Card::CardSuit::Square,i + 1, false, cardBack });
	}
}
