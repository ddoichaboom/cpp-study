#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int iFNum(0), iSNum(0);

	cout << "-----------������ ����-----------" << endl;
	cout << "�� �� �� ������ ���Ͻó���?" << endl;
	cout << "�� : ";
	cin >> iFNum;

	cin.clear();
	cin.ignore(1000, '\n');

	cout << "�� : ";
	cin >> iSNum;

	cout << "����� ��û : " << iFNum << " ��" << iSNum << " ��" << endl;

	for (int i = 2; i < iFNum + 1; ++i)
	{
		cout << "================" << i << "��===============" << endl;

		for (int j = 1; j < iSNum + 1; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}


	return 0;
}