#include <iostream>

using namespace std;

int main()
{
	float fAver(0.f);

	cout << "평균 성적을 입력하세요 : ";
	cin >> fAver;

	if ((fAver < 0.f) || (fAver > 100.f))
	{
		cout << "잘못된 성적 입력입니다." << endl;
	}
	else if ((fAver >= 90.f) && (fAver <= 100.f))
	{
		cout << "A학점입니다." << endl;
	}
	else if ((fAver >= 80.f) && (fAver < 90.f))
	{
		cout << "B학점입니다." << endl;
	}
	else if ((fAver >= 70.f) && (fAver < 80.f))
	{
		cout << "C학점입니다." << endl;
	}
	else if ((fAver >= 60.f) && (fAver < 70.f))
	{
		cout << "D학점입니다." << endl;
	}
	else
	{
		cout << "F학점입니다." << endl;
	}


	return 0;
}