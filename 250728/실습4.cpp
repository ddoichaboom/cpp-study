#pragma region ������ - �Լ� Ȱ��

#include <iostream>

using namespace std;

void Loop(int _iFnum, int _iSnum);
void PrintGugudan(int _iFnum, int _iSnum);

int main()
{
	int iFnum(9), iSnum(9);

	Loop(iFnum, iSnum);

	return 0;
}

void Loop(int _iFnum, int _iSnum)
{
	for (int i = 2; i < _iFnum + 1; ++i)
	{
		cout << "-----------" << i << " ��------------" << endl;
		PrintGugudan(i, _iSnum);
	}
}

void PrintGugudan(int _iFnum, int _iSnum)
{
	for (int j = 2; j < _iSnum + 1; ++j)
	{
		cout << "\t" << _iFnum << " * " << j << " = " << _iFnum * j << endl;
	}
}


#pragma endregion