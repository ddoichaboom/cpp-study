#include <iostream>

using namespace std;

//void Render(int pArray[][3], int iRow);
void Render(int (*pArray)[3], int iRow);

int main()
{
	int iArray[2][3] = { 1, 2, 3, 4, 5, 6 };

	cout << iArray << endl;
	cout << &iArray[0] << endl;
	cout << iArray[0] << endl;
	cout << &iArray[0][0] << endl;

	cout << "===========================================" << endl;
	cout << *iArray << endl;
	cout << **iArray << endl;
	cout << *iArray[0] << endl;

	int* p1 = &iArray[0][0];
	int* p2 = iArray[0];

	int(*pArray)[3] = iArray;

	cout << "===========================================" << endl;

	cout << p1 << endl;
	cout << p2 << endl;
	cout << pArray[1][1] << endl;

	cout << "===========================================" << endl;
	Render(iArray, 2);

	return 0;
}

// void Render(int pArray[][3], int iRow)
void Render(int (*pArray)[3], int iRow)
{
	cout << "2차원 배열 함수를 통한 포인터 활용 예시" << endl;
	for (int i = 0; i < iRow; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << pArray[i][j] << ' ';
		}
		cout << endl;
	}
}
