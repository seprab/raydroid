#include "Hand.h"

void Hand::AddCard(Card* card, bool selected)
{
	Cards.emplace_back(card);
	if (selected)
		Select(card);
}

void Hand::Select(Card* card)
{
	Deselect();
	if (card == nullptr)
		return;

	SelectedCard = card;

	// make it look like we picked up the card
	SelectedCard->Position.x -= 5;
	SelectedCard->Position.y -= 5;
}

void Hand::Deselect()
{
	if (SelectedCard != nullptr)
	{
		// make it look like we dropped the card
		SelectedCard->Position.x += 10;
		SelectedCard->Position.y += 10;
	}
	SelectedCard = nullptr;
}

void Hand::Draw()
{
	for (Card* card : Cards)
	{
		if (card != SelectedCard)
			card->Draw();
	}

	if (SelectedCard != nullptr)
	{
		// draw a shadow below the card
		Rectangle shadow = SelectedCard->GetScreenRect();
		shadow.x += 10;
		shadow.y += 10;

		DrawRectangleRec(shadow, ColorAlpha(BLACK, 0.5f));

		SelectedCard->Draw();
	}
}
