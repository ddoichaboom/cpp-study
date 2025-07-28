#pragma region ���丮�� - ����Լ�, ���� ���

#include <iostream>

using namespace std;

int GetNumber();
int Factorial(int n);
void FactorialResult(int n);


int main()
{
	int iNum(0);

	iNum = GetNumber();

	FactorialResult(iNum);

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
	{
		return 1;
	}

	return n * Factorial(n - 1);
}

void FactorialResult(int n)
{
	cout << "---------���丮��----------" << endl;

	if ((n == 1) || (n ==0)) 
	{
		cout << n << "!  = " << Factorial(n) << endl;
	}
	else 
	{
		cout << n << "! = ";

		for (int i = n; i  > 0 ; --i)
		{
			if (i == 1)
			{
				cout << i << " = " << Factorial(n) << endl;
			}
			else
			{
				cout << i << " * ";
			}
		}

	}
}

#pragma endregion