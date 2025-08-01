#include <iostream>

using namespace std;

void InitArray(int (*pArray)[3], int iRow);
void PrintArray(int (*pArray)[3], int iRow, int iCol);
void RotateArray(int (*pArray)[3], int (*pResult)[3], int iRow, int iCol);
void UpdateArray(int (*pArray)[3], int (*pResult)[3], int iRow, int iCol);

int main()
{
	int iArray[3][3] = {};
	int iResult[3][3] = {};


	InitArray(iArray, size(iArray));
	PrintArray(iArray, size(iArray), 3);


	for (int i = 1; i < 5; ++i)
	{

	cout << "========" << i *90 << "µµ È¸Àü=========" << endl;

	RotateArray(iArray, iResult, size(iArray), 3);

	PrintArray(iResult, size(iResult), 3);

	UpdateArray(iArray, iResult, size(iResult), 3);
	}


	return 0;
}

void InitArray(int (*pArray)[3], int iRow)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iRow; ++j)
		{
			pArray[i][j] = (i * iRow) + j + 1;
		}
	}
}

void PrintArray(int (*pArray)[3], int iRow, int iCol)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			cout << pArray[i][j] << '\t';
		}
		cout << endl;
	}
}

void RotateArray(int (*pArray)[3], int (*pResult)[3], int iRow, int iCol)
{
	
	for (int i = 0; i < iRow; ++i)
	{
		int iIndex = iRow - 1 - i;

		for (int j = 0; j < iCol; ++j)
		{
			pResult[j][iIndex] = pArray[i][j];
		}
	}
}

void UpdateArray(int (*pArray)[3], int (*pResult)[3], int iRow, int iCol)
{
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			pArray[i][j] = pResult[i][j];
		}
	}
}

