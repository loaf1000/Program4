
/**************************************************************
***************************************************************
***************************************************************

ID INFORMATION

Programmers		        :Laithe Marshall
Assignment #		    :Final Project
Assignment Name		    :Black Jack - The Big Deal
Course # and Title		:CISC 192 - C++
Class Meeting Time		:MW 9:35 - 12:45
Instructor			    :Professor Forman
Hours			        :60
Difficulty			    :6
Completion Date		    :December/15/2014
Project Name		    :Program4

***************************************************************
***************************************************************
CUSTOM DEFINED FUNCTIONS
addCardToHand
arrangeHand
blackJack
bust
cleanup
clearScreenTester
credits
dealCard
dealHand
dealerAceChange
dealerHit
debugDecks
displayCardandValue
displayCardTotal
displayDealerStrategy
displayDeck
displayFarewellMessage
displayGameResults
displayGameStats
getCardValue
getHandTypes
initializePointArrays
loadDeck
quit
setupDeckBySuit
setupDeckByValue
storeDeck
shuffleDeck
shuffleRandomSwap
updateBank
validAccount

***************************************************************
***************************************************************
EVENT-DRIVEN FUNCTIONS

buttonCredits_Click
buttonDisplayDeck_Click
buttonHelp_Click
buttonHistory_Click
buttonHit_Click
buttonLogin_Click
buttonQuit_Click
buttonPlay_Click
buttonResults_Click
buttonStay_Click
buttonTest_Click
dealerCard_MouseEnter
dealerCard_MouseLeave
MyForm_Load
playerCard_MouseEnter
playerCard_MouseLeave
testerCard_MouseEnter
testerCard_MouseLeave
timerCardAnimation_Tick
timerDateTime_Tick
***************************************************************
***************************************************************
PROGRAM DESCRIPTION
The program welcomes the user to the Black Jack "table" and asks
the user to log in with account # and password. The user will then be given a bank roll of 
$100 to play black jack. When the user hits play, they bet $10
to play a hand of Black Jack. The user has the option to hit or stay,
and plays against the dealer. The user gains $20 if they win, $30 if they
Black Jack, and $10 if they tie. If the user runs out of money they will
be forced to quit the program. The user may click on the help button
for detailed instructions of how to play & how to use the program.
The credits button will display credits.The Results button displays
statistics based on the hands of Black Jack played. The Quit button
will exit the program after giving the user a farewell message. 


***************************************************************
***************************************************************

CREDITS

Acknowledge those who helped you and whom you helped
Remember the “triangle of learning”

Thanks for assistance and inspiration from:

Thanks to Professor Forman for creating TDHOs.
http://visualgo.net/ for bubble sorting help
Thanks for the opportunity to assist and inspire:

N/A

***************************************************************
***************************************************************

MEDIA

Images & Icons

Queen of Diamonds
http://s12.photobucket.com/user/yanzai03/media/AQ.jpg.html
Face cards and Aces
http://playingcardcollector.net/2013/05/02/fullmetal-alchemist-playing-cards/
FMA everyone (exit background)
http://imgdonkey.com/big/N01ZNEZGbg/all-right-imgur-lets-rustle-some-jimmies-which-is-better.gif
Transmutation Circle
http://fc01.deviantart.net/fs42/f/2009/067/c/c/Transmutation_Circle_by_Wojtas19.png
Anime shuffle
http://media.giphy.com/media/7sRMjntXYEITu/giphy.gif
Face Value Cards
http://ardisoft.net/svg-z-cards/screenshot.png
FMA Icon
http://fc04.deviantart.net/fs70/f/2012/274/3/1/fma_icon_2_by_iloveyoukisshu-d5gfxgm.gif

Music

Let it Out by Fukuhara Miho TV edit (exit song)
http://thepiratebay.se/torrent/8206483/Fullmetal_Alchemist__Brotherhood_Soundtrack_Collection

Lapis Philosophorum Chant Composed by Senju Akira
http://thepiratebay.se/torrent/8206483/Fullmetal_Alchemist__Brotherhood_Soundtrack_Collection

***************************************************************
***************************************************************
**************************************************************/

#pragma once

namespace Program2{

#include "Card.h"
#include "Hand.h"
#include "GameResult.h"


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		value class AccountType
		{
		public:
			String^ accountNumber;
			String^ password;
			String^ firstName;
			String^ lastName;
		};

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ImageList^  imageListCards;
	private: System::Windows::Forms::PictureBox^  pictureBoxGif;
	private: System::Windows::Forms::PictureBox^  pictureBoxAlignment;
	private: System::Windows::Forms::Label^  labelTitle;
	private: System::Windows::Forms::Timer^  timerDateTime;
	private: System::Windows::Forms::Label^  labelDateTime;
	private: System::Windows::Forms::PictureBox^  pictureBoxCardAnimation1;
	private: System::Windows::Forms::PictureBox^  pictureBoxCardAnimation2;


	private: System::Windows::Forms::Timer^  timerCardAnimation;
	private: System::Windows::Forms::TextBox^  textBoxLogin;

	private: System::Windows::Forms::Label^  labelDescription;

	private: System::Windows::Forms::Button^  buttonLogin;
	private: System::Windows::Forms::Button^  buttonHelp;

	private: System::Windows::Forms::Button^  buttonQuit;
	private: System::Windows::Forms::Button^  buttonCredits;
	private: System::Windows::Forms::Button^  buttonPlay;
	private: System::Windows::Forms::Button^  buttonHit;
	private: System::Windows::Forms::Button^  buttonStay;
	private: System::Windows::Forms::Label^  labelPlayerTotal;

	private: System::Windows::Forms::Label^  labelDealerTotal;
	private: System::Windows::Forms::Button^  buttonResults;
	private: System::Windows::Forms::Label^  labelGameNumber;
	private: System::Windows::Forms::ComboBox^  comboBoxCheat;
	private: System::Windows::Forms::Label^  labelBank;
	private: System::Windows::Forms::TextBox^  textBoxPassword;
	private: System::Windows::Forms::ComboBox^  comboBoxTestFunctions;
	private: System::Windows::Forms::Button^  buttonTest;
	private: System::Windows::Forms::Button^  buttonDisplayDeck;
	private: System::Windows::Forms::Label^  labelPassword;
	private: System::Windows::Forms::Label^  labelAccountNumber;
	private: System::Windows::Forms::Button^  buttonHistory;

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->imageListCards = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBoxGif = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAlignment = (gcnew System::Windows::Forms::PictureBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->timerDateTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelDateTime = (gcnew System::Windows::Forms::Label());
			this->pictureBoxCardAnimation1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxCardAnimation2 = (gcnew System::Windows::Forms::PictureBox());
			this->timerCardAnimation = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->labelDescription = (gcnew System::Windows::Forms::Label());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			this->buttonQuit = (gcnew System::Windows::Forms::Button());
			this->buttonCredits = (gcnew System::Windows::Forms::Button());
			this->buttonPlay = (gcnew System::Windows::Forms::Button());
			this->buttonHit = (gcnew System::Windows::Forms::Button());
			this->buttonStay = (gcnew System::Windows::Forms::Button());
			this->labelPlayerTotal = (gcnew System::Windows::Forms::Label());
			this->labelDealerTotal = (gcnew System::Windows::Forms::Label());
			this->buttonResults = (gcnew System::Windows::Forms::Button());
			this->labelGameNumber = (gcnew System::Windows::Forms::Label());
			this->comboBoxCheat = (gcnew System::Windows::Forms::ComboBox());
			this->labelBank = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxTestFunctions = (gcnew System::Windows::Forms::ComboBox());
			this->buttonTest = (gcnew System::Windows::Forms::Button());
			this->buttonDisplayDeck = (gcnew System::Windows::Forms::Button());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
			this->buttonHistory = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGif))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAlignment))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCardAnimation1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCardAnimation2))->BeginInit();
			this->SuspendLayout();
			// 
			// imageListCards
			// 
			this->imageListCards->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageListCards.ImageStream")));
			this->imageListCards->TransparentColor = System::Drawing::Color::Transparent;
			this->imageListCards->Images->SetKeyName(0, L"fullmetal_alchemist_playing_cards_the_ace_of_clubs.jpg");
			this->imageListCards->Images->SetKeyName(1, L"2c.png");
			this->imageListCards->Images->SetKeyName(2, L"3c.png");
			this->imageListCards->Images->SetKeyName(3, L"4c.png");
			this->imageListCards->Images->SetKeyName(4, L"5c.png");
			this->imageListCards->Images->SetKeyName(5, L"6c.png");
			this->imageListCards->Images->SetKeyName(6, L"7c.png");
			this->imageListCards->Images->SetKeyName(7, L"8c.png");
			this->imageListCards->Images->SetKeyName(8, L"9c.png");
			this->imageListCards->Images->SetKeyName(9, L"10c.png");
			this->imageListCards->Images->SetKeyName(10, L"fullmetal_alchemist_playing_cards_the_jack_of_clubs.jpg");
			this->imageListCards->Images->SetKeyName(11, L"fullmetal_alchemist_playing_cards_the_queen_of_clubs.jpg");
			this->imageListCards->Images->SetKeyName(12, L"fullmetal_alchemist_playing_cards_the_king_of_clubs.jpg");
			this->imageListCards->Images->SetKeyName(13, L"fullmetal_alchemist_playing_cards_the_ace_of_diamonds.jpg");
			this->imageListCards->Images->SetKeyName(14, L"2d.png");
			this->imageListCards->Images->SetKeyName(15, L"3d.png");
			this->imageListCards->Images->SetKeyName(16, L"4d.png");
			this->imageListCards->Images->SetKeyName(17, L"5d.png");
			this->imageListCards->Images->SetKeyName(18, L"6d.png");
			this->imageListCards->Images->SetKeyName(19, L"7d.png");
			this->imageListCards->Images->SetKeyName(20, L"8d.png");
			this->imageListCards->Images->SetKeyName(21, L"9d.png");
			this->imageListCards->Images->SetKeyName(22, L"10d.png");
			this->imageListCards->Images->SetKeyName(23, L"fullmetal_alchemist_playing_cards_the_jack_of_diamonds.jpg");
			this->imageListCards->Images->SetKeyName(24, L"QD-lanczos3.jpg");
			this->imageListCards->Images->SetKeyName(25, L"fullmetal_alchemist_playing_cards_the_king_of_diamonds.jpg");
			this->imageListCards->Images->SetKeyName(26, L"fullmetal_alchemist_playing_cards_the_ace_of_hearts.jpg");
			this->imageListCards->Images->SetKeyName(27, L"2h.png");
			this->imageListCards->Images->SetKeyName(28, L"3h.png");
			this->imageListCards->Images->SetKeyName(29, L"4h.png");
			this->imageListCards->Images->SetKeyName(30, L"5h.png");
			this->imageListCards->Images->SetKeyName(31, L"6h.png");
			this->imageListCards->Images->SetKeyName(32, L"7h.png");
			this->imageListCards->Images->SetKeyName(33, L"8h.png");
			this->imageListCards->Images->SetKeyName(34, L"9h.png");
			this->imageListCards->Images->SetKeyName(35, L"10h.png");
			this->imageListCards->Images->SetKeyName(36, L"fullmetal_alchemist_playing_cards_the_jack_of_hearts.jpg");
			this->imageListCards->Images->SetKeyName(37, L"fullmetal_alchemist_playing_cards_the_queen_of_hearts.jpg");
			this->imageListCards->Images->SetKeyName(38, L"fullmetal_alchemist_playing_cards_the_king_of_hearts.jpg");
			this->imageListCards->Images->SetKeyName(39, L"fullmetal_alchemist_playing_cards_the_ace_of_spades.jpg");
			this->imageListCards->Images->SetKeyName(40, L"2s.png");
			this->imageListCards->Images->SetKeyName(41, L"3s.png");
			this->imageListCards->Images->SetKeyName(42, L"4s.png");
			this->imageListCards->Images->SetKeyName(43, L"5s.png");
			this->imageListCards->Images->SetKeyName(44, L"6s.png");
			this->imageListCards->Images->SetKeyName(45, L"7s.png");
			this->imageListCards->Images->SetKeyName(46, L"8s.png");
			this->imageListCards->Images->SetKeyName(47, L"9s.png");
			this->imageListCards->Images->SetKeyName(48, L"10s.png");
			this->imageListCards->Images->SetKeyName(49, L"fullmetal_alchemist_playing_cards_the_jack_of_spades.jpg");
			this->imageListCards->Images->SetKeyName(50, L"fullmetal_alchemist_playing_cards_the_queen_of_spades.jpg");
			this->imageListCards->Images->SetKeyName(51, L"fullmetal_alchemist_playing_cards_the_king_of_spades.jpg");
			// 
			// pictureBoxGif
			// 
			this->pictureBoxGif->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxGif.Image")));
			this->pictureBoxGif->Location = System::Drawing::Point(429, 298);
			this->pictureBoxGif->Name = L"pictureBoxGif";
			this->pictureBoxGif->Size = System::Drawing::Size(150, 150);
			this->pictureBoxGif->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxGif->TabIndex = 0;
			this->pictureBoxGif->TabStop = false;
			// 
			// pictureBoxAlignment
			// 
			this->pictureBoxAlignment->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxAlignment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxAlignment->Location = System::Drawing::Point(0, 0);
			this->pictureBoxAlignment->Name = L"pictureBoxAlignment";
			this->pictureBoxAlignment->Size = System::Drawing::Size(1008, 730);
			this->pictureBoxAlignment->TabIndex = 1;
			this->pictureBoxAlignment->TabStop = false;
			this->pictureBoxAlignment->Visible = false;
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->ForeColor = System::Drawing::Color::White;
			this->labelTitle->Location = System::Drawing::Point(287, 9);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(434, 35);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Welcome to Laithe\'s Blackjack Table";
			// 
			// timerDateTime
			// 
			this->timerDateTime->Enabled = true;
			this->timerDateTime->Interval = 1000;
			this->timerDateTime->Tick += gcnew System::EventHandler(this, &MyForm::timerDateTime_Tick);
			// 
			// labelDateTime
			// 
			this->labelDateTime->AutoSize = true;
			this->labelDateTime->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDateTime->ForeColor = System::Drawing::Color::White;
			this->labelDateTime->Location = System::Drawing::Point(355, 685);
			this->labelDateTime->Name = L"labelDateTime";
			this->labelDateTime->Size = System::Drawing::Size(298, 33);
			this->labelDateTime->TabIndex = 3;
			this->labelDateTime->Text = L"11/17/2014 12:25:36 PM";
			this->labelDateTime->Visible = false;
			// 
			// pictureBoxCardAnimation1
			// 
			this->pictureBoxCardAnimation1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxCardAnimation1->Location = System::Drawing::Point(294, 298);
			this->pictureBoxCardAnimation1->Name = L"pictureBoxCardAnimation1";
			this->pictureBoxCardAnimation1->Size = System::Drawing::Size(125, 183);
			this->pictureBoxCardAnimation1->TabIndex = 4;
			this->pictureBoxCardAnimation1->TabStop = false;
			this->pictureBoxCardAnimation1->Visible = false;
			// 
			// pictureBoxCardAnimation2
			// 
			this->pictureBoxCardAnimation2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxCardAnimation2->Location = System::Drawing::Point(595, 298);
			this->pictureBoxCardAnimation2->Name = L"pictureBoxCardAnimation2";
			this->pictureBoxCardAnimation2->Size = System::Drawing::Size(125, 183);
			this->pictureBoxCardAnimation2->TabIndex = 5;
			this->pictureBoxCardAnimation2->TabStop = false;
			this->pictureBoxCardAnimation2->Visible = false;
			// 
			// timerCardAnimation
			// 
			this->timerCardAnimation->Enabled = true;
			this->timerCardAnimation->Interval = 600;
			this->timerCardAnimation->Tick += gcnew System::EventHandler(this, &MyForm::timerCardAnimation_Tick);
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxLogin->Location = System::Drawing::Point(429, 129);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(150, 26);
			this->textBoxLogin->TabIndex = 6;
			this->textBoxLogin->Text = L"Account # (1234)";
			// 
			// labelDescription
			// 
			this->labelDescription->AutoSize = true;
			this->labelDescription->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDescription->ForeColor = System::Drawing::Color::White;
			this->labelDescription->Location = System::Drawing::Point(192, 62);
			this->labelDescription->MaximumSize = System::Drawing::Size(1008, 0);
			this->labelDescription->Name = L"labelDescription";
			this->labelDescription->Size = System::Drawing::Size(625, 33);
			this->labelDescription->TabIndex = 7;
			this->labelDescription->Text = L"Please log in with your account number and password.";
			this->labelDescription->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonLogin
			// 
			this->buttonLogin->BackColor = System::Drawing::Color::Black;
			this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLogin->ForeColor = System::Drawing::Color::White;
			this->buttonLogin->Location = System::Drawing::Point(465, 222);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(78, 40);
			this->buttonLogin->TabIndex = 8;
			this->buttonLogin->Text = L"Log In";
			this->buttonLogin->UseVisualStyleBackColor = false;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &MyForm::buttonLogin_Click);
			// 
			// buttonHelp
			// 
			this->buttonHelp->BackColor = System::Drawing::Color::Black;
			this->buttonHelp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHelp->ForeColor = System::Drawing::Color::White;
			this->buttonHelp->Location = System::Drawing::Point(12, 678);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(78, 40);
			this->buttonHelp->TabIndex = 9;
			this->buttonHelp->Text = L"Help";
			this->buttonHelp->UseVisualStyleBackColor = false;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &MyForm::buttonHelp_Click);
			// 
			// buttonQuit
			// 
			this->buttonQuit->BackColor = System::Drawing::Color::Black;
			this->buttonQuit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonQuit->ForeColor = System::Drawing::Color::White;
			this->buttonQuit->Location = System::Drawing::Point(918, 678);
			this->buttonQuit->Name = L"buttonQuit";
			this->buttonQuit->Size = System::Drawing::Size(78, 40);
			this->buttonQuit->TabIndex = 10;
			this->buttonQuit->Text = L"Quit";
			this->buttonQuit->UseVisualStyleBackColor = false;
			this->buttonQuit->Click += gcnew System::EventHandler(this, &MyForm::buttonQuit_Click);
			// 
			// buttonCredits
			// 
			this->buttonCredits->BackColor = System::Drawing::Color::Black;
			this->buttonCredits->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCredits->ForeColor = System::Drawing::Color::White;
			this->buttonCredits->Location = System::Drawing::Point(824, 678);
			this->buttonCredits->Name = L"buttonCredits";
			this->buttonCredits->Size = System::Drawing::Size(78, 40);
			this->buttonCredits->TabIndex = 11;
			this->buttonCredits->Text = L"Credits";
			this->buttonCredits->UseVisualStyleBackColor = false;
			this->buttonCredits->Click += gcnew System::EventHandler(this, &MyForm::buttonCredits_Click);
			// 
			// buttonPlay
			// 
			this->buttonPlay->BackColor = System::Drawing::Color::Black;
			this->buttonPlay->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonPlay->ForeColor = System::Drawing::Color::White;
			this->buttonPlay->Location = System::Drawing::Point(465, 602);
			this->buttonPlay->Name = L"buttonPlay";
			this->buttonPlay->Size = System::Drawing::Size(78, 40);
			this->buttonPlay->TabIndex = 12;
			this->buttonPlay->Text = L"Play";
			this->buttonPlay->UseVisualStyleBackColor = false;
			this->buttonPlay->Visible = false;
			this->buttonPlay->Click += gcnew System::EventHandler(this, &MyForm::buttonPlay_Click);
			// 
			// buttonHit
			// 
			this->buttonHit->BackColor = System::Drawing::Color::Black;
			this->buttonHit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHit->ForeColor = System::Drawing::Color::White;
			this->buttonHit->Location = System::Drawing::Point(381, 602);
			this->buttonHit->Name = L"buttonHit";
			this->buttonHit->Size = System::Drawing::Size(78, 40);
			this->buttonHit->TabIndex = 13;
			this->buttonHit->Text = L"Hit";
			this->buttonHit->UseVisualStyleBackColor = false;
			this->buttonHit->Visible = false;
			this->buttonHit->Click += gcnew System::EventHandler(this, &MyForm::buttonHit_Click);
			// 
			// buttonStay
			// 
			this->buttonStay->BackColor = System::Drawing::Color::Black;
			this->buttonStay->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonStay->ForeColor = System::Drawing::Color::White;
			this->buttonStay->Location = System::Drawing::Point(549, 602);
			this->buttonStay->Name = L"buttonStay";
			this->buttonStay->Size = System::Drawing::Size(78, 40);
			this->buttonStay->TabIndex = 14;
			this->buttonStay->Text = L"Stay";
			this->buttonStay->UseVisualStyleBackColor = false;
			this->buttonStay->Visible = false;
			this->buttonStay->Click += gcnew System::EventHandler(this, &MyForm::buttonStay_Click);
			// 
			// labelPlayerTotal
			// 
			this->labelPlayerTotal->AutoSize = true;
			this->labelPlayerTotal->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayerTotal->ForeColor = System::Drawing::Color::White;
			this->labelPlayerTotal->Location = System::Drawing::Point(12, 648);
			this->labelPlayerTotal->Name = L"labelPlayerTotal";
			this->labelPlayerTotal->Size = System::Drawing::Size(177, 27);
			this->labelPlayerTotal->TabIndex = 15;
			this->labelPlayerTotal->Text = L"Player\'s Total: 21";
			this->labelPlayerTotal->Visible = false;
			// 
			// labelDealerTotal
			// 
			this->labelDealerTotal->AutoSize = true;
			this->labelDealerTotal->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDealerTotal->ForeColor = System::Drawing::Color::White;
			this->labelDealerTotal->Location = System::Drawing::Point(819, 648);
			this->labelDealerTotal->Name = L"labelDealerTotal";
			this->labelDealerTotal->Size = System::Drawing::Size(179, 27);
			this->labelDealerTotal->TabIndex = 16;
			this->labelDealerTotal->Text = L"Dealer\'s Total: 21";
			this->labelDealerTotal->Visible = false;
			// 
			// buttonResults
			// 
			this->buttonResults->BackColor = System::Drawing::Color::Black;
			this->buttonResults->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonResults->ForeColor = System::Drawing::Color::White;
			this->buttonResults->Location = System::Drawing::Point(111, 678);
			this->buttonResults->Name = L"buttonResults";
			this->buttonResults->Size = System::Drawing::Size(78, 40);
			this->buttonResults->TabIndex = 17;
			this->buttonResults->Text = L"Results";
			this->buttonResults->UseVisualStyleBackColor = false;
			this->buttonResults->Visible = false;
			this->buttonResults->Click += gcnew System::EventHandler(this, &MyForm::buttonResults_Click);
			// 
			// labelGameNumber
			// 
			this->labelGameNumber->AutoSize = true;
			this->labelGameNumber->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGameNumber->ForeColor = System::Drawing::Color::White;
			this->labelGameNumber->Location = System::Drawing::Point(204, 690);
			this->labelGameNumber->Name = L"labelGameNumber";
			this->labelGameNumber->Size = System::Drawing::Size(135, 27);
			this->labelGameNumber->TabIndex = 18;
			this->labelGameNumber->Text = L"Game 99999";
			this->labelGameNumber->Visible = false;
			// 
			// comboBoxCheat
			// 
			this->comboBoxCheat->BackColor = System::Drawing::Color::Black;
			this->comboBoxCheat->Enabled = false;
			this->comboBoxCheat->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxCheat->ForeColor = System::Drawing::Color::White;
			this->comboBoxCheat->FormattingEnabled = true;
			this->comboBoxCheat->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Player Black Jack", L"Dealer Black Jack",
					L"Black Jack Tie", L"Player 3 Card Bust", L"Dealer 3 Card Bust (Player hit Stay)", L"Player 3 Card Win", L"Dealer 3 Card Win (Player hit Stay) ",
					L"Player 5 Card Win", L"Dealer 5 Card Win (Player hit Stay)"
			});
			this->comboBoxCheat->Location = System::Drawing::Point(361, 569);
			this->comboBoxCheat->Name = L"comboBoxCheat";
			this->comboBoxCheat->Size = System::Drawing::Size(292, 27);
			this->comboBoxCheat->TabIndex = 19;
			this->comboBoxCheat->Text = L"Choose an option to Debug";
			this->comboBoxCheat->Visible = false;
			// 
			// labelBank
			// 
			this->labelBank->AutoSize = true;
			this->labelBank->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBank->ForeColor = System::Drawing::Color::White;
			this->labelBank->Location = System::Drawing::Point(12, 621);
			this->labelBank->Name = L"labelBank";
			this->labelBank->Size = System::Drawing::Size(123, 27);
			this->labelBank->TabIndex = 20;
			this->labelBank->Text = L"Bank: $100";
			this->labelBank->Visible = false;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPassword->Location = System::Drawing::Point(429, 190);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(150, 26);
			this->textBoxPassword->TabIndex = 21;
			this->textBoxPassword->Text = L"Password";
			// 
			// comboBoxTestFunctions
			// 
			this->comboBoxTestFunctions->BackColor = System::Drawing::Color::Black;
			this->comboBoxTestFunctions->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxTestFunctions->ForeColor = System::Drawing::Color::White;
			this->comboBoxTestFunctions->FormattingEnabled = true;
			this->comboBoxTestFunctions->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Set up deck by suit", L"Set up deck by value",
					L"Display deck", L"Shuffle deck", L"Shuffle deck (Random Swap)", L"Deal a card", L"Deal a hand", L"Add card to hand", L"Arrange hand",
					L"Store deck on disk", L"Load deck from disk", L"Return"
			});
			this->comboBoxTestFunctions->Location = System::Drawing::Point(361, 569);
			this->comboBoxTestFunctions->Name = L"comboBoxTestFunctions";
			this->comboBoxTestFunctions->Size = System::Drawing::Size(292, 27);
			this->comboBoxTestFunctions->TabIndex = 22;
			this->comboBoxTestFunctions->Text = L"Test Functions";
			this->comboBoxTestFunctions->Visible = false;
			// 
			// buttonTest
			// 
			this->buttonTest->BackColor = System::Drawing::Color::Black;
			this->buttonTest->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTest->ForeColor = System::Drawing::Color::White;
			this->buttonTest->Location = System::Drawing::Point(465, 602);
			this->buttonTest->Name = L"buttonTest";
			this->buttonTest->Size = System::Drawing::Size(78, 40);
			this->buttonTest->TabIndex = 23;
			this->buttonTest->Text = L"Test";
			this->buttonTest->UseVisualStyleBackColor = false;
			this->buttonTest->Visible = false;
			this->buttonTest->Click += gcnew System::EventHandler(this, &MyForm::buttonTest_Click);
			// 
			// buttonDisplayDeck
			// 
			this->buttonDisplayDeck->BackColor = System::Drawing::Color::Black;
			this->buttonDisplayDeck->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDisplayDeck->ForeColor = System::Drawing::Color::White;
			this->buttonDisplayDeck->Location = System::Drawing::Point(424, 642);
			this->buttonDisplayDeck->Name = L"buttonDisplayDeck";
			this->buttonDisplayDeck->Size = System::Drawing::Size(160, 40);
			this->buttonDisplayDeck->TabIndex = 24;
			this->buttonDisplayDeck->Text = L"Display Deck";
			this->buttonDisplayDeck->UseVisualStyleBackColor = false;
			this->buttonDisplayDeck->Visible = false;
			this->buttonDisplayDeck->Click += gcnew System::EventHandler(this, &MyForm::buttonDisplayDeck_Click);
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->ForeColor = System::Drawing::Color::White;
			this->labelPassword->Location = System::Drawing::Point(452, 158);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(104, 27);
			this->labelPassword->TabIndex = 25;
			this->labelPassword->Text = L"Password";
			// 
			// labelAccountNumber
			// 
			this->labelAccountNumber->AutoSize = true;
			this->labelAccountNumber->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAccountNumber->ForeColor = System::Drawing::Color::White;
			this->labelAccountNumber->Location = System::Drawing::Point(415, 99);
			this->labelAccountNumber->Name = L"labelAccountNumber";
			this->labelAccountNumber->Size = System::Drawing::Size(178, 27);
			this->labelAccountNumber->TabIndex = 26;
			this->labelAccountNumber->Text = L"Account Number";
			// 
			// buttonHistory
			// 
			this->buttonHistory->BackColor = System::Drawing::Color::Black;
			this->buttonHistory->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHistory->ForeColor = System::Drawing::Color::White;
			this->buttonHistory->Location = System::Drawing::Point(730, 678);
			this->buttonHistory->Name = L"buttonHistory";
			this->buttonHistory->Size = System::Drawing::Size(78, 40);
			this->buttonHistory->TabIndex = 27;
			this->buttonHistory->Text = L"History";
			this->buttonHistory->UseVisualStyleBackColor = false;
			this->buttonHistory->Visible = false;
			this->buttonHistory->Click += gcnew System::EventHandler(this, &MyForm::buttonHistory_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->labelAccountNumber);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelGameNumber);
			this->Controls->Add(this->buttonCredits);
			this->Controls->Add(this->buttonQuit);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->buttonLogin);
			this->Controls->Add(this->labelDescription);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->pictureBoxCardAnimation2);
			this->Controls->Add(this->pictureBoxCardAnimation1);
			this->Controls->Add(this->labelDateTime);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->pictureBoxGif);
			this->Controls->Add(this->pictureBoxAlignment);
			this->Controls->Add(this->buttonHit);
			this->Controls->Add(this->buttonStay);
			this->Controls->Add(this->buttonResults);
			this->Controls->Add(this->labelDealerTotal);
			this->Controls->Add(this->labelBank);
			this->Controls->Add(this->labelPlayerTotal);
			this->Controls->Add(this->comboBoxCheat);
			this->Controls->Add(this->buttonTest);
			this->Controls->Add(this->comboBoxTestFunctions);
			this->Controls->Add(this->buttonPlay);
			this->Controls->Add(this->buttonDisplayDeck);
			this->Controls->Add(this->buttonHistory);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Text = L"Laithe\'s Blackjack Table";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGif))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAlignment))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCardAnimation1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCardAnimation2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		////////////////////////////////////////////////////////////////////
		//
		//				DECLARE GLOBAL VARIABLES/OBJECTS
		//
		////////////////////////////////////////////////////////////////////

		array<String^>^ cardName; 
		array<String^>^ cardSuit;
		array<int>^ cardValue;

		AccountType user;
		GameResults^ userHistory = gcnew GameResults();
		GameResults^ dealerHistory = gcnew GameResults();

		// creates arrays to store cards, card images, and card labels for the tester
		array<PictureBox^>^ testerCardPictureBoxes = gcnew array<PictureBox^>(52);
		array<Label^>^ testerCardLabels = gcnew array<Label^>(52);
		array<Point>^ testerCardPositions = gcnew array<Point>(52);
		Hand^ testerHand = gcnew Hand();

		// creates arrays to store cards, card images, and card labels for the player
		array<PictureBox^>^ playerCardPictureBoxes = gcnew array<PictureBox^>(10); 
		array<Label^>^ playerCardLabels = gcnew array<Label^>(60);
		array<Point>^ playerCardPositions; // card positions for 5 cards (50, 112), (180, 112), (310, 112), (108, 333), (238, 333)
		Hand^ playerHand = gcnew Hand();

		// creates arrays to store cards, card images, and card labels for the dealer
		array<PictureBox^>^ dealerCardPictureBoxes = gcnew array<PictureBox^>(10);
		array<Label^>^ dealerCardLabels = gcnew array<Label^>(10);
		array<Point>^ dealerCardPositions; // card positions for 5 cards (573 ,112), (703 , 112), (833, 112), (631, 333), (761, 333)
		Hand^ dealerHand = gcnew Hand();

		ArrayList^ deck = gcnew ArrayList();

		int gameNumber = 0, win = 0, loss = 0, tie = 0;
		int playerWinCounter = 0, playerLoseCounter = 0, playerTieCounter = 0;

		//counters for stats
		int totalCardsUsed = 0, totalAcesUsed = 0, totalTwosUsed = 0, totalThreesUsed = 0, totalFoursUsed = 0, totalFivesUsed = 0;
		int totalSixesUsed = 0, totalSevensUsed = 0, totalEightsUsed = 0, totalNinesUsed = 0, totalTensUsed = 0, totalJacksUsed = 0;
		int totalQueensUsed = 0, totalKingsUsed = 0, timesShuffled = 0;
		int handLessThan16 = 0, handBetween16And20 = 0, hand21 = 0, handGreaterThan21 = 0;

		int bank = 100;

		bool playingGame = false, debugMode = false, bankrupt = false, playerWin = false, tied = false, playerBlackJack = false, bet = false;
		////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////
		//
		//				START CUSTOM DEFINED FUNCTIONS
		//
		////////////////////////////////////////////////////////////////////

		void addCardToHand(ArrayList^ deck ,Hand^ hand, String^ owner)
		{
			if (hand->getHandSize() < 2)
			{
				MessageBox::Show("Please deal a hand before adding a card to the hand.", "Error");
			}
			else
			{
				dealCard(deck, hand, owner);
			}
		}

		void arrangeHand(Hand^ hand, String^ owner)
		{
			if (hand->getHandSize() > 0)
			{
				if (owner = "tester")
				{
					ArrayList^ tempHand;
					hand->arrangeHand();

					int handSize = hand->getHandSize();

					tempHand = gcnew ArrayList(hand->getCards());

					clearScreenTester();
					hand->setHandSize(0);

					for (int i = 0; i < handSize; i++)
					{

						dealCard(tempHand, hand, owner);
					}
				}
			}

			else
			{
				MessageBox::Show("Please create a hand to arrange.", "Error");
			}
		}

		/**************************************************************

			NAME: blackJack

			DESCRIPTION: Validity statement that returns true if card total is 
			equal to 21, else it returns false.

			PRECONDITIONS: Function expects a positive integer between 2-32 which
			is given by calculating the value of a hand in black jack.

			POSTCONDITIONS: see description

			CALLED BY: buttonPlay_Click

			CALLS: None

		**************************************************************/

		bool blackJack(int cardTotal)
		{
			if (cardTotal == 21)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}


		/**************************************************************

			NAME: bust

			DESCRIPTION: Validity statement that returns true if the card total is greater
			than 21, else it returns false

			PRECONDITIONS:  Function expects a positive integer between 2-32 which
			is given by calculating the value of a hand in black jack.

			POSTCONDITIONS: see description

			CALLED BY: buttonHit_Click, buttonPlay_Click, buttonStay_Click

			CALLS: None

			**************************************************************/

		bool bust(int cardTotal)
		{
			if (cardTotal > 21)
			{
				return true;
			}

			else
			{
				return false;
			}
		}


		/**************************************************************

			NAME: cleanup

			DESCRIPTION: Readys the program to play another game of black jack
			by clearing the screen, updating statistics, and reinitializing variables to their 
			original value.

			PRECONDITIONS: Function requires the integer amount of cards used by player and dealer
			to clear all cards and their labels using these values and a index ceiling. These values
			must be exact, to high and the program will crash, to low and it will not clear all the cards and labels.

			POSTCONDITIONS: None

			CALLED BY: buttonHit_Click, buttonPlay_Click, buttonStay_Click

			CALLS: countCardsUsed, countHandTypes, quit, updateBank

		**************************************************************/

		void cleanup()
		{
			GameType playerCurrentGame;
			GameType dealerCurrentGame;

			buttonHit->Visible = false;
			buttonStay->Visible = false;
			buttonPlay->Visible = true;
			labelDescription->Text = "";
			labelGameNumber->Visible = false;

			playingGame = false;

			playerCurrentGame.cardTotal = playerHand->getHandValue();
			dealerCurrentGame.cardTotal = dealerHand->getHandValue();

			playerCurrentGame.handResult = getHandType(playerHand->getHandValue());
			dealerCurrentGame.handResult = getHandType(dealerHand->getHandValue());

			playerCurrentGame.gameNumber = gameNumber;
			dealerCurrentGame.gameNumber = gameNumber;
			
			if (playerWinCounter < win)
			{
				playerCurrentGame.gameOutcome = GameResult::win;
				dealerCurrentGame.gameOutcome = GameResult::lose;
				playerWinCounter++;
			}

			else if (playerLoseCounter < loss)
			{
				playerCurrentGame.gameOutcome = GameResult::lose;
				dealerCurrentGame.gameOutcome = GameResult::win;
				playerLoseCounter++;
			}

			else if (playerTieCounter < tie)
			{
				playerCurrentGame.gameOutcome = GameResult::tie;
				dealerCurrentGame.gameOutcome = GameResult::tie;
				playerTieCounter++;
			}
			else
			{
				MessageBox::Show("error");
			}
			updateBank();

			userHistory->addGameResult(playerCurrentGame);
			dealerHistory->addGameResult(dealerCurrentGame);


			playerWin = false;
			tied = false;
			playerBlackJack = false;
			bet = false;

			labelPlayerTotal->Visible = false;
			labelDealerTotal->Visible = false;

			if (debugMode)
			{
				comboBoxCheat->Text = "Choose an option to Debug";
				comboBoxCheat->Visible = true;
			}

			for (int i = 0; i < playerHand->getHandSize(); i++)
			{
				delete playerCardPictureBoxes[i];
				delete playerCardLabels[i];
			}

			for (int i = 0; i < dealerHand->getHandSize(); i++)
			{
				delete dealerCardPictureBoxes[i];
				delete dealerCardLabels[i];
			}

			playerHand->clearHand();

			dealerHand->clearHand();

			if (bankrupt)
			{
				quit();
			}
		}
		void clearScreenTester()
		{
			for (int i = 0; i < testerHand->getHandSize(); i++)
			{
				delete testerCardPictureBoxes[i];
				delete testerCardLabels[i];
			}

			testerHand->clearHand();
		}
		/**************************************************************

			NAME: credits

			DESCRIPTION: Function displays message boxes for each of the following,
			ID info, credits, media, and stars.

			PRECONDITIONS: None

			POSTCONDITIONS: None

			CALLED BY: buttonCredits_Click

			CALLS: None

			**************************************************************/



		void credits()
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			String^ message;
			StreamReader^ sr;

			////////////////////////////////////////////////////////////////////

			sr = gcnew StreamReader("..//Farewell/ID_info.txt");
			message = sr->ReadToEnd();
			sr->Close();

			MessageBox::Show(
				message,
				"ID INFORMATION" // message box caption
				);

			sr = gcnew StreamReader("..//Farewell/Credits.txt");
			message = sr->ReadToEnd();
			sr->Close();

			MessageBox::Show(
				message,
				"CREDITS" // message box caption
				);

			sr = gcnew StreamReader("..//Farewell/Media.txt");
			message = sr->ReadToEnd();
			sr->Close();

			MessageBox::Show(
				message,
				"MEDIA" // message box caption
				);

			sr = gcnew StreamReader("..//Farewell/Stars.txt");
			message = sr->ReadToEnd();
			sr->Close();

			MessageBox::Show(

				message,
				"STARS" // message box caption
				);
		}



			/**************************************************************

				NAME: getHandTypes

				DESCRIPTION: Function returns the following hand types:
				<16, >15 & <21, =21, and > 21 

				PRECONDITIONS: Function requires the card total value of the player hand
				and the dealer hand.

				POSTCONDITIONS: None

				CALLED BY: cleanup

				CALLS: None

				**************************************************************/

		HandResultType getHandType(int handValue)
		{
			if (handValue < 16)
			{
				return HandResultType::lessThan16;
			}

			if (handValue > 15 && handValue < 21)
			{
				return HandResultType::between16and20;
			}

			if (handValue == 21)
			{
				return HandResultType::exactly21;
			}


			else 
			{
				return HandResultType::over21;
			}

		}

		/**************************************************************

			NAME: dealCard

			DESCRIPTION: this function simulates dealing a card from a deck and returns
			the card dealt.

			PRECONDITIONS: None

			POSTCONDITIONS: See description

			CALLED BY: buttonHit_Click, buttonPlay_Click, buttonStay_Click

			CALLS:

			**************************************************************/

		void dealCard(ArrayList^ deck, Hand^ hand, String^ handOwner)
		{

			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			Card^ tempCard = gcnew Card();
			Card^ aceChange = gcnew Card();
			int index, aceIndex = 0;
			int aceIndexHand[5];
			array<String^>^ aceSuit = gcnew array<String^>(5);
			ArrayList^ cardsInHand;
			bool aceChanged = false;
			////////////////////////////////////////////////////////////////////

			if (deck->Count > 0)
			{
				tempCard = safe_cast<Card^>(deck[0]);

				if (tempCard->getCardName() == "Ace")
				{
					tempCard->setCardValue(11);
				}


				if (hand->getHandValue() + tempCard->getCardValue() > 21)
				{
					if (tempCard->getCardName() != "Ace")
					{
						cardsInHand = gcnew ArrayList(hand->getCards());

						for (int i = 0; i < hand->getHandSize(); i++)
						{
							aceChange = safe_cast<Card^>(cardsInHand[i]);
							if (aceChange->getCardName() == "Ace")
							{

								safe_cast<Card^>(cardsInHand[i])->setCardValue(1);
								aceChanged = true;
								aceSuit[aceIndex] = aceChange->getCardSuit();
								aceIndexHand[aceIndex] = i;
								aceIndex++;
							}
						}
						hand->setCards(cardsInHand);
						hand->calcHandValue();
					}
					else
					{
						tempCard->setCardValue(1);
					}

					
				}

			
				if (handOwner == "player")
				{
					index = hand->getHandSize();
					this->playerCardPictureBoxes[index] = gcnew PictureBox();
					this->playerCardLabels[index] = gcnew Label();

					this->Controls->Add(playerCardPictureBoxes[index]);
					this->Controls->Add(playerCardLabels[index]);
					this->playerCardPictureBoxes[index]->Name = index.ToString();

					this->playerCardPictureBoxes[index]->MouseEnter += gcnew System::EventHandler(this, &MyForm::playerCard_MouseEnter);
					this->playerCardPictureBoxes[index]->MouseLeave += gcnew System::EventHandler(this, &MyForm::playerCard_MouseLeave);

					deck->RemoveAt(0);

					hand += tempCard;

					tempCard->displayCard(playerCardPictureBoxes[index], playerCardLabels[index], imageListCards, playerCardPositions[index]);

					if (aceChanged)
					{
						for (int i = 0; i < aceIndex; i++)
						{
							playerCardLabels[aceIndexHand[i]]->Text = "Ace of " + aceSuit[i] + "\n(1)";
						}
					}
				}

				if (handOwner == "dealer")
				{
					index = hand->getHandSize();
					this->dealerCardPictureBoxes[index] = gcnew PictureBox();
					this->dealerCardLabels[index] = gcnew Label();

					this->Controls->Add(dealerCardPictureBoxes[index]);
					this->Controls->Add(dealerCardLabels[index]);
					this->dealerCardPictureBoxes[index]->Name = index.ToString();

					this->dealerCardPictureBoxes[index]->MouseEnter += gcnew System::EventHandler(this, &MyForm::dealerCard_MouseEnter);
					this->dealerCardPictureBoxes[index]->MouseLeave += gcnew System::EventHandler(this, &MyForm::dealerCard_MouseLeave);

					deck->RemoveAt(0);

					hand += tempCard;

					tempCard->displayCard(dealerCardPictureBoxes[index], dealerCardLabels[index], imageListCards, dealerCardPositions[index]);

					if (aceChanged)
					{
						for (int i = 0; i < aceIndex; i++)
						{
							testerCardLabels[aceIndexHand[i]]->Text = "Ace of " + aceSuit[i] + "\n(1)";
						}
					}
				}

				if (handOwner == "tester")
				{
					index = hand->getHandSize();
					this->testerCardPictureBoxes[index] = gcnew PictureBox();
					this->testerCardLabels[index] = gcnew Label();

					this->Controls->Add(testerCardPictureBoxes[index]);
					this->Controls->Add(testerCardLabels[index]);
					this->testerCardPictureBoxes[index]->Name = index.ToString();

					this->testerCardPictureBoxes[index]->MouseEnter += gcnew System::EventHandler(this, &MyForm::testerCard_MouseEnter);
					this->testerCardPictureBoxes[index]->MouseLeave += gcnew System::EventHandler(this, &MyForm::testerCard_MouseLeave);

					deck->RemoveAt(0);

					hand += tempCard;

					tempCard->displayCard(testerCardPictureBoxes[index], testerCardLabels[index], imageListCards, testerCardPositions[index]);
					
					if (aceChanged)
					{
						for (int i = 0; i < aceIndex; i++)
						{
							testerCardLabels[aceIndexHand[i]]->Text = "Ace of " + aceSuit[i] + "\n(1)";
						}
					}
				}
			}

			else
			{
				MessageBox::Show("Please setup or load the deck before dealing cards.", "Error");
			}

		}

		void dealHand(ArrayList^ deck, Hand^ hand,String^ owner)
		{
			if (deck->Count > 0)
			{
				dealCard(deck, hand, owner);
				dealCard(deck, hand, owner);
			}

			else
			{
				MessageBox::Show("Please setup or load the deck before dealing a hand.", "Error");
			}
			
		}


		/**************************************************************

			NAME: dealerHit

			DESCRIPTION: Validity statement to determine if the dealer will hit
			in a game of Black Jack. Function returns true if the card total is 
			less than 16, else it returns false.

			PRECONDITIONS: Function requires the integer card value total from the dealer's hand.

			POSTCONDITIONS: see description

			CALLED BY: buttonStay_Click

			CALLS: None

			**************************************************************/

		bool dealerHit(int cardTotal)
		{
			if (cardTotal < 16)
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		/**************************************************************

			NAME: debugDecks

			DESCRIPTION: prepares a deck to use in the debugging process based 
			on a combo box list.

			PRECONDITIONS: An option in the combo box list has been selected.

			POSTCONDITIONS: Stacks a deck based on the precondition.

			CALLED BY: buttonPlay_Click

			CALLS: None

			**************************************************************/

		void debugDecks()
		{
			ArrayList^ debugDeck = gcnew ArrayList();
			deck->Clear();
			setupDeckBySuit(debugDeck);
			if (comboBoxCheat->Text == "Player Black Jack")
			{
				deck->Add(debugDeck[39]); //Ace
				deck->Add(debugDeck[40]); //2 
				deck->Add(debugDeck[49]); //Jack
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
			}

			if (comboBoxCheat->Text == "Dealer Black Jack")
			{
				deck->Add(debugDeck[40]); //2 
				deck->Add(debugDeck[39]); //Ace
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[49]); //Jack
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				
			}

			if (comboBoxCheat->Text == "Black Jack Tie")
			{
				deck->Add(debugDeck[39]); //Ace
				deck->Add(debugDeck[39]); //Ace
				deck->Add(debugDeck[49]); //Jack
				deck->Add(debugDeck[49]); //Jack
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
	
			}

			if (comboBoxCheat->Text == "Player 3 Card Bust")
			{
				deck->Add(debugDeck[51]); //King
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[50]); //Queen
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[49]); //Jack
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
			}

			if (comboBoxCheat->Text == "Dealer 3 Card Bust (Player hit Stay)")
			{
				deck->Add(debugDeck[51]); //King
				deck->Add(debugDeck[44]); //6
				deck->Add(debugDeck[50]); //Queen
				deck->Add(debugDeck[45]); //7
				deck->Add(debugDeck[49]); //Jack
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
			}

			if (comboBoxCheat->Text == "Player 3 Card Win")
			{
				deck->Add(debugDeck[44]); //6
				deck->Add(debugDeck[51]); //King
				deck->Add(debugDeck[45]); //7
				deck->Add(debugDeck[50]); //Queen
				deck->Add(debugDeck[46]); //8
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
			}

			if (comboBoxCheat->Text == "Dealer 3 Card Win (Player hit Stay) ")
			{
				deck->Add(debugDeck[51]); //King
				deck->Add(debugDeck[44]); //6
				deck->Add(debugDeck[50]); //Queen
				deck->Add(debugDeck[45]); //7
				deck->Add(debugDeck[46]); //8
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
			}

			if (comboBoxCheat->Text == "Player 5 Card Win")
			{
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3

				deck->Add(debugDeck[41]); //3

			}

			if (comboBoxCheat->Text == "Dealer 5 Card Win (Player hit Stay)")
			{
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[40]); //2
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
				deck->Add(debugDeck[41]); //3
			}
		}

		/**************************************************************

			NAME: displayCardTotal

			DESCRIPTION: displays a label with total value of the cards displayed

			PRECONDITIONS: requires a boolean expression to determine if the
			card total displayed is for the player(true) or dealer(false).

			POSTCONDITIONS: see description

			CALLED BY: buttonHit_Click, buttonPlay_Click, buttonStay_Click

			CALLS: None

			**************************************************************/

		void displayCardTotal(Hand^ hand,bool player)
		{
			if (player)
			{
				labelPlayerTotal->Text = user.firstName + "\'s Total: " + hand->getHandValue().ToString();
				labelPlayerTotal->Visible = true;
			}

			else
			{
				labelDealerTotal->Text = "Dealer\'s Total: " + hand->getHandValue().ToString();
				labelDealerTotal->Visible = true;
			}
		}

		/**************************************************************

			NAME: displayDealerStrategy

			DESCRIPTION: displays in a message box what dealer will do in a game of black jack
			given the their current hand value.

			PRECONDITIONS: None

			POSTCONDITIONS: See description

			CALLED BY: buttonStay_Click

			CALLS: None

			**************************************************************/

		void displayDealerStrategy()
		{
			if (dealerHand->getHandValue() < 16)
			{
				MessageBox::Show("Dealer has " + dealerHand->getHandValue().ToString() + " and will hit on 15 or lower.", "Dealer Strategy");
			}

			else
			{
				MessageBox::Show( "Dealer has " + dealerHand->getHandValue().ToString() + " and will stay on 16 or higher.","Dealer Strategy");
			}
		}

		void displayDeck(ArrayList^ deck)
		{
			ArrayList^ displayDeck = gcnew ArrayList(deck);
			String^ message;
			String^ cardName;
			String^ cardSuit;
			int count = 0;

			if (deck->Count > 0)
			{
				clearScreenTester();

				for (int i = 0; i < displayDeck->Count; i++)
				{
					cardName = safe_cast<Card^>(displayDeck[i])->getCardName();
					cardSuit = safe_cast<Card^>(displayDeck[i])->getCardSuit();

					message += i.ToString() + ": " + cardName + " of " + cardSuit + ", ";

					if (count == 13)
					{
						message += "\n\n";
						count = 0;
					}
					count++;
				}
				MessageBox::Show(message);
				count = displayDeck->Count;

				for (int i = 0; i < count; i++)
				{
					dealCard(displayDeck, testerHand, "tester");
				}
			}

			else
			{
				MessageBox::Show("Please setup or load a deck before displaying it.", "Error");
			}
		}

		/**************************************************************

			NAME: displayFarewellMessage

			DESCRIPTION: displays farewell messages based on how well a user did
			while playing black jack.

			PRECONDITIONS: None

			POSTCONDITIONS: See description

			CALLED BY: quit

			CALLS: None

		**************************************************************/

		void displayFarewellMessage()
		{
			if (bankrupt)
			{
				MessageBox::Show("Well, this is awkward " + user.firstName + "... You seem to be out of money.\n"+ 
								 "Time for you to go... See you when you get more money.", "Bankrupt!");
			}

			if (gameNumber == 0)
			{
				if (user.firstName == nullptr)
				{
					MessageBox::Show("Goodbye anonymous user. Hopefully next time you'll play a game.", "Farewell");
				}
				
				else
				{
					MessageBox::Show("Goodbye " + user.firstName + ". Hopefully next time you'll play a game.", "Farewell");
				}
			}

			else
			{
				if (bank > 0)
				{
					MessageBox::Show(user.firstName + ", you are withdrawing an amount of $" + bank.ToString() + ".", "Congratulations...");
				}

				if (win > loss)
				{
					MessageBox::Show("Goodbye " + user.firstName + ". Out of " + gameNumber.ToString() + " games you won " + win.ToString() +
									 " game(s) while the dealer won " + loss.ToString() + " game(s). You and the Dealer tied " +
									  tie.ToString() + " game(s). You beat the dealer! :)", "Farewell");
				}

				else if (win < loss)
				{
					MessageBox::Show("Goodbye " + user.firstName + ". Out of " + gameNumber.ToString() + " games you won " + win.ToString() +
									 " game(s) while the dealer won " + loss.ToString() + " game(s). You and the Dealer tied " +
									 tie.ToString() + " game(s). The dealer beat you! :(", "Farewell");
				}

				else
				{
					MessageBox::Show("Goodbye " + user.firstName + ". Out of " + gameNumber.ToString() + " games you won " + win.ToString() +
									 " game(s) while the dealer won " + loss.ToString() + " game(s). You and the Dealer tied " +
									 tie.ToString() + " game(s). You and the dealer tied. :|", "Farewell");
				}
			}
		}

		/**************************************************************

			NAME: displayGameResults

			DESCRIPTION: Displays in a message box a results message based on 
			the outcome of a Black Jack game.

			PRECONDITIONS: Function takes a string command to determine what
			message to display. This command is entered by the programmer.

			POSTCONDITIONS: see description

			CALLED BY: buttonHit_Click, buttonPlay_Click, buttonStay_Click

			CALLS: None

			**************************************************************/

		void displayGameResults(String^ command)
		{
			if (command->ToLower() == "player bust")
			{
				MessageBox::Show(user.firstName + " busts with a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " loses. Dealer wins.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "dealer bust")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer busts with a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " wins. Dealer loses.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "player win")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " wins. Dealer loses.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "dealer win")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " loses. Dealer Wins.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "tie")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " and Dealer tie.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "dealer bj")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
							  	 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
							 	 user.firstName + " loses. Dealer wins with Black Jack.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "player bj")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " wins with Black Jack. Dealer loses.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "bj tie")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " and Dealer tie with Black Jack.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "player 5 card win")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
								 "Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
								 user.firstName + " wins with 5 cards under 22. Dealer loses.", "Game " + gameNumber.ToString());
			}

			if (command->ToLower() == "dealer 5 card win")
			{
				MessageBox::Show(user.firstName + " has a total of: " + playerHand->getHandValue().ToString() + ". " +
					"Dealer has a total of: " + dealerHand->getHandValue().ToString() + ".\n" +
					"Dealer wins with 5 cards under 22. " + user.firstName + " loses.", "Game " + gameNumber.ToString());
			}
		}

		/**************************************************************

			NAME: displayGameStats

			DESCRIPTION: Displays in a message box current games won, games lost, games tied. Whether
			the player is winning, losing, or tied with dealer. The function also displays, in a second message box,
			how often a card has been used, how many times the deck has been shuffled, and how many times different hand 
			types have occured.

			PRECONDITIONS: integer counters have been initialized

			POSTCONDITIONS: see description

			CALLED BY: buttonResults_Click

			CALLS: None

			**************************************************************/

		void displayGameStats()
		{
			if (win > loss)
			{
				MessageBox::Show(user.firstName + " has won " + win.ToString() + " game(s).\n" +
					"The Dealer has won " + loss.ToString() + " game(s).\n" + user.firstName + " and the Dealer tied " +
								 tie.ToString() + " game(s).\n" + "Total Games: " + gameNumber.ToString() + "\n" +
								 "So far " + user.firstName + " has won more games.", "Current Results");
			}

			else if (win < loss)
			{
				MessageBox::Show(user.firstName + " has won " + win.ToString() + " game(s).\n" +
								 "The Dealer has won " + loss.ToString() + " game(s).\n" + user.firstName + " and the Dealer tied " +
								 tie.ToString() + " game(s).\n" + "Total Games: " + gameNumber.ToString() + "\n" +
								 "So far the Dealer has won more games.", "Current Results");
			}

			else
			{
				MessageBox::Show(user.firstName + " has won " + win.ToString() + " game(s).\n" +
					"The Dealer has won " + loss.ToString() + " game(s).\n" + user.firstName + " and the Dealer tied " +
								 tie.ToString() + " game(s).\n" + "Total Games: " + gameNumber.ToString() + "\n" +"So far " +
								 user.firstName + " and the Dealer are tied.", "Current Results");
			}

			/*MessageBox::Show(
				"Total times the Deck has been shuffled: " + timesShuffled.ToString() + "\n\n" +
				"Hands under 16: " + handLessThan16.ToString() + "\n" +
				"Hands between 16 and 20: " + handBetween16And20.ToString() + "\n" +
				"Hands equal to 21: " + hand21.ToString() + "\n" +
				"Hands greater than 21 : " + handGreaterThan21.ToString() + "\n\n" +
				"Total Cards Used: " + totalCardsUsed.ToString() + "\n" +
				"Total Aces Used: " + totalAcesUsed.ToString() + "\n" +
				"Total Twos Used: " + totalTwosUsed.ToString() + "\n" +
				"Total Threes Used: " + totalThreesUsed.ToString() + "\n" +
				"Total Fours Used: " + totalFoursUsed.ToString() + "\n" +
				"Total Fives Used: " + totalFivesUsed.ToString() + "\n" +
				"Total Sixes Used: " + totalSixesUsed.ToString() + "\n" +
				"Total Sevens Used: " + totalSevensUsed.ToString() + "\n" +
				"Total Eights Used: " + totalEightsUsed.ToString() + "\n" +
				"Total Nines Used: " + totalNinesUsed.ToString() + "\n" +
				"Total Tens Used: " + totalTensUsed.ToString() + "\n" +
				"Total Jacks Used: " + totalJacksUsed.ToString() + "\n" +
				"Total Queen Used: " + totalQueensUsed.ToString() + "\n" +
				"Total Kings Used: " + totalKingsUsed.ToString(), "Shuffling, Hand, & Card Totals");*/
		}

		/**************************************************************

			NAME: initializePointArrays

			DESCRIPTION: sets the values of the point arrays dealerCardPositions and playercardPositions

			PRECONDITIONS: the arrays have been intialized.

			POSTCONDITIONS: see description

			CALLED BY: MyForm_Load

			CALLS: None

			**************************************************************/

		void initializeArrays()
		{

			Point testerStartingPoint (30, 82);

			for (int i = 0; i < 52; i++)
			{

				if (i < 13)
				{
					testerCardPositions[i] = testerStartingPoint;
					testerStartingPoint.X += 20;

					if (i == 12)
					{
						testerStartingPoint.X = 30;
						testerStartingPoint.Y = 162;
					}
				}

				else if (i < 26)
				{
					testerCardPositions[i] = testerStartingPoint;
					testerStartingPoint.X += 20;
					if (i == 25)
					{
						testerStartingPoint.X = 30;
						testerStartingPoint.Y = 252;
					}
				}

				else if (i < 39)
				{
					testerCardPositions[i] = testerStartingPoint;
					testerStartingPoint.X += 20;
					if (i == 38)
					{
						testerStartingPoint.X = 30;
						testerStartingPoint.Y = 342;
					}
				}

				else if (i < 52)
				{
					testerCardPositions[i] = testerStartingPoint;
					testerStartingPoint.X += 20;
				}
			}

			dealerCardPositions = gcnew array<Point> { Point(573, 112), Point(593, 122), Point(613, 132), Point(633, 142), Point(653, 152) };
			playerCardPositions = gcnew array<Point> { Point(50, 112), Point(70, 122), Point(90, 132), Point(110, 142), Point(130, 152) };

			cardName = gcnew array<String^> { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
											  "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
			
			cardSuit = gcnew array < String^ > { "Clubs", "Diamonds", "Hearts", "Spades" };

			cardValue = gcnew array < int > {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
		}

		void loadDeck(ArrayList^ deck)
		{
			StreamReader^ sr = gcnew StreamReader("..//Data/workingDeck.dat");
			
			array<String^>^ delimiter = gcnew array<String^> { ", " };
			array<String^>^ cardData;
			String^ data;
			String^ message;
			Card^ tempCard;
			int tempCardValue, tempCardImageList;
			int count;

			deck->Clear();

			if (sr->Peek() > -1)
			{
				while (sr->Peek() > -1)
				{
					tempCard = gcnew Card();

					data = sr->ReadLine();
					cardData = data->Split(delimiter, System::StringSplitOptions::None);
					tempCard->setCardName(cardData[0]);
					tempCard->setCardSuit(cardData[1]);

					Int32::TryParse(cardData[2], tempCardValue);
					tempCard->setCardValue(tempCardValue);

					Int32::TryParse(cardData[3], tempCardImageList);
					tempCard->setCardImageList(tempCardImageList);



					deck->Add(tempCard);
				}
				
			

			count = deck->Count;
			for (int i = 0; i < count; i++)
			{
				tempCard = safe_cast<Card^>(deck[i]);
				message += i.ToString() + ": " + tempCard->getCardName() + ", " + tempCard->getCardSuit() + ", " + tempCard->getCardValue().ToString() + ", " +
				tempCard->getCardImageList().ToString() + "    ";
				if (i % 3 == 0 && i != 0)
				{
					message += "\n\n";
				}
			}

			MessageBox::Show(message, "Deck Loaded");

			sr->Close();

			}

			else
			{
				MessageBox::Show("Please store a deck to disk before trying to load it.", "Error");
			}
		}

		/**************************************************************

			NAME: quit

			DESCRIPTION: displays a farewell message and image, plays music, and closes the program.

			PRECONDITIONS: None

			POSTCONDITIONS: see description

			CALLED BY: buttonQuit_Click, cleanup

			CALLS: displayFarewellMessage

			**************************************************************/

		void quit()
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			Image^ exitImage = Image::FromFile("..//Media/Images/FMA_everyone.jpg");
			Media::SoundPlayer^ sndPlayer = gcnew Media::SoundPlayer("..//Media/Music/Fukuhara Miho - LET IT OUT (TV Size).wav");

			////////////////////////////////////////////////////////////////////

			pictureBoxAlignment->Image = exitImage;
			pictureBoxAlignment->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			pictureBoxAlignment->BringToFront();
			pictureBoxAlignment->Visible = true;

			sndPlayer->Play();
			displayFarewellMessage();
			Close();
		}


		void setupDeckBySuit(ArrayList^ deck)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			Card^ card = gcnew Card();

			////////////////////////////////////////////////////////////////////

			deck->Clear();

			for (int i = 0; i < 52; i++)
			{
				card = gcnew Card();

				card->setCardValue(cardValue[i % 13]);
				card->setCardName(cardName[i % 13]);
				card->setCardSuit(cardSuit[i / 13]);
				card->setCardImageList(i);
				deck->Add(card);
			}

			MessageBox::Show("Deck has been set up by suit.", "Deck Setup");
		}

		void setupDeckByValue(ArrayList^ deck)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			ArrayList^ tempDeck;

			////////////////////////////////////////////////////////////////////

			setupDeckBySuit(deck);

			tempDeck = gcnew ArrayList(deck);

			deck->Clear();

			for (int i = 0; i < 13; i++)
			{
				deck->Add(tempDeck[i]);
				deck->Add(tempDeck[i + 13]);
				deck->Add(tempDeck[i + 26]);
				deck->Add(tempDeck[i + 39]);
			}

			MessageBox::Show("Deck has been set up by value.", "Deck Setup");
		}

		void storeDeck(ArrayList^ deck)
		{
			StreamWriter^ sw = gcnew StreamWriter("..//Data/workingDeck.dat");
			Card^ tempCard = gcnew Card();
			String^ data;
			String^ message;

			for (int i = 0; i < deck->Count; i++)
			{
				tempCard = safe_cast<Card^>(deck[i]);
				data = tempCard->getCardName() + ", " + tempCard->getCardSuit() + ", " + tempCard->getCardValue().ToString() + ", " +
					tempCard->getCardImageList().ToString();
				sw->WriteLine(data);

				message += i.ToString() + ": " + data + "    ";
				if (i % 3 == 0 && i != 0)
				{
					message += "\n\n";
				}
			}			
			MessageBox::Show(message, "Deck Stored");
			sw->Close();
		}

		/**************************************************************

			NAME: shuffleDeck

			DESCRIPTION: simulates a shuffled deck of 52 playing cards

			PRECONDITIONS: None

			POSTCONDITIONS: See description

			CALLED BY: buttonHit_Click, buttonPlay_Click, buttonStay_Click

			CALLS: None

			**************************************************************/

		void shuffleDeck(ArrayList^ deck)
		{
			//Random Assign Shuffle Make a Random Swap Shuffle
			
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			ArrayList^ sortedDeck =gcnew ArrayList(deck);
			Random^ seedGenerator = gcnew Random();
			int index, seed = seedGenerator->Next(), count;;
			Random^ shuffler = gcnew Random(seed);

			////////////////////////////////////////////////////////////////////
			if (deck->Count > 0)
			{

				deck->Clear();
				count = sortedDeck->Count;
				for (int i = count-1; i > -1; i--)
				{
					index = shuffler->Next(i);
					deck->Add(sortedDeck[index]);
					sortedDeck->RemoveAt(index);
				}

				timesShuffled++;
			}

			else
			{
				MessageBox::Show("Please setup or load a deck before shuffling it.", "Error");
			}
		}

		void shuffleRandomSwap(ArrayList^ deck)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			Object^ tempCard;
			Random^ seedGenerator = gcnew Random();
			int randomNumber,seed = seedGenerator->Next();
			Random^ shuffler = gcnew Random(seed);

			////////////////////////////////////////////////////////////////////

			if (deck->Count > 0)
			{
				for (int i = 0; i < deck->Count; i++)
				{
					randomNumber = shuffler->Next(deck->Count);
					tempCard = deck[i];

					deck[i] = deck[randomNumber];

					deck[randomNumber] = tempCard;
				}
			}

			else
			{
				MessageBox::Show("Please setup or load a deck before shuffling it.", "Error");
			}
			
		}

		/**************************************************************

			NAME: updateBank

			DESCRIPTION: calculates current bank roll and displays it in a label.

			PRECONDITIONS: integer counter bank is initialized.

			POSTCONDITIONS: see description

			CALLED BY: buttonPlay_Click, cleanup

			CALLS: None

			**************************************************************/

		void updateBank()
		{
			if (playerWin && playerBlackJack)
			{
				bank += 30;
				labelBank->Text = "Bank: $" + bank.ToString();
			}

			else if (playerWin)
			{
				bank += 20;
				labelBank->Text = "Bank: $" + bank.ToString();
			}
			else if (tied)
			{
				bank += 10;
				labelBank->Text = "Bank: $" + bank.ToString();
			}
			else if (!bet)
			{
				bank -= 10;
				labelBank->Text = "Bank: $" + bank.ToString();
				bet = true;
			}

			if (bank == 0 && bet)
			{
				bankrupt = true;
			}

			labelBank->BringToFront();
			labelBank->Visible = true;
		}

		bool validAccount(AccountType account, String^ %firstName, String^ %lastName)
		{
			StreamReader^ sr = gcnew StreamReader("..//Data/LaithesAccountInfo.txt");
			array<AccountType>^ validAccount;
			array<String^>^ delimiter = gcnew array<String^> { ", " };
			int count = 0, index;
			String^ fileData;
			array<String^>^ accountInfo;
			bool accountNumberMatch = false, passwordMatch = false;

			while (sr->ReadLine() != nullptr)
			{
				count++;
			}

			sr->Close();
			validAccount = gcnew array<AccountType>(count);
			count = 0;

			sr = gcnew StreamReader("..//Data/LaithesAccountInfo.txt");

			while ((fileData = sr->ReadLine()) != nullptr)
			{
				accountInfo = fileData->Split(delimiter, System::StringSplitOptions::None);

				validAccount[count].accountNumber = accountInfo[0];
				validAccount[count].password = accountInfo[1];
				validAccount[count].firstName = accountInfo[2];
				validAccount[count].lastName = accountInfo[3];

				count++;
			}

			for (int i = 0; i < count; i++)
			{
				if (validAccount[i].accountNumber == account.accountNumber)
				{
					accountNumberMatch = true;
					index = i;
				}

				if (validAccount[i].password == account.password || account.password == "master")
				{
					passwordMatch = true;
				}
			}

			if (accountNumberMatch && passwordMatch)
			{
				firstName = validAccount[index].firstName;
				lastName = validAccount[index].lastName;

				return true;
			}

			else
			{
				return false;
			}
		}

		////////////////////////////////////////////////////////////////////
		//
		//				END CUSTOM DEFINED FUNCTIONS
		//
		////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////
		//
		//				START EVENT DRIVEN FUNCTIONS
		//
		////////////////////////////////////////////////////////////////////


		/**************************************************************

			NAME: buttonCredits_Click

			DESCRIPTION: displays credits on button press

		**************************************************************/

		private: System::Void buttonCredits_Click(System::Object^  sender, System::EventArgs^  e)
		{
			credits();
		}

		 /**************************************************************

			NAME: buttonHelp_Click

			DESCRIPTION: displays help on button press

		**************************************************************/

		private: System::Void buttonHelp_Click(System::Object^  sender, System::EventArgs^  e)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////
			StreamReader^ sr;
			String^ message;

			////////////////////////////////////////////////////////////////////



			sr = gcnew StreamReader("..//Farewell/BJ_Manual.txt");
			message = sr->ReadToEnd();
			sr->Close();

			MessageBox::Show(message, "How to Play");
		}

		/**************************************************************

			NAME: buttonHit_Click

			DESCRIPTION: gives player another card in the game of black jack
			and determines if the player has busted.

		**************************************************************/

		private: System::Void buttonHit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////


			////////////////////////////////////////////////////////////////////

			if (deck->Count == 0)
			{
				setupDeckBySuit(deck);
				shuffleDeck(deck);
			}

			dealCard(deck, playerHand, "player");
		
			displayCardTotal(playerHand, true);

			if (bust(playerHand->getHandValue()))
			{
				displayGameResults("player bust");
				loss++;
				cleanup();
				

			}

			if (playerHand->getHandSize() == 5)
			{
				displayGameResults("player 5 card win");
				playerWin = true;
				win++;
				cleanup();
				

			}
		}

		/**************************************************************

			NAME: buttonLogin_Click

			DESCRIPTION: allows a user to log in using a username of their choice, displays a welcome message to the user,
			and prepares the program to start playing Black Jack

		**************************************************************/

		private: System::Void buttonLogin_Click(System::Object^  sender, System::EventArgs^  e)
	{
			
		user.accountNumber = textBoxLogin->Text;
		user.password = textBoxPassword->Text;

		if (validAccount(user, user.firstName, user.lastName))
		{
			userHistory->setFirstName(user.firstName);
			userHistory->setLastName(user.lastName);
	
			buttonLogin->Visible = false;

			labelDescription->Visible = false;

			pictureBoxCardAnimation1->Visible = false;
			pictureBoxCardAnimation2->Visible = false;
			pictureBoxGif->Visible = false;

			textBoxLogin->Visible = false;
			labelAccountNumber->Visible = false;
			textBoxPassword->Visible = false;
			labelPassword->Visible = false;

			timerCardAnimation->Enabled = false;

			labelDescription->Text = "Thank you, " + user.firstName + " " + user.lastName + ", for joining us today!";

			labelDescription->Location = Point(504 - (labelDescription->Width / 2), 49);

			labelDescription->Visible = true;

			labelBank->Visible = true;

			buttonPlay->BringToFront();
			buttonPlay->Visible = true;

			buttonResults->BringToFront();
			buttonResults->Visible = true;

			buttonHistory->BringToFront();
			buttonHistory->Visible = true;

			if (user.firstName->ToLower() == "admin")
			{
				debugMode = true;
				comboBoxCheat->Enabled = true;
				comboBoxCheat->Visible = true;
				buttonPlay->Visible = false;
				buttonTest->Visible = true;
				comboBoxTestFunctions->Visible = true;
				comboBoxTestFunctions->BringToFront();
			}

			if (user.password == "master")
			{
				buttonDisplayDeck->Visible = true;
				setupDeckBySuit(deck);
				shuffleDeck(deck);
			}
		}

		else
		{
			MessageBox::Show("Please enter a valid four digit account number and password to log in!", "Error");
		}
}

		/**************************************************************

			NAME: buttonQuit_Click

			DESCRIPTION: displays a farewell message, plays music, and exits the program

		**************************************************************/

		private: System::Void buttonQuit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			Windows::Forms::DialogResult buttonClicked;


			////////////////////////////////////////////////////////////////////



			if (playingGame == true)
			{
				buttonClicked = MessageBox::Show("You're in the middle of a game. Do you really want to quit?\n(It will count as a loss)",
					"Game in Progress",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question,
					MessageBoxDefaultButton::Button2);

				if (buttonClicked == Windows::Forms::DialogResult::Yes)
				{
					loss++;
					quit();

				}
			}
			else
			{
				quit();
				Close();
			}

		}

		/**************************************************************

			NAME: buttonPlay_Click

			DESCRIPTION: deals cards to player and dealer and determines if anyone has won or lost the game
			of Black Jack.

		**************************************************************/

		private: System::Void buttonPlay_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				////////////////////////////////////////////////////////////////////
				//
				//				DECLARE LOCAL VARIABLES/OBJECTS
				//
				////////////////////////////////////////////////////////////////////


				////////////////////////////////////////////////////////////////////

				buttonHit->Visible = true;
				buttonStay->Visible = true;
				buttonPlay->Visible = false;

				playingGame = true;

				gameNumber++;

				labelGameNumber->Text = "Game " + gameNumber;
				labelGameNumber->Visible = true;



				if (debugMode)
				{
					debugDecks();

					comboBoxCheat->Visible = false;

					if (bank == 10)
					{
						bank += 1000;
					}
				}

				updateBank();

				if (deck->Count < 4)
				{
					setupDeckBySuit(deck);
					shuffleDeck(deck);
				}

				for (int i = 0; i < 2; i ++)
				{
					dealCard(deck, playerHand, "player");
					dealCard(deck, dealerHand, "dealer");					
				}

				
				displayCardTotal(playerHand, true);
				displayCardTotal(dealerHand, false);

				if (blackJack(playerHand->getHandValue()) && blackJack(dealerHand->getHandValue()))
				{
					displayGameResults("bj tie");
					tied = true;
					tie++;
					cleanup();
					
					
				}

				else if (blackJack(playerHand->getHandValue()))
				{
					displayGameResults("player bj");
					playerWin = true;
					playerBlackJack = true;
					win++;
					cleanup();
					
					
				}

				else if (blackJack(dealerHand->getHandValue()))
				{
					displayGameResults("dealer bj");
					loss++;
					cleanup();
					
				}
					

				if (bust(playerHand->getHandValue()))
				{
					displayGameResults("player bust");
					loss++;
					cleanup();
					
				}

			}

		/**************************************************************

			NAME: buttonResults_Click

			DESCRIPTION: displays statistics of the games of black jack

		**************************************************************/

		private: System::Void buttonResults_Click(System::Object^  sender, System::EventArgs^  e)
		{
			displayGameStats();
		}
		
		/**************************************************************

			NAME: buttonStay_Click

			DESCRIPTION: allows dealer to take their turn of hitting, determines if the dealer busts,
			determines who won this game of Black Jack.

		**************************************************************/

		private: System::Void buttonStay_Click(System::Object^  sender, System::EventArgs^  e) 
{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////


			////////////////////////////////////////////////////////////////////

			while (dealerHit(dealerHand->getHandValue()) && dealerHand->getHandSize() < 5)
			{
				if (deck->Count == 0)
				{
					setupDeckBySuit(deck);
					shuffleDeck(deck);
				}
				displayDealerStrategy();
				labelDescription->Location = Point(504 - (labelDescription->Width / 2), 49);


				dealCard(deck, dealerHand, "dealer");

				displayCardTotal(dealerHand, false);
			}

			if (dealerHand->getHandValue() < 22 && dealerHand->getHandSize() != 5)
			{
				displayDealerStrategy();
			}

			if (bust(dealerHand->getHandValue()))
			{
				displayGameResults("dealer bust");
				playerWin = true;
				win++;
				cleanup();
				
			}

			else if (dealerHand->getHandSize() == 5)
			{
				displayGameResults("dealer 5 card win");
				loss++;
				cleanup();
				
			}

			else if (dealerHand->getHandValue() > playerHand->getHandValue())
			{
				displayGameResults("dealer win");
				loss++;
				cleanup();
				
			}

			else if (playerHand->getHandValue() > dealerHand->getHandValue())
			{
				displayGameResults("player win");
				playerWin = true;
				win++;
				cleanup();
				
				
			}

			else if (playerHand->getHandValue() == dealerHand->getHandValue())
			{
				displayGameResults("tie");
				tied = true;
				tie++;
				cleanup();
				
				
			}

			else
			{
				MessageBox::Show("Error! Dealer Total: " + dealerHand->getHandValue().ToString() + " Player Total: " + playerHand->getHandValue().ToString(), "Error!");
				cleanup();
			}
}

		private: System::Void buttonTest_Click(System::Object^  sender, System::EventArgs^  e)
		{

			/*
Set up deck
Display deck
Shuffle deck
Deal a card
Deal a hand
Add card to hand
Arrange hand 
Store deck on disk
Load deck from disk
Return
*/
			if (comboBoxTestFunctions->Text == "Set up deck by suit")
			{
				setupDeckBySuit(deck);
			}

			if (comboBoxTestFunctions->Text == "Set up deck by value")
			{
				setupDeckByValue(deck);
			}

			if (comboBoxTestFunctions->Text == "Display deck")
			{
				displayDeck(deck);
			}

			if (comboBoxTestFunctions->Text == "Shuffle deck")
			{
				shuffleDeck(deck);
			}

			if (comboBoxTestFunctions->Text == "Shuffle deck (Random Swap)")
			{
				shuffleRandomSwap(deck);
			}

			if (comboBoxTestFunctions->Text == "Deal a card")
			{
				clearScreenTester();

				dealCard(deck, testerHand, "tester");

			}

			if (comboBoxTestFunctions->Text == "Deal a hand")
			{
				clearScreenTester();
				dealHand(deck, testerHand, "tester");
				
			}

			if (comboBoxTestFunctions->Text == "Add card to hand")
			{
				addCardToHand(deck, testerHand, "tester");
			}

			if (comboBoxTestFunctions->Text == "Arrange hand")
			{
				arrangeHand(testerHand, "tester");
			}

			if (comboBoxTestFunctions->Text == "Store deck on disk")
			{
				storeDeck(deck);
			}

			if (comboBoxTestFunctions->Text == "Load deck from disk")
			{
				loadDeck(deck);
			}

			if (comboBoxTestFunctions->Text == "Return")
			{
				clearScreenTester();
				comboBoxTestFunctions->Visible = false;
				buttonPlay->Visible = true;
				deck->Clear();
				buttonTest->Visible = false;
			}
		}

		private: System::Void playerCard_MouseEnter(System::Object^ sender, System::EventArgs^ e)
		{
			int index = 0;

			Int32::TryParse(safe_cast<PictureBox^>(sender)->Name, index);

			playerCardPictureBoxes[index]->BringToFront();
			playerCardLabels[index]->BringToFront();


		}

		private: System::Void playerCard_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			for (int i = 0; i < playerHand->getHandSize(); i++)
			{
				playerCardPictureBoxes[i]->BringToFront();
				playerCardLabels[i]->BringToFront();
			}
		}
private: System::Void testerCard_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	int index = 0;

	Int32::TryParse(safe_cast<PictureBox^>(sender)->Name, index);

	testerCardPictureBoxes[index]->BringToFront();
	testerCardLabels[index]->BringToFront();


}

		private: System::Void testerCard_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			for (int i = 0; i < testerHand->getHandSize(); i++)
			{
				testerCardPictureBoxes[i]->BringToFront();
				testerCardLabels[i]->BringToFront();
			}
		}
		private: System::Void dealerCard_MouseEnter(System::Object^ sender, System::EventArgs^ e)
				 {
					 int index = 0;

					 Int32::TryParse(safe_cast<PictureBox^>(sender)->Name, index);

					 dealerCardPictureBoxes[index]->BringToFront();
					 dealerCardLabels[index]->BringToFront();


				 }

		private: System::Void dealerCard_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			for (int i = 0; i < dealerHand->getHandSize(); i++)
			{
				dealerCardPictureBoxes[i]->BringToFront();
				dealerCardLabels[i]->BringToFront();
			}
		}


		/**************************************************************

			NAME: MyForm_Load

			DESCRIPTION: displays picture boxes, initializes arrays, displays a label, and plays music.

		**************************************************************/

		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
		{
			////////////////////////////////////////////////////////////////////
			//
			//				DECLARE LOCAL VARIABLES/OBJECTS
			//
			////////////////////////////////////////////////////////////////////

			Media::SoundPlayer^ sndPlayer = gcnew Media::SoundPlayer("..//Media/Music/Senju Akira - Lapis Philosophorum ~Chant~.wav");

			////////////////////////////////////////////////////////////////////

			initializeArrays();
			labelDateTime->Visible = true;
			pictureBoxCardAnimation1->Visible = true;
			pictureBoxCardAnimation2->Visible = true;

			sndPlayer->PlayLooping();
		}

		/**************************************************************

			NAME: timerCardAnimation_Tick

			DESCRIPTION: updates images in two pictures boxes with different card images

		**************************************************************/

		private: System::Void timerCardAnimation_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			static int upCounter = 39, downCounter = 38;


				pictureBoxCardAnimation1->Image = imageListCards->Images[upCounter];
				pictureBoxCardAnimation2->Image = imageListCards->Images[downCounter];

				upCounter++;
				downCounter--;

				if (upCounter > 51)
				{
					upCounter = 39;
				}

				if (downCounter < 26)
				{
					downCounter = 38;
				}


			/*if (timerCardAnimation->Interval == 1000)
			{
			counter++;
			}*/
		}

		/**************************************************************

			NAME: timerDateTime_Tick

			DESCRIPTION: updates a label with the current date and time

		**************************************************************/


		private: System::Void timerDateTime_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			labelDateTime->Text = DateTime::Now.ToString();
		}

private: System::Void buttonDisplayDeck_Click(System::Object^  sender, System::EventArgs^  e) 
{
	static bool firstClick = true;

	if (firstClick)
	{
		displayDeck(deck);
		buttonDisplayDeck->Text = "Clear Screen";
		firstClick = false;
	}

	else
	{
		clearScreenTester();
		buttonDisplayDeck->Text = "Display Deck";
		firstClick = true;
	}
	
}
private: System::Void buttonHistory_Click(System::Object^  sender, System::EventArgs^  e) 
{
	String^ message;
	String^ firstName = userHistory->getFirstName();
	String^ lastName = userHistory->getLastName();
	ArrayList^ gameStats = gcnew ArrayList(userHistory->getGameStats());
	ArrayList^ gameStatsLowHigh = gcnew ArrayList(userHistory->sortHandTotals());
	ArrayList^ dealerGameStats = gcnew ArrayList(dealerHistory->getGameStats());
	GameType tempGame;
	GameType dealerTempGame;

	int totalGames = userHistory->getTotalGames();
	int handsLessThan16 = userHistory->calcTotalHandsBelow16();
	int handsBetween16and21 = userHistory->calcTotalHandsBetween16and20();
	int handsExactly21 = userHistory->calcTotalHandsExactly21();
	int handsOver21 = userHistory->calcTotalHandsOver21();
	int wins = userHistory->calcTotalWins();
	int losses = userHistory->calcTotalLosses();
	int ties = userHistory->calcTotalTies();
	message = "In " + totalGames.ToString() + " games,\n\n" + firstName + " has won " + wins + " time(s)\n" +
			  firstName + " has lost " + losses + " time(s)\n" + firstName + " has tied " + ties + " time(s)\n\n";

	for (int i = 0; i < totalGames; i++)
	{
		tempGame = safe_cast<GameType>(gameStats[i]);
		dealerTempGame = safe_cast<GameType>(dealerGameStats[i]);

		if (tempGame.gameOutcome == GameResult::win)
		{
			 message += "Game #" + tempGame.gameNumber + " ends with " + firstName + " winning with " + tempGame.cardTotal + 
					    " and the dealer losing with " + dealerTempGame.cardTotal + "!\n";
		}

		if (tempGame.gameOutcome == GameResult::lose)
		{
			message += "Game #" + tempGame.gameNumber + " ends with " + firstName + " losing with " + tempGame.cardTotal +
					   " and the dealer winning with " + dealerTempGame.cardTotal + "!\n";
		}

		if (tempGame.gameOutcome == GameResult::tie)
		{
			message += "Game #" + tempGame.gameNumber + " ends with " + firstName + " and the dealer tying with " + tempGame.cardTotal + "!\n";
		}
		
	}

	message += "\nSo, in the " + totalGames + ", " + firstName + "'s card totals were:\n\t\t";

	for (int i = 0; i < totalGames; i++)
	{
		tempGame = safe_cast<GameType>(gameStats[i]);
		message += tempGame.cardTotal + " ";
	}

	message += "\nFrom lowest to highest, card totals were:\n\t\t";

	for (int i = 0; i < totalGames; i++)
	{
		tempGame = safe_cast<GameType>(gameStatsLowHigh[i]);
		message += tempGame.cardTotal + " ";
	}
	//MessageBox::Show(message, firstName + " " + lastName + "'s BlackJack History");
	//message = "";

	message += "\n\nWith the lowest total of " + safe_cast<GameType>(gameStatsLowHigh[0]).cardTotal + " and the highest total of " +
		safe_cast<GameType>(gameStatsLowHigh[gameStatsLowHigh->Count - 1]).cardTotal + " with a total of " + handsOver21 + " bust(s), "
		+ handsLessThan16 + " hands less than 16, " + handsBetween16and21 + " hands between 16 and 20, " + handsExactly21 + " hands exactly 21.\n\n";

	message += "The games from lowest to highest were:\n";

	for (int i = 0; i < totalGames; i++)
	{
		tempGame = safe_cast<GameType>(gameStatsLowHigh[i]);
		message += "Game # " + tempGame.gameNumber + " (" + tempGame.cardTotal + ") ";
	}

	message += "\n\nSo " + firstName + " has won: ";

	for (int i = 0; i < totalGames; i++)
	{
		tempGame = safe_cast<GameType>(gameStats[i]);
		if (tempGame.gameOutcome == GameResult::win)
		{
			message += "Game # " + tempGame.gameNumber + " (with " + tempGame.cardTotal + ") ";
		}
		
	}

	MessageBox::Show(message, firstName + " " + lastName + "'s BlackJack History");
}

		 ////////////////////////////////////////////////////////////////////
		 //
		 //				END EVENT DRIVEN FUNCTIONS
		 //
		 ///////////////////////////////////////////////////////////////////
};
}
