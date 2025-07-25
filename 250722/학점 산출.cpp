#include <iostream>

using namespace std;

int main()
{
	int iKor(0), iMat(0), iEng(0), iTotal(0);
	float fAver(0.f);
	char cGra(' ');

	cout << "성적을 입력하세요." << endl;
	cout << "국어 성적 : ";
	cin >> iKor;
	cout << "수학 성적 : ";
	cin >> iMat;
	cout << "영어 성적 : ";
	cin >> iEng;

	iTotal = iKor + iMat + iEng;
	cout << "당신의 성적의 총합은 " << iTotal << " 점 입니다." << endl;

	fAver = (float)iTotal / 3.0f;
	cout << "당신의 성적의 평균은 " << fAver << " 점 입니다." << endl;

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

	cout << "당신의 학점은 " << cGra << "입니다." << endl;

	return 0;
}