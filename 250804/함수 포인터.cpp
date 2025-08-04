#include <iostream>

using namespace std;

int Plu(int Dst, int Src);
int Min(int Dst, int Src);
int Mul(int Dst, int Src);
int Div(int Dst, int Src);

int main()
{
	char op;
	int iDst(0), iSrc(0);
	int (*operation)(int, int) = NULL;

	cout << "연산 기호 선택 +, -, *, /" << endl;
	cout << "기호 입력 : ";
	cin >> op;

	cout << "첫 번째 숫자 입력 : ";
	cin >> iDst;

	cout << "두 번째 숫자 입력 : ";
	cin >> iSrc;

	if (op == '+')
	{
		operation = Plu;
	}
	else if (op == '-')
	{
		operation = Min;
	}
	else if (op == '*')
	{
		operation = Mul;
	}
	else if (op == '/')
	{
		operation = Div;
	}
	
	if (operation)
	{
		cout << iDst << " " << op << " " << iSrc << " = " << operation(iDst, iSrc) << endl;

	}
	else
	{
		cout << "잘못된 연산 기호입니다. " << endl;
	}

	return 0;
}

int Plu(int Dst, int Src)
{
	return Dst + Src;
}

int Min(int Dst, int Src)
{
	return Dst - Src;
}

int Mul(int Dst, int Src)
{
	return Dst * Src;
}

int Div(int Dst, int Src)
{
	return Dst / Src;
}