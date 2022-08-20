#pragma once
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Deck
{
public:
	vector<Card> Cards;

	Deck();
	~Deck();
	
	void Initialize();
};

