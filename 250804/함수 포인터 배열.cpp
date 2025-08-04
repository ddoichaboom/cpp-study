#include <iostream>

using namespace std;

int Plu(int Dst, int Src);
int Min(int Dst, int Src);
int Mul(int Dst, int Src);
int Div(int Dst, int Src);



int main()
{
	int(*operArr[4])(int, int) = { Plu, Min, Mul, Div };
	char ops[4] = { '+', '-', '*', '/' };

	int iDst(0), iSrc(0);
	char op = { };

	cout << "���� ��ȣ�� �����ϼ���." << endl;
	cout << "��ȣ �Է� : ";
	cin >> op;

	cout << "ù ��° ���ڸ� �Է��ϼ��� : ";
	cin >> iDst;

	cout << "�� ��° ���ڸ� �Է��ϼ��� : ";
	cin >> iSrc;

	for (int i = 0; i < size(ops); ++i)
	{
		if (op == ops[i])
		{
			cout << iDst << " " << op << " " << iSrc << " " << " = " << operArr[i](iDst, iSrc) << endl;
			return 0;
		}
	}

	cout << "�߸��� �������Դϴ�." << endl;
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
