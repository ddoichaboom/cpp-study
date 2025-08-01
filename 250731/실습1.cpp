#pragma region 실습 1 - 2중 for문 & 배열 활용

#include <iostream>

using namespace std;

void InitArray(int pArray[], int iSize);
void PrintArray(int pArray[]);

int main()
{
	int iArray[25] = { };

	InitArray(iArray, size(iArray));
	PrintArray(iArray);

	return 0;
}

void InitArray(int pArray[], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		pArray[i] = i + 1;
	}
}

//void PrintArray(int pArray[], int iSize)
//{
//	for (int i = 0; i < iSize; ++i)
//	{
//		if (((i + 1) % 5) == 0)
//		{
//			cout << pArray[i] << endl;
//		}
//		else
//		{
//			cout << pArray[i] << "\t";
//		}
//	}
//}

void PrintArray(int pArray[])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int index = i * 5 + j;

			cout << pArray[index] << "\t";

		}
		cout << endl;
	}
}

#pragma endregion