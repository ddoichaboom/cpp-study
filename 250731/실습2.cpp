#pragma region 로또 번호 추첨기(보너스 번호 제외)

#include <iostream>

using namespace std;

void InitArray(int pArray[], int iSize);
void GetRandomNumber(int* pRandom);
void GetLottoNumber(int* pRandom, int pArray[], int pResult[], int iSizeA, int iSizeR);
void BubbleSort(int pResult[], int iSizeR);
void PrintResult(int pResult[], int iSizeR);

int main()
{
	srand(unsigned(time(0)));

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

void GetRandomNumber(int* pRandom)
{
	*pRandom = rand() % 45;
}

void GetLottoNumber(int* pRandom, int pArray[], int pResult[], int iSizeA, int iSizeR)
{

	for (int i = 0; i < iSizeR;)
	{
		GetRandomNumber(pRandom);

		bool bExist = false;

		for (int j = 0; j < i; ++j)
		{
			if (pResult[j] == pArray[*pRandom])
			{
				bExist = true;
				break;
			}
		}

		if (!bExist)
		{
			pResult[i] = pArray[*pRandom];
			++i;
		}

	}

	BubbleSort(pResult, iSizeR);
}

void BubbleSort(int pResult[], int iSizeR)
{
	int iSwap(0);

	for (int i = 0; i < iSizeR - 1; ++i)
	{
		for (int j = 0; j < iSizeR - 1 - i; ++j)
		{
			if (pResult[j] > pResult[j+1])
			{
				iSwap = pResult[j+1];
				pResult[j+1] = pResult[j];
				pResult[j] = iSwap;
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