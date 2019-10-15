// This game is called snake
// You have to move the snake and eat the food to get larger
// You keep playing until you hit into your own snake in which the game will end
// The purpose of the code is to demonstrate the logic behind the game not to create a user friendly GUI

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


// define variables
bool gameOver;
const int width = 15;
const int height = 15;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

// creates the default setting for when the game starts
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

// creates the board using the values of width and height
// uses christmas colors to detect as well as to visually show the vertical positioning and movements of the caterpillar and the food
void Draw()
{
	system("cls");						// or system("clear");
	for (int i = 0; i < width + 2; i++)
	{
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "#";
			}
			if (i == y && j == x)
			{
				HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "F";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Score:" << score << endl;
}

// allows the user to use the W A S D keys to move the caterpillar 
// can leave the game by hitting the x letter
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

// how the caterpillar will change depending on the moves throughout the game
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//if (x > width || x < 0 || y > height || y < 0)
	//  gameOver = true;
	if (x >= width) 
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = width - 1;
	}
	if (y >= height)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = height - 1;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
		}
	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

//calls the functions
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);
	}
	return 0;
}