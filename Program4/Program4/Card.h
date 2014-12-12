#ifndef CARD_H
#define CARD_H

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class Card
{
public:

	// Constructors

	Card() //Default
	{
		_cardName = "default";
		_cardSuit = "default";
		_cardValue = -1;
		_cardImageList = -1;
	}

	Card(String^ cardName, String^ cardSuit, int cardValue, int cardImageList)
	{
		_cardName = cardName;
		_cardSuit = cardSuit;
		_cardValue = cardValue;
		_cardImageList = cardImageList;
	}


	//get & set

	String^ getCardName()
	{
		return _cardName;
	}

	String^ getCardSuit()
	{
		return _cardSuit;
	}

	int getCardValue()
	{
		return _cardValue;
	}

	int getCardImageList()
	{
		return _cardImageList;
	}

	void setCardName(String^ cardName)
	{
		_cardName = cardName;
	}

	void setCardSuit(String^ cardSuit)
	{
		_cardSuit = cardSuit;
	}

	void setCardValue(int cardValue)
	{
		_cardValue = cardValue;
	}

	void setCardImageList(int cardImageList)
	{
		_cardImageList = cardImageList;
	}

	//declare overloaded operator
	int operator+(Card^ secondCard);
	//functions
	void displayCard(PictureBox^ cardImage, Label^ cardLabel, ImageList^ imageListCards,Point^ location)
	{
		// Picture Box

		cardImage->BackColor = System::Drawing::Color::Transparent;
		cardImage->Size = System::Drawing::Size(125, 183);
		cardImage->TabIndex = 4;
		cardImage->TabStop = false;
		cardImage->Visible = true;
		cardImage->Image = imageListCards->Images[_cardImageList];

		cardImage->SizeMode = PictureBoxSizeMode::StretchImage;

		cardImage->BringToFront();

		// Label

		cardLabel->AutoSize = false;
		cardLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		cardLabel->ForeColor = System::Drawing::Color::White;
		cardLabel->Location = System::Drawing::Point(location->X, location->Y + 183);
		cardLabel->Size = System::Drawing::Size(125, 33);
		cardLabel->TabIndex = 3;
		cardLabel->Text = _cardName + " of " + _cardSuit + " (" + _cardValue.ToString() + ")";
		cardLabel->TextAlign = ContentAlignment::MiddleCenter;
		cardLabel->Visible = true;
		cardLabel->BringToFront();
	}


private:
	String^ _cardName;
	String^ _cardSuit;
	int _cardValue;
	int _cardImageList;

protected:

};

// define overloaded operator
int Card::operator+(Card^ secondCard)
{
	return _cardValue + secondCard->_cardValue;
}

#endif // CARD_H