#ifndef HAND_H
#define HAND_H

#include "Card.h"

using namespace System;

using namespace System::Collections;

ref class Hand
{
public:
	// Constuctors
	Hand()
	{
		_cards = gcnew ArrayList();
	}

	Hand(ArrayList^ cards)
	{
		_cards = gcnew ArrayList(cards);
	}

	//Functions

	void arrangeHand()
	{
		ArrayList^ clubs;
		ArrayList^ diamonds;
		ArrayList^ hearts;
		ArrayList^ spades;

		Card^ tempCard;

		//sort the hand by suit
		for (int i = 0; i < _cards->Count; i++)
		{
			tempCard = safe_cast<Card^>(_cards[i]);

			if (tempCard->getCardName() == "Clubs")
			{
				clubs->Add(tempCard);
			}

			else if (tempCard->getCardName() == "Diamonds")
			{
				diamonds->Add(tempCard);
			}

			else if (tempCard->getCardName() == "Hearts")
			{
				hearts->Add(tempCard);
			}

			else if (tempCard->getCardName() == "Spades")
			{
				spades->Add(tempCard);
			}
		}
	}
		//sort the suits by value
	void clearHand()
	{
		_handSize = 0;
		_handValue = 0;
		_cards->Clear();
	}

	int getHandSize()
	{
		return _handSize;
	}

	int getHandValue()
	{
		return _handValue;
	}

	void setHandValue(int value)
	{
		_handValue = value;
	}

	//Declare + define overloaded operator
	void operator+= (Card^ card)
	{
		_cards->Add(card);
		_handSize++;
		_handValue += card->getCardValue();

	}
private:
	ArrayList^ _cards;
	int _handSize = 0;
	int _handValue = 0;

	void bubbleSort(ArrayList^ cards)
	{

		Card^ tempCard;
		Card^ rhCard;
		Card^ lhCard;
		bool switched;
		/*
		do

		swapped = false

		for i = 1 to numOfElements exclusive

		if leftElement > rightElement

		swap(leftElement, rightElement)

		swapped = true

		while swapped
		*/
		do
		{
			switched = false;

			for (int i = 0; i < cards->Count; i++)
			{
				lhCard =safe_cast<Card^>( cards[i]);
				
				if (i + 1 < cards->Count)
				{
					rhCard = safe_cast<Card^>(cards[i + 1]);
				}

				else
				{
					break;
				}

				if (lhCard->getCardValue() > rhCard->getCardValue())
				{
					tempCard = lhCard;
					lhCard = rhCard;
					rhCard = tempCard;

					switched = true;
				}
			}

		} while (switched);


	}

protected:
	
};



#endif // HAND_H
