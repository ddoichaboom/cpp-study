#include <iostream>

using namespace std;

void InitArray(int (*pArray)[5], int iRow, int iCol);
void PrintArray(int (*pPlayer)[5], int (*pCom)[5], int iRow, int iCol);
void MixArray(int (*pArray)[5], int iRow, int iCol);
void Reset();
void CheckBingo(int (*pArray)[5], int iRow, int iCol, int* pHor, int* pVer, int* pDiaR, int* pDiaL, int* pBingo);
void CheckArray(int (*pPlayer)[5], int (*pCom)[5], int iRow, int iCol, int* pInput, bool* pTurn);
void GetRandomNumerByCom(int* pCInput);

int main()
{
	srand(unsigned(time(NULL)));

	int iPlayer[5][5] = {};
	int iCom[5][5] = {};
	const int iCol = 5;
	const int iRow = 5;

	// iHor : 가로, iVer : 세로, iDia : 대각선
	int iInput(0), iHor(0), iVer(0), iDiaR(0), iDiaL(0), iPBingo(0), iCBingo(0), iCInput(0);
	bool bTurn = true, bExist = false;

	InitArray(iPlayer, iRow, iCol);
	InitArray(iCom, iRow, iCol);
	MixArray(iPlayer, iRow, iCol);
	MixArray(iCom, iRow, iCol);


	while ((iPBingo < 5) && (iCBingo < 5))
	{
		system("cls");

		cout << "==================================== 5 x 5 빙고 게임  ====================================" << endl;
		PrintArray(iPlayer,iCom, size(iPlayer), 5);

		if (bTurn)
		{
			cout << "플레이어 턴" << endl;
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

			CheckArray(iPlayer, iCom, iRow, iCol, &iInput, &bExist);

			if (bExist)
			{
				cout << " 이미 입력하신 숫자입니다." << endl;
				Reset();

				system("pause");

				continue;
			}

			cout << "입력한 숫자 : " << iInput << endl;

			CheckBingo(iPlayer, iRow, iCol, &iHor, &iVer, &iDiaR, &iDiaL, &iPBingo);
			CheckBingo(iCom, iRow, iCol, &iHor, &iVer, &iDiaR, &iDiaL, &iCBingo);

			cout << "현재 스코어" << endl;
			cout << "플레이어 : " << iPBingo << " 빙고" << endl;
			cout << "컴퓨터 : " << iCBingo << " 빙고" << endl;

			cout << "플레이어 턴 종료" << endl;

			bTurn = false;

			system("pause");
		}
		else if (!bTurn)
		{
			cout << " 컴퓨터 턴" << endl;

			GetRandomNumerByCom(&iCInput);

			CheckArray(iPlayer, iCom, iRow, iCol, &iCInput, &bExist);

			if (bExist)
			{
				cout << " 이미 입력된 숫자입니다." << endl;
				cout << "컴퓨터 재 선택" << endl;

				system("pause");

				continue;
			}

			cout << "컴퓨터 선택 : " << iCInput << endl;

			CheckBingo(iPlayer, iRow, iCol, &iHor, &iVer, &iDiaR, &iDiaL, &iPBingo);
			CheckBingo(iCom, iRow, iCol, &iHor, &iVer, &iDiaR, &iDiaL, &iCBingo);

			cout << "현재 스코어" << endl;
			cout << "컴퓨터 : " << iCBingo << " 빙고" << endl;
			cout << "플레이어 : " << iPBingo << " 빙고" << endl;

			cout << "컴퓨터 턴 종료" << endl;

			bTurn = true;

			system("pause");
		}
	}

	system("cls");

	if ((iPBingo == 5) && (iCBingo != 5))
	{
		cout << "플레이어 승리!" << endl;
		PrintArray(iPlayer, iCom, iRow, iCol);
		cout << "-----빙고 게임을 종료합니다.-----" << endl;
	}
	else if ((iPBingo != 5) && (iCBingo == 5))
	{
		cout << "컴퓨터 승리!" << endl;
		PrintArray(iPlayer, iCom, iRow, iCol);
		cout << "-----빙고 게임을 종료합니다.-----" << endl;
	}
	else if ((iPBingo == 5) && (iCBingo == 5))
	{
		cout << "무승부!" << endl;
		PrintArray(iPlayer, iCom, iRow, iCol);
		cout << "-----빙고 게임을 종료합니다.-----" << endl;
	}

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

void PrintArray(int (*pPlayer)[5], int (*pCom)[5], int iRow, int iCol)
{
	cout << "==========플레이어 빙고===========\t \t\t===========컴퓨터 빙고============" << endl;

	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			if (pPlayer[i][j] == 0)
			{
				cout << "*" << "\t";
			}
			else
			{
				cout << pPlayer[i][j] << "\t";
			}
		}

		cout << "\t\t";

		for (int j = 0; j < iCol; ++j)
		{
			if (pCom[i][j] == 0)
			{
				cout << "*" << "\t";
			}
			else
			{
				cout << pCom[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

void MixArray(int (*pArray)[5], int iRow, int iCol)
{
	int iRandom = rand() % 100;

	for (int k = 0; k < iRandom; ++k)
	{
		int iIndexR1 = rand() % 5;
		int iIndexC1 = rand() % 5;
		int iIndexR2 = rand() % 5;
		int iIndexC2 = rand() % 5;
		
		swap(pArray[iIndexR1][iIndexC1], pArray[iIndexR2][iIndexC2]);
	}
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void CheckArray(int (*pPlayer)[5], int (*pCom)[5], int iRow, int iCol, int* pInput, bool* pExist)
{
	*pExist = true;

	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			if (pPlayer[i][j] == *pInput)
			{
				pPlayer[i][j] = 0;
				*pExist = false;
			}
		}
	}

	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			if (pCom[i][j] == *pInput)
			{
				pCom[i][j] = 0;
				*pExist = false;
			}
		}
	}
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

void GetRandomNumerByCom(int* pCInput)
{
	*pCInput = (rand() % 25) + 1;
}
