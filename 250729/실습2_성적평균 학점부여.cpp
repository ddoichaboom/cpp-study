#include <iostream>

using namespace std;

void GetAverScore(float* pAver);
void GetGrade(float _fAver);


int main()
{
	float fAver(0.f);
	
	GetAverScore(&fAver);
	GetGrade(fAver);

	return 0;
}

void GetAverScore(float* pAver)
{
	cout << "��� ������ �Է��ϼ��� : ";
	cin >> *pAver;

}

void GetGrade(float _fAver)
{
	if ((_fAver < 0.f) || (_fAver > 100.f))
	{
		cout << "�߸��� ��� �����Դϴ�." << endl;
	}
	else if ((_fAver >= 90.f) && (_fAver <= 100.f))
	{
		cout << "����� ������ : A �Դϴ�." << endl;
	}
	else if ((_fAver >= 80.f) && (_fAver < 90.f))
	{
		cout << "����� ������ : B �Դϴ�." << endl;
	}
	else if ((_fAver >= 70.f) && (_fAver < 80.f))
	{
		cout << "����� ������ : C �Դϴ�." << endl;
	}
	else if ((_fAver >= 60.f) && (_fAver < 70.f))
	{
		cout << "����� ������ : D �Դϴ�." << endl;
	}
	else
	{
		cout << "����� ������ : F �Դϴ�." << endl;
	}

	
	cout << endl << "���α׷��� �����մϴ�." << endl;

}

