#include <iostream>

using namespace std;

int main()
{
	int iKor(0), iMat(0), iEng(0), iTotal(0);
	float fAver(0.f);
	char cGra(' ');

	cout << "������ �Է��ϼ���." << endl;
	cout << "���� ���� : ";
	cin >> iKor;
	cout << "���� ���� : ";
	cin >> iMat;
	cout << "���� ���� : ";
	cin >> iEng;

	iTotal = iKor + iMat + iEng;
	cout << "����� ������ ������ " << iTotal << " �� �Դϴ�." << endl;

	fAver = (float)iTotal / 3.0f;
	cout << "����� ������ ����� " << fAver << " �� �Դϴ�." << endl;

	if ((fAver >= 90.f) && (fAver <= 100.f))
	{
		cGra = 'A';
	}
	else if ((fAver >= 80.f) && (fAver < 90.f))
	{
		cGra = 'B';
	}
	else if ((fAver >= 70.f) && (fAver < 80.f))
	{
		cGra = 'C';
	}
	else if ((fAver >= 60.f) && (fAver < 70.f))
	{
		cGra = 'D';
	}
	else
	{
		cGra = 'F';
	}

	cout << "����� ������ " << cGra << "�Դϴ�." << endl;

	return 0;
}