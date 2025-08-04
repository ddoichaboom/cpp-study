#include <iostream>

using namespace std;

const int ROW = 20;
const int COL = 10;

struct Player
{
	int iRow;
	int	iCol;
};

struct Enemy
{
	int iRow;
	int iCol;
};

void InitArray(char (*pBoard)[COL], int iSize);
void PrintArray(char (*pBoard)[COL], int iSize);


int main()
{
	const int iSize = 20;
	char cBoard[ROW][COL] = { NULL };

	InitArray(cBoard, iSize);
	PrintArray(cBoard, iSize);



	return 0;
}

void InitArray(char (*pBoard)[COL], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			pBoard[i][j] = '*';
		}
	}
}

void PrintArray(char (*pBoard)[COL], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			cout << pBoard[i][j] << "\t";
		}
		cout << endl;
	}
}

