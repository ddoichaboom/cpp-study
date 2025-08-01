#pragma region �ǽ� 1 - 2�� for�� & 2���� �迭 Ȱ�� 1 ~ 25 ���

#include <iostream>

using namespace std;

void InitArray(int (*pArray)[5], int iRow);
void PrintArray(int pArray[][5], int iRow);


int main()
{
	int iArray[5][5] = { };

	InitArray(iArray, size(iArray));
	PrintArray(iArray, size(iArray));

	return 0;
}

void InitArray(int (*pArray)[5], int iRow)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			pArray[i][j] = (i * 5) + (j + 1);
		}
	}
}

void PrintArray(int pArray[][5], int iRow)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << pArray[i][j] << '\t';
		}
		cout << endl;
	}
}

#pragma endregion