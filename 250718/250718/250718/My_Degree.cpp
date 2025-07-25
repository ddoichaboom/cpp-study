#include <iostream>

using namespace std;

int main()
{
	int iKorean(0), iMath(0), iEnglish(0), iTotal(0);
	float fAver(0.f);

	cout << "국어 성적을 입력하세요 : ";
	cin >> iKorean;
	cout << "수학 성적을 입력하세요 : ";
	cin >> iMath;
	cout << "영어 성적을 입력하세요 : ";
	cin >> iEnglish;

	iTotal = iKorean + iMath + iEnglish;
	fAver = (float)iTotal / 3.0f;

	cout << "국어\t수학\t영어\t총합\t평균" << endl;
	cout << iKorean << "\t" << iMath << "\t" << iEnglish << "\t" << iTotal << "\t" << fAver << endl;

	return 0;
}