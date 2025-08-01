#pragma region ½Ç½À 1 - 2Áß for¹® & ¹è¿­ È°¿ë

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

// ï¿½ï¿½ï¿½Ç¹ï¿½ ï¿½Ì¹Ç·ï¿½ 2ï¿½ï¿½ forï¿½ï¿½ ï¿½ï¿½ï¿½Ç¿ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
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

// 2ï¿½ï¿½ forï¿½ï¿½ 
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