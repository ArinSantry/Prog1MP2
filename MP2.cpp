/* File: MP2.cpp
*  Author: Arin Santry
*  Date Started: 10/5/18
*  Date Due: 10/18/18
*  Desc: Play a game of pigs with a computer
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// find if a single 1 is rolled and turn score is lost
bool isTurnScoreLost(int die1value, int die2value); 
// find if two 1s are rolled and game is lost
bool isGameScoreLost(int die1value, int die2value); 
int rollDie(void); // random number generator (1-6)
char getUserInput(void); // get input to continue playing or stop

int main(void)
{
	int scoreHuman = 0; // score of player
	int scoreComp = 0; // score of computer
	bool passHuman = false; // indicate if player passes
	bool passComp = false; // indicate if computer passes
	srand((unsigned)time(0));


	while (true)
	{
		// roll dice for player
		int humanDie1;
		int humanDie2;
		int compDie1;
		int compDie2;

		if (!passHuman)
		{
			humanDie1 = rollDie();
			humanDie2 = rollDie();
		}

		// roll until the computer reaches a total score of 23
		if (scoreComp <= 23)
		{
			// roll dice for computer
			compDie1 = rollDie();
			compDie2 = rollDie();
		}
		else
		{
			passComp = true; // computer passes
		}

		// does player pass?
		if (!passHuman) // player rolls
			cout << "Your die 1: " << humanDie1 << "   Your die 2: " 
				 << humanDie2 << endl;
		else // player does not roll
			cout << "You pass\n";

		// does computer pass?
		if (!passComp) //computer rolls
			cout << "Opponent's die 1: " << compDie1 << "   Opponent's die 2: " 
				 << compDie2 << endl;
		else //computer does not roll
			cout << "Your opponent passes\n";

		if (!passHuman)
		{
			// calculate human score
			if (isGameScoreLost(humanDie1, humanDie2))
			{
				// if two 1s are rolled, the player's score is reset to 0
				scoreHuman = 0;
			}
			else if (isTurnScoreLost(humanDie1, humanDie2))
			{
				// if a single 1 is rolled, no points are scored
			}
			else
			{
				// if a 1 is not rolled, add dice to total score
				scoreHuman += humanDie1 + humanDie2;
			}
		}

				
		// calculate computer score
		if (!passComp)
		{
			if (isGameScoreLost(compDie1, compDie2))
			{
				// if two 1s are rolled, the player's score is reset to 0
				scoreComp = 0;
			}
			else if (isTurnScoreLost(compDie1, compDie2))
			{
				// if a single 1 is rolled, no points are scored
			}
			else
			{
				// if a 1 is not rolled, add dice to total score
				scoreComp += compDie1 + compDie2;
			}
		}

		cout << "Player score: " << scoreHuman << endl;
		cout << "Computer score: " << scoreComp << endl;

		// continue playing?
		if (getUserInput() == 's')
		{
			passHuman = true; // player passes if they choose 's'
		}
		else
			passHuman = false; // player does not pass if they choose 'r'

		cout << endl;

		if (scoreComp >= 100 || scoreHuman >= 100)
			break;
	}

	if (scoreHuman > scoreComp)
		cout << "\nYou win!\n";
	if (scoreHuman < scoreComp)
		cout << "\nComputer wins\n";
	if (scoreHuman == scoreComp)
		cout << "\nIt's a tie!\n";
}

// function definitions:

// isTurnScoreLost: check if a single 1 is rolled
// Parameters: int die1value, int die2value - individual die values
// Returns: true if a single 1 is rolled, false if not
bool isTurnScoreLost(int die1value, int die2value)
{
	if ((die1value == 1 || die2value == 1))
		return true;
	else
		return false;
}

// isGameScoreLost: check if two 1s are rolled
// Parameters: int die1value, int die2value - individual die values
// Returns: true if two 1s are rolled, false if not
bool isGameScoreLost(int die1value, int die2value)
{
	if (die1value == 1 && die2value == 1)
		return true;
	else
		return false;
}

// rollDie: simulates the rolling of a 6-sided die
// Parameters: none
// Returns: integer value of the rolled die
int rollDie(void)
{
	const int NUM_SIDES = 6;
	const int LOWEST_VALUE = 1;
	return rand() % NUM_SIDES + LOWEST_VALUE;
}

// getUserInput: get input r or s
// Parameters: none
// Return: char input r (continue playing) or s (stop)
char getUserInput(void)
{
	char input;
	cout << "Roll again (r) or stop (s)? ";
	cin >> input;

	return input;
}