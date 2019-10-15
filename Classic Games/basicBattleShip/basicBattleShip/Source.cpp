// This code plays the battleship game with a twist
// Instead of versusing the computer turn after turn, this game goes to the end and
// whichever player has the least amount of turns to sink all ships wins!

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

// defines constants
const int rows = 5;
const int elements = 5;
int maxShips = 5;
int matrix[rows][elements];
int answer[rows][elements];
int score, scoreComputer;

// creates a clear board to start the game by setting eaach array position to 0
void Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			matrix[i][j] = 0;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// draws the board at the beginning of the game by printing '0' at each array position
void draw()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << "0  ";
		}
		cout << endl << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//displays the board
void Show()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (matrix[i][j] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << matrix[i][j] << "  ";
			}
			if (matrix[i][j] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << matrix[i][j] << "  ";
			}
			if (matrix[i][j] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << matrix[i][j] << "  ";
			}
		}
		cout << endl << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


// returns an int of the player's number of ships
int NumberOfShips()
{
	int c = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (matrix[i][j] == 1)

			{
				c++;
			}
		}
	}
	return c;
}

// returns an int of the computer's number of ships
int computerNumberOfShips()
{
	int c = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (answer[i][j] == 1)

			{
				c++;
			}
		}
	}
	return c;
}

// sets the computer's ships randomly on the board
void setShips()
{
	int s = 0;
	while (s < maxShips)
	{
		const int x = rand() % rows;
		const int y = rand() % elements;
		if (matrix[x][y] != 1)
		{
			matrix[x][y] = 1;
			answer[x][y] = 1;
			s++;
		}
	}
}

// function for the player to attack the computer's board
bool Attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

// function for the computer to attack the player's board
bool computerAttack(int x, int y)
{
	if (answer[x][y] == 1)
	{
		answer[x][y] = 2; 
		return true;
	}
	return false;
}

// detects if a hit as occured
void hit(int x, int y)
{
	if (matrix[x][y] == '1')
	{

	}
}

// prints out the final scoreboard of amount of turns
void scoreboard()
{
	cout << "It took you " << score << " turns" << endl;
}

// initials the computer to attack if the player has not won already
int computer()
{
	while(computerNumberOfShips() != 0)
	{
		int a = rand() % rows;
		int b = rand() % elements;
		computerAttack(a, b);
		scoreComputer++;
	}
	return scoreComputer;
}

int main()
{
	cout << "You are versusing the computer!! 0,0 is the top left position and " << rows - 1 << "," << elements - 1 << " is the bottom left position" << endl;
	cout << "Keep playing and in the end whoever took the least amount of turns to sink all battleships WINS!" << endl;
	srand(time(NULL));
	Clear();
	draw();
	setShips();
	int pos1, pos2, result;
	char quit;

	// play the game until one person has no ships remaining
	while (1)
	{
		cout << "Input where you want to attack: " << endl;
		cout << "Number of remaining ships: " << NumberOfShips() << endl;
		cin >> pos1;
		cin >> pos2;
		if (Attack(pos1, pos2))
		{
			cout << "You got a ship!" << endl;
		}
		else
		{
			cout << "Missed!"<< endl;
		}
		score++;
		if (NumberOfShips() == 0)
		{
			break;
		}
	}

	// shows the final result and winner
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	cout << "GAME OVER" << endl;
	scoreboard();
	Show(); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (computer() / 2 > score)
	{
		cout << "You win! The computer took " << scoreComputer / 2 << " turns, and you took " << score << " turns" << endl;
		Show();
	}
	else if (computer () / 2 < score)
	{
		cout << "You lose! The computer took " << scoreComputer / 2 << " turns, and you took " << score << " turns" << endl;
		Show();
	}
	else
	{
		cout << "TIE!!!!" << endl;
		Show();
	}
	system("pause");
	return 0;
}