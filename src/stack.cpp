#include "stack.h"

void Stack::FromDeck(Deck& deck)
{
	Cards.clear();
	for (auto& card : deck.Cards)
		Cards.push_back(&card);
}

void Stack::Swap(size_t a, size_t b)
{
	Card* t = Cards[a];
	Cards[a] = Cards[b];
	Cards[b] = t;
}

void Stack::Shuffle(size_t factor)
{
	size_t count = Cards.size() * factor;

	for (size_t i = 0; i < count; i++)
	{
		size_t a = (size_t)GetRandomValue(0, (int)Cards.size() - 1);
		size_t b = (size_t)GetRandomValue(0, (int)Cards.size() - 1);

		Swap(a, b);
	}
}

Card* Stack::Top()
{
	Card* topCard = nullptr;
	if (!Cards.empty())
		topCard = Cards[Cards.size() - 1];

	return topCard;
}

Card* Stack::PopTop()
{
	if (Cards.empty())
		return nullptr;

	Card* topCard = Cards[Cards.size() - 1];
	Cards.erase(Cards.begin() + (Cards.size() - 1));

	return topCard;
}

void Stack::Draw()
{
	Rectangle baseRect = Rectangle{ Pos.x,Pos.y, (float)CardBack.width, (float)CardBack.height };

	// draw a gray rectangle where this stack is
	DrawRectangleRec(baseRect, DARKGRAY);


	// draw a fake 'card' for every 10 cards in the stack
	int stackHeight = (int)Cards.size() / 10;
	stackHeight *= 3;

	for (int i = 3; i < stackHeight; i += 3)
	{
		baseRect.x -= 3;
		baseRect.y -= 3;
		DrawRectangleRec(baseRect, (i % 6) == 0 ? DARKGRAY : GRAY);
	}

	// draw the top card
	Card* topCard = Top();

	if (topCard != nullptr)
	{
		topCard->Position.x = baseRect.x - 3;
		topCard->Position.y = baseRect.y - 3;
		topCard->Draw();
	}
}
