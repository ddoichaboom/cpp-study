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
		cout << "���� 0�� �̵��� �� �ֽ��ϴ�." << endl;
		cout << "2 - �Ʒ� / 4 - ���� / 6 - ������ / 8 - �� / 5 - ����" << endl;
		cout << "�Է� : ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "���ڸ� �Է��ϼ���!" << endl;
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
				cout << "0�� �ٴڿ� ��ġ�߽��ϴ�." << endl;

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
				cout << "0�� ���� ���� ��ġ�߽��ϴ�." << endl;

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
				cout << "0�� ���� ���� ��ġ�߽��ϴ�." << endl;

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
				cout << "0�� �ֻ�� ���� ��ġ�߽��ϴ�." << endl;

				system("pause");

				break;
			}
			else
			{
				swap(iArray[iX][iY], iArray[iX - 1][iY]);
				break;
			}
		case 5:
			cout << "���α׷��� �����մϴ� " << endl;
			bChoice = false;
			break;

		default:
			cout << "������ ���� �߿��� �Է����ּ���." << endl;

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
