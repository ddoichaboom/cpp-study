#pragma region ���� �Է� - ���丮�� ��� �Լ�

#include <iostream>

using namespace std;

int GetNumber();
int Factorial(int n);

int main()
{
	int iNum(0);
	
	iNum = GetNumber();

	cout << "--------���丮��---------" << endl;
	cout << "\t" << iNum << "! = " << Factorial(iNum) << "\t" << endl;


	return 0;
}

int GetNumber()
{
	int iInput(0);

	cout << "���ڸ� �Է��ϼ��� :";
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