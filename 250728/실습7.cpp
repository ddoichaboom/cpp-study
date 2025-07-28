#pragma region 정수 입력 - 팩토리얼 재귀 함수

#include <iostream>

using namespace std;

int GetNumber();
int Factorial(int n);

int main()
{
	int iNum(0);
	
	iNum = GetNumber();

	cout << "--------팩토리얼---------" << endl;
	cout << "\t" << iNum << "! = " << Factorial(iNum) << "\t" << endl;


	return 0;
}

int GetNumber()
{
	int iInput(0);

	cout << "숫자를 입력하세요 :";
	cin >> iInput;

	return iInput;
}

int Factorial(int n)
{
	if (n == 0)
		return 1;

	return n * Factorial(n - 1);
}

#pragma endregion