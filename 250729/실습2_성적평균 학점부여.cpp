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
	cout << "평균 점수를 입력하세요 : ";
	cin >> *pAver;

}

void GetGrade(float _fAver)
{
	if ((_fAver < 0.f) || (_fAver > 100.f))
	{
		cout << "잘못된 평균 점수입니다." << endl;
	}
	else if ((_fAver >= 90.f) && (_fAver <= 100.f))
	{
		cout << "당신의 학점은 : A 입니다." << endl;
	}
	else if ((_fAver >= 80.f) && (_fAver < 90.f))
	{
		cout << "당신의 학점은 : B 입니다." << endl;
	}
	else if ((_fAver >= 70.f) && (_fAver < 80.f))
	{
		cout << "당신의 학점은 : C 입니다." << endl;
	}
	else if ((_fAver >= 60.f) && (_fAver < 70.f))
	{
		cout << "당신의 학점은 : D 입니다." << endl;
	}
	else
	{
		cout << "당신의 학점은 : F 입니다." << endl;
	}

	
	cout << endl << "프로그램을 종료합니다." << endl;

}

