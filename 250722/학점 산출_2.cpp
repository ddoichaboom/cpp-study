#include <iostream>

using namespace std;

int main()
{
	float fAver(0.f);

	cout << "��� ������ �Է��ϼ��� : ";
	cin >> fAver;

	if ((fAver < 0.f) || (fAver > 100.f))
	{
		cout << "�߸��� ���� �Է��Դϴ�." << endl;
	}
	else if ((fAver >= 90.f) && (fAver <= 100.f))
	{
		cout << "A�����Դϴ�." << endl;
	}
	else if ((fAver >= 80.f) && (fAver < 90.f))
	{
		cout << "B�����Դϴ�." << endl;
	}
	else if ((fAver >= 70.f) && (fAver < 80.f))
	{
		cout << "C�����Դϴ�." << endl;
	}
	else if ((fAver >= 60.f) && (fAver < 70.f))
	{
		cout << "D�����Դϴ�." << endl;
	}
	else
	{
		cout << "F�����Դϴ�." << endl;
	}


	return 0;
}