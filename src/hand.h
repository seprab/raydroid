#pragma once
#include "stack.h"
#include <list>

class Hand : public Stack
{
public:
	std::list<Card*> Cards;

	Card* SelectedCard = nullptr;

	void AddCard(Card* card, bool selected = true);

	void Select(Card* card);

	void Deselect();

	void Draw();
};

