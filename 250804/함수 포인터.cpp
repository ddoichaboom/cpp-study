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

	cout << "���� ��ȣ ���� +, -, *, /" << endl;
	cout << "��ȣ �Է� : ";
	cin >> op;

	cout << "ù ��° ���� �Է� : ";
	cin >> iDst;

	cout << "�� ��° ���� �Է� : ";
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
		cout << "�߸��� ���� ��ȣ�Դϴ�. " << endl;
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