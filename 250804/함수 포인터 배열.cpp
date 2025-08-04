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

	cout << "수식 기호를 선택하세요." << endl;
	cout << "기호 입력 : ";
	cin >> op;

	cout << "첫 번째 숫자를 입력하세요 : ";
	cin >> iDst;

	cout << "두 번째 숫자를 입력하세요 : ";
	cin >> iSrc;

	for (int i = 0; i < size(ops); ++i)
	{
		if (op == ops[i])
		{
			cout << iDst << " " << op << " " << iSrc << " " << " = " << operArr[i](iDst, iSrc) << endl;
			return 0;
		}
	}

	cout << "잘못된 연산자입니다." << endl;
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
