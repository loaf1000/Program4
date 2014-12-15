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
		bubbleSort(_cards);
		
	}
	void clearHand()
	{
		_handSize = 0;
		_handValue = 0;
		_cards->Clear();
	}

	void calcHandValue()
	{
		Card^ tempCard = gcnew Card();
		_handValue = 0;
		for (int i = 0; i < _cards->Count; i++)
		{
			tempCard =safe_cast<Card^> (_cards[i]);
			_handValue += tempCard->getCardValue();
		}
	}

	ArrayList^ getCards()
	{
		return _cards;
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

	void setHandSize(int value)
	{
		_handSize = value;
	}

	void setCards(ArrayList^ cards)
	{
		_cards = gcnew ArrayList(cards);
		_handSize = cards->Count;
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

		Card^ tempCard = gcnew Card();
		Card^ rhCard = gcnew Card();
		Card^ lhCard = gcnew Card();
		bool switched;
		/*
		do                                   from http://visualgo.net/

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
			
			for (int i = 1; i < cards->Count; i++)
			{
				lhCard =safe_cast<Card^>( cards[i-1]);
				
				rhCard = safe_cast<Card^>(cards[i]);

					if (lhCard->getCardImageList() > rhCard->getCardImageList())
					{
						tempCard = lhCard;
						cards[i - 1] = cards[i];
						cards[i] = tempCard;

						switched = true;
					}
					//MessageBox::Show(switched.ToString(), "True/False");
			}
				

		} while (switched);


	}

protected:
	
};



#endif // HAND_H
