#include <iostream>

using namespace std;

int main()
{
	float fAver(0.f);

	cout << "성적 평균 점수를 입력하세요 : ";
	cin >> fAver;

	switch ((int)fAver / 10)
	{

	case 10:
	case 9:
		cout << "A학점" << endl;
		break;

	case 8:
		cout << "B학점" << endl;
		break;

	case 7:
		cout << "C학점" << endl;
		break;

	case 6:
		cout << "D학점" << endl;
		break;

	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		cout << "F학점" << endl;
		break;

	default:
		cout << "잘못된 점수입니다." << endl;
		break;

		return 0;
	}