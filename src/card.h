#pragma once

#include "raylib.h"
#include "raymath.h"

class Card
{
public:
	Texture CardBack;
	enum class CardSuit
	{
		Circle,
		Square,
	};
	Vector2 Position;
	CardSuit Suit = CardSuit::Circle;
	int Value = 0;
	bool FaceUp = false;

	Card(Vector2 position, CardSuit suit, int value, bool faceUp, Texture& cardBack);
	Color GetCardColor();
	Rectangle GetScreenRect();
	void Draw();
	bool PointIn(const Vector2& pos);
	Texture* GetCardTexture();
};

