#include "card.h"

Color Card::GetCardColor()
{
	switch (Suit)
	{
	case Card::CardSuit::Circle:
		return RED;
	case Card::CardSuit::Square:
		return BLUE;
	default:
		return BLACK;
	}
}
Rectangle Card::GetScreenRect()
{
	return Rectangle
	{ 
		Position.x,
		Position.y,
		static_cast<float>(CardBack.width),
		static_cast<float>(CardBack.height)
	};
}
void Card::Draw()
{
	if (FaceUp)
	{
		// draw the card face with an outline
		Rectangle baseRect = Rectangle
		{
			Position.x - 1,
			Position.y - 1,
			static_cast<float>(CardBack.width + 2),
			static_cast<float>(CardBack.height + 2)
		};
		DrawRectangleRec(baseRect, BLACK);
		DrawRectangleRec(GetScreenRect(), RAYWHITE);

		Vector2 center = 
		{
			Position.x + CardBack.width / 2,
			Position.y + CardBack.height / 2
		};

		DrawText(
			TextFormat("%d", Value),
			static_cast<int>(center.x),
			static_cast<int>(center.y) + 55,
			40,
			GetCardColor());

		switch (Suit)
		{
		case CardSuit::Circle:
			DrawCircle(
				static_cast<int>(center.x),
				static_cast<int>(center.y) - 40,
				40,
				GetCardColor());
			break;
		case CardSuit::Square:
			DrawRectangle(
				static_cast<int>(center.x - 20),
				static_cast<int>(center.y) - 60,
				40,
				40,
				GetCardColor());
			break;
		}
	}
	else
	{
		// draw the card back
		DrawTexture(
			CardBack,
			static_cast<int>(Position.x),
			static_cast<int>(Position.y),
			WHITE);
	}
}
bool Card::PointIn(const Vector2& pos)
{
    return false;
}