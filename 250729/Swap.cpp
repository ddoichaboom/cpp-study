#pragma region Call by Reference - Swap

#include <iostream>

using namespace std;

void Swap(int* pA, int* pB);

int main()
{
	int a = 10, b = 20;
	cout << " a = " << a << " b = " << b << endl;

	Swap(&a, &b);
	cout << " a = " << a << " b = " << b << endl;

	return 0;
}

void Swap(int* pA, int* pB)
{
	int iTmp(0);
	iTmp = *pA;
	*pA = *pB;
	*pB = iTmp;
}

#pragma endregion