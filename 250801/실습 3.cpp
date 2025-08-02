#include <iostream>

using namespace std;

void InitArray(int (*pArray)[5], int iRow, int iCol);
void PrintArray(int (*pArray)[5], int iRow, int iCol);
void Reset();
bool CheckArray(int (*pArray)[5], int iRow, int iCol, int iInput);
void CheckBingo(int (*pArray)[5], int iRow, int iCol, int* pHor, int* pVer, int* pDiaR, int* pDiaL, int* pBingo);

int main()
{
	int iArray[5][5] = {};
	const int iCol = 5;
	int iInput(0), iHor(0), iVer(0), iDiaR(0), iDiaL(0), iBingo(0);				// iHor : 가로, iVer : 세로, iDia : 대각선

	InitArray(iArray, size(iArray), 5);

	while (iBingo < 5)
	{
		system("cls");

		PrintArray(iArray, size(iArray), 5);

		cout << "숫자를 입력하세요 : ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "숫자만 입력하세요!" << endl;
			Reset();

			system("pause");

			continue;
		}
		else if ((iInput < 1) || (iInput > 25))
		{
			cout << "1 ~ 25 사이의 숫자만 입력하세요!" << endl;
			Reset();

			system("pause");

			continue;
		}

		if (CheckArray(iArray, size(iArray), iCol, iInput))
		{
			cout << "이미 입력했던 숫자입니다." << endl;
			Reset();

			system("pause");

			continue;
		}
		else
		{
			cout << "입력한 숫자 : " << iInput << endl;
		}

		CheckBingo(iArray, size(iArray), iCol, &iHor, &iVer, &iDiaR, &iDiaL, &iBingo);
		cout << "현재 " << iBingo << "빙고 입니다." << endl;

		system("pause");
	}

	system("cls");

	cout << "5 빙고를 달성하셨습니다." << endl;
	PrintArray(iArray, size(iArray), iCol);
	cout << "-----빙고 게임을 종료합니다.-----" << endl;

	return 0;
}

void InitArray(int (*pArray)[5], int iRow, int iCol)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			pArray[i][j] = (i * 5) + j + 1;
		}
	}
}

void PrintArray(int (*pArray)[5], int iRow, int iCol)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			if (pArray[i][j] == 0)
			{
				cout << "*" << "\t";
				continue;
			}
			else
			{
				cout << pArray[i][j] << "\t";
			}
		}
		cout << endl;
	}
}



void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

bool CheckArray(int (*pArray)[5], int iRow, int iCol, int iInput)
{
	int iIndexR = (iInput - 1) / 5, iIndexC = (iInput - 1) % 5;

	if (pArray[iIndexR][iIndexC] == 0)
	{
		return true;
	}

	pArray[iIndexR][iIndexC] = 0;
	return false;


}

void CheckBingo(int (*pArray)[5], int iRow, int iCol, int* pHor, int* pVer, int* pDiaR, int* pDiaL, int* pBingo)
{
	*pBingo = 0, * pDiaR = 0, * pDiaL = 0;

	for (int i = 0; i < iRow; ++i)
	{	
		if (pArray[i][i] == 0)
		{
			(*pDiaR)++;

			*pHor = 0, * pVer = 0;

			for (int j = 0; j < iCol; ++j)
			{
				if (pArray[i][j] == 0)
				{
					(*pHor)++;
				}

				if (pArray[j][i] == 0)
				{
					(*pVer)++;
				}
			}
			
			if ((*pHor) == 5)
			{
				(*pBingo)++;
			}

			if ((*pVer) == 5)
			{
				(*pBingo)++;
			}
		}

		if (pArray[i][4 - i] == 0)
		{
			(*pDiaL)++;
		}

			
	}

	if ((*pDiaR) == 5)
	{
		(*pBingo)++;
	}

	if ((*pDiaL) == 5)
	{
		(*pBingo)++;
	}
}