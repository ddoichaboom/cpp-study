#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int iFNum(0), iSNum(0);

	cout << "-----------구구단 게임-----------" << endl;
	cout << "몇 단 몇 곱까지 원하시나요?" << endl;
	cout << "단 : ";
	cin >> iFNum;

	cin.clear();
	cin.ignore(1000, '\n');

	cout << "곱 : ";
	cin >> iSNum;

	cout << "사용자 요청 : " << iFNum << " 단" << iSNum << " 곱" << endl;

	for (int i = 2; i < iFNum + 1; ++i)
	{
		cout << "================" << i << "단===============" << endl;

		for (int j = 1; j < iSNum + 1; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}


	return 0;
}