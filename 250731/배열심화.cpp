#include <iostream>

using namespace std;

// void Render(int* pArray, int iSize);
void Render(int pArray[], int iSize);

int main()
{
	int iArray[3] = { 1, 2, 3 };

	// Render(&iArray[0], size(iArray));
	Render(iArray, sizeof(iArray) / sizeof(int));

	return 0;
}

// void Render(int* pArray, int iSize)
void Render(int pArray[], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		cout << pArray[i] << endl;
	}
}