#pragma region 로또 번호 추첨기(보너스 번호 제외)

#include <iostream>

using namespace std;

void InitArray(int pArray[], int iSize);
void GetRandomNumber(int** ppRandom);
void GetLottoNumber(int* pRandom, int pArray[], int pResult[], int iSizeA, int iSizeR);
void BubbleSort(int pResult[], int iSizeR);
void PrintResult(int pResult[], int iSizeR);

int main()
{
	int iRandom(0);
	int iArray[45] = { };
	int iResult[6] = { };

	InitArray(iArray, size(iArray));

	cout << "=============로또 번호 추첨기=============" << endl;



	for (int i = 0; i < 5; ++i)
	{
		GetLottoNumber(&iRandom, iArray, iResult, size(iArray), size(iResult));
		PrintResult(iResult, size(iResult));
	}



	return 0;
}

void InitArray(int pArray[], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		pArray[i] = i + 1;
	}
}

void GetRandomNumber(int** ppRandom)
{
	srand(unsigned(time(0)));

	**ppRandom = rand() % 45;
}

void GetLottoNumber(int* pRandom, int pArray[], int pResult[], int iSizeA, int iSizeR)
{
	int iNum(iSizeA);
	int i(0);

	while (i < iSizeR)
	{
		GetRandomNumber(&pRandom);

		if (*pRandom != iNum)
		{
			pResult[i] = pArray[*pRandom];
			iNum = *pRandom;
			++i;
		}

	}

	BubbleSort(pResult, iSizeR);
}

void BubbleSort(int pResult[], int iSizeR)
{
	int iSwap(0);

	for (int i = 0; i < iSizeR; ++i)
	{
		for (int j = i + 1; j < iSizeR; ++j)
		{
			if (pResult[i] > pResult[j])
			{
				iSwap = pResult[j];
				pResult[j] = pResult[i];
				pResult[i] = iSwap;
			}
		}
	}
}

void PrintResult(int pResult[], int iSizeR)
{
	for (int i = 0; i < iSizeR; ++i)
	{
		cout << pResult[i] << "\t";
	}
	cout << endl;
}

#pragma endregion