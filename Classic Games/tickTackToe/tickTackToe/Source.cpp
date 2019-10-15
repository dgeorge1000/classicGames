// Tic Tac Toe game which includes draw, input, clear, togglePlayer, win, and scoreboard functions (6 total)
// Allows you to play against another person

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

// makes the amount of rows, columns, the 'X', and both scores
const int row = 3;
const int col = 3;
char matrix[row][col] = { '1', '2', '3', '4', '5','6', '7', '8', '9' };
char player = 'X';
int n;
int score1, score2;


// clears the board of 'X' and 'O' 
void Clear()
{
	char clear[row][col] = { '1', '2', '3', '4', '5','6', '7', '8', '9' };
	system("cls");
	cout << "TIC TAC TOE BOARD" << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			matrix[i][j] = clear[i][j];
		}
		cout << endl << endl;
	}
}

// draws the current board
void Draw()
{
	system("cls");
	cout << "TIC TAC TOE BOARD" << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (matrix[i][j] == 'X')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << matrix[i][j] << "       ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (matrix[i][j] == 'O')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << matrix[i][j] << "       ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				cout << matrix[i][j] << "       ";
			}
		}
		cout << endl << endl;
	}
}

// places a tic in the desired position
void input()
{
	int a;
	char final;
	cout << "It's " << player << " turn. Press the number where you want to hit: " << endl;
	cin >> a;

	if (a == 1 && matrix[0][0] == '1')
	{
		matrix[0][0] = player;
	}
	else if (a == 2 && matrix[0][1] == '2')
	{
		matrix[0][1] = player;
	}
	else if (a == 3 && matrix[0][2] == '3')
	{
		matrix[0][2] = player;
	}
	else if (a == 4 && matrix[1][0] == '4')
	{
		matrix[1][0] = player;
	}
	else if (a == 5 && matrix[1][1] == '5')
	{
		matrix[1][1] = player;
	}
	else if (a == 6 && matrix[1][2] == '6')
	{
		matrix[1][2] = player;
	}
	else if (a == 7 && matrix[2][0] == '7')
	{
		matrix[2][0] = player;
	}
	else if (a == 8 && matrix[2][1] == '8')
	{
		matrix[2][1] = player;
	}
	else if (a == 9 && matrix[2][2] == '9')
	{
		matrix[2][2] = player;
	}
	else if (a < 0 || a > 9)
	{
		system("cls");
		Draw();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "That number is not in the field!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		input();
	}
	else
	{
		system("cls");
		Draw();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "Field is already in use try again!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		input();
	}

}

// switches players
void togglePlayer()
{
	if (player == 'X')
	{

		player = 'O';
	}
	else
	{
		player = 'X';
	}
}

// checks for a win
bool win()
{
	// check diagonals
	if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
	{
		return true;
	}
	if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)
	{
		return true;
	}


	// check horizontal and vertical victories
	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player)
		{
			return true;
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (matrix[0][j] == player && matrix[1][j] == player && matrix[2][j] == player)
		{
			return true;
		}
	}

	return false;
}

// prints the players win count
void scoreBoard()
{
	if (player == 'X')
	{
		score1++;
		togglePlayer();
	}
	else
	{
		score2++;
		togglePlayer();
	}
	cout << "   Player X: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << score1 << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "   Player O: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << score2 << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
	cout << endl;
}

// 2 switch cases to play again or quit
int main()
{
	n = 0;
	int choice = 1;
	while (1)
	{
		switch (choice)
		{
			case 1: 
				Draw();
				n++;
				input();
				Draw();
				if (win())
				{
					cout << " ----------------" << endl;
					cout << "|   GAME OVER    |" << endl;
					cout << " ----------------" << endl;
					scoreBoard();
					cout << "Press 1 to play again or 2 to quit" << endl;
					cin >> choice;
					Clear();
					Draw();
					break;
				}
				togglePlayer();
				if (win())
				{
					cout << "GAME OVER" << endl;
					scoreBoard();
 					cout << "Press 1 to play again or 2 to quit" << endl;
					cin >> choice;
					Clear();
					Draw();
					break;
				}
				else if (n == 9)
				{
					cout << "Its a Draw" << endl;
					cout << "Press 1 to play again or 2 to quit" << endl;
					cin >> choice;
					Clear();
					Draw();
					break;
				}
			case 2:
				break;

		}
	}
	system("pause");
	return 1;
}