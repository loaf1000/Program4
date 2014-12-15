#ifndef GAMERESULTS_H
#define GAMERESULTS_H

using namespace System;
using namespace System::Collections;

enum class GameResult
{
	tie, lose, win
};

enum class HandResultType
{
	lessThan16, between16and20, exactly21, over21
};

value class GameType
{
public:
	int gameNumber;
	GameResult gameOutcome;
	int cardTotal;
	HandResultType handResult;
};

	


ref class GameResults
{
public:

	GameResults()
	{
		 _totalGames = 0;
		 _firstName = "default";
		 _lastName = "name";
		 _gameStats = gcnew ArrayList();

	}

	GameResults(ArrayList^ gameStats, String^ firstName, String^ lastName)
	{
		_totalGames = gameStats->Count;
		_firstName = firstName;
		_lastName = lastName;
		_gameStats = gcnew ArrayList(gameStats);
	}

	String^ getFirstName()
	{
		return _firstName;
	}

	String^ getLastName()
	{
		return _lastName;
	}

	int getTotalGames()
	{
		return _totalGames;
	}

	ArrayList^ getGameStats()
	{
		return _gameStats;
	}
	
	void setFirstName(String^ name)
	{
		_firstName = name;
	}

	void setLastName(String^ name)
	{
		_lastName = name;
	}

	void setGameStats(ArrayList^ gameStats)
	{
		_gameStats = gameStats;
	}

	void addGameResult(GameType game)
	{
		_gameStats->Add(game);
		_totalGames++;
	}

	int calcTotalHandsBelow16()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.handResult == HandResultType::lessThan16)
			{
				counter++;
			}
		}
		return counter;
	}

	int calcTotalHandsBetween16and20()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.handResult == HandResultType::between16and20)
			{
				counter++;
			}
		}
		return counter;
	}

	int calcTotalHandsExactly21()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.handResult == HandResultType::exactly21)
			{
				counter++;
			}
		}
		return counter;
	}

	int calcTotalHandsOver21()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.handResult == HandResultType::over21)
			{
				counter++;
			}
		}
		return counter;
	}

	int calcTotalWins()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.gameOutcome == GameResult::win)
			{ 
				counter++;
			}
		}
		return counter;
	}
	
	int calcTotalLosses()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.gameOutcome == GameResult::lose)
			{
				counter++;
			}
		}
		return counter;
	}

	int calcTotalTies()
	{
		int counter = 0;
		GameType game;
		for (int i = 0; i < _gameStats->Count; i++)
		{
			game = safe_cast<GameType>(_gameStats[i]);
			if (game.gameOutcome == GameResult::tie)
			{
				counter++;
			}
		}
		return counter;
	}

	ArrayList^ sortHandTotals()
	{
		ArrayList^ games = gcnew ArrayList(_gameStats);
		GameType tempGameInfo;
		GameType rhGame;
		GameType lhGame;

		bool switched;
		/*
		do                     psuedo code from http://visualgo.net/

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

			for (int i = 1; i < games->Count; i++)
			{
				lhGame = safe_cast<GameType>(games[i - 1]);

				rhGame = safe_cast<GameType>(games[i]);

				if (lhGame.cardTotal > rhGame.cardTotal)
				{
					tempGameInfo = lhGame;
					games[i - 1] = games[i];
					games[i] = tempGameInfo;

					switched = true;
				}
			}


		} while (switched);
		return games;
	}


	


private:
	int _totalGames;

	String^ _firstName;
	String^ _lastName;
	ArrayList^ _gameStats;
	

};


#endif // GameResults