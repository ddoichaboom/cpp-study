#pragma region 5! = ? - ����Լ� ����

#include <iostream>

using namespace std;

int Factorial(int n);

int main()
{
	cout << "----------���丮��-----------" << endl;

	cout << "5! = " << Factorial(5) << endl;

	return 0;
}

int Factorial(int n)
{
	if (n == 0)
		return 1;

	return n * Factorial(n - 1);
}

#pragma endregion
