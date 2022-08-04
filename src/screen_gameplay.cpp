/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include "card.h"
#include "deck.h"
#include "hand.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

// all the cards in the game
Deck cards;

// the deck of cards we can pull from
Stack DrawDeck{ 30, 20 };

// the cards we have pulled
Hand PlayerHand;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
	cards.Initialize();
	DrawDeck.FromDeck(cards);
	DrawDeck.Shuffle();
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        //finishScreen = 1;
        PlaySound(fxCoin);
    }
	

	bool handled = false;

	// check to see if we are dragging a card
	if (PlayerHand.SelectedCard != nullptr)
	{
		if (PlayerHand.SelectedCard->PointIn(GetMousePosition()))
		{
			if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				PlayerHand.SelectedCard->Position = Vector2Add(PlayerHand.SelectedCard->Position, GetMouseDelta());
			else
				PlayerHand.Deselect();
			handled = true;
		}
	}
	else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // check to see if we are selecting a card from the hand
	{
		for (Card* card : PlayerHand.Cards)
		{
			if (card->PointIn(GetMousePosition()))
			{
				// activate this card so we can start dragging it.
				PlayerHand.Select(card);
				break;
			}
		}
	}

	// check to see if we are interacting with the draw deck
	if (!handled)
	{
		Card* deckTop = DrawDeck.Top();
		if (deckTop != nullptr)
		{
			if (deckTop->PointIn(GetMousePosition()))
			{
				if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
				{
					// show the top card
					deckTop->FaceUp = true;
				}
				else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && PlayerHand.SelectedCard == nullptr)
				{
					// take the card into a hand and start dragging it.
					PlayerHand.AddCard(DrawDeck.PopTop());

					// always show the face of drawn cards
					PlayerHand.SelectedCard->FaceUp = true;
				}
			}
		}
	}
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    DrawTextEx(font, "GAMEPLAY SCREEN", Vector2{ 20, 10 }, font.baseSize*3.0f, 4, MAROON);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
	DrawDeck.Draw();
	PlayerHand.Draw();
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}