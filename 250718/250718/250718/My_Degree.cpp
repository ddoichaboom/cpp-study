#include <iostream>

using namespace std;

int main()
{
	int iKorean(0), iMath(0), iEnglish(0), iTotal(0);
	float fAver(0.f);

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iKorean;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iMath;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iEnglish;

	iTotal = iKorean + iMath + iEnglish;
	fAver = (float)iTotal / 3.0f;

	cout << "����\t����\t����\t����\t���" << endl;
	cout << iKorean << "\t" << iMath << "\t" << iEnglish << "\t" << iTotal << "\t" << fAver << endl;

	return 0;
}