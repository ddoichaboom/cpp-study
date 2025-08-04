#include <iostream>

using namespace std;

void Reset();
void InitArray(int (*pArray)[5], int iSize);
void PrintArray(int (*pArray)[5], int iSize);
void FindZeroPosition(int (*pArray)[5], int iSize, int* pX, int* pY);

int main()
{
	const int iSize = 5;
	int iArray[5][5] = {};
	int iInput(0), iX(0), iY(0);
	bool bChoice = true;

	InitArray(iArray, iSize);
	PrintArray(iArray, iSize);

	while (bChoice)
	{
		system("cls");

		PrintArray(iArray, iSize);
		cout << "숫자 0을 이동할 수 있습니다." << endl;
		cout << "2 - 아래 / 4 - 왼쪽 / 6 - 오른쪽 / 8 - 위 / 5 - 종료" << endl;
		cout << "입력 : ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "숫자만 입력하세요!" << endl;
			Reset();

			system("pause");

			continue;
		}
		
		FindZeroPosition(iArray, iSize, &iX, &iY);

		switch (iInput)
		{
		case 2:
			if (iX == (iSize - 1))
			{
				cout << "0이 바닥에 위치했습니다." << endl;

				system("pause");

				break;
			}
			else
			{
				swap(iArray[iX][iY], iArray[iX + 1][iY]);
				break;
			}
		case 4:
			if (iY == 0)
			{
				cout << "0이 좌측 벽에 위치했습니다." << endl;

				system("pause");

				break;
			}
			else
			{
				swap(iArray[iX][iY], iArray[iX][iY - 1]);
				break;
			}
		case 6:
			if (iY == (iSize - 1))
			{
				cout << "0이 우측 벽에 위치했습니다." << endl;

				system("pause");

				break;
			}
			else
			{
				swap(iArray[iX][iY], iArray[iX][iY + 1]);
				break;
			}
		case 8:
			if (iX == 0)
			{
				cout << "0이 최상단 벽에 위치했습니다." << endl;

				system("pause");

				break;
			}
			else
			{
				swap(iArray[iX][iY], iArray[iX - 1][iY]);
				break;
			}
		case 5:
			cout << "프로그램을 종료합니다 " << endl;
			bChoice = false;
			break;

		default:
			cout << "지정된 숫자 중에서 입력해주세요." << endl;

			system("pause");

			break;
		}
	}

	return 0;
}

void InitArray(int (*pArray)[5], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			pArray[i][j] = (i * 5) + j;
		}
	}
}

void PrintArray(int (*pArray)[5], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cout << pArray[i][j] << "\t";
		}
		cout << endl;
	}
}



void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void FindZeroPosition(int (*pArray)[5], int iSize, int* pX, int* pY)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (pArray[i][j] == 0)
			{
				*pX = i;
				*pY = j;
				return;
			}
		}
	}
}
