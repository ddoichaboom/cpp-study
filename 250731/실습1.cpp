#pragma region �ǽ� 1 - 2�� for�� & �迭 Ȱ��

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

// ���ǹ� �̹Ƿ� 2�� for�� ���ǿ� ���� ����
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

// 2�� for�� 
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