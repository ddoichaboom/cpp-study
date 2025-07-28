#pragma region 성적 평균 학점 계산 - switch 분기문 활용

#include <iostream>

using namespace std;

int InputScore();
void Reset();
int TotalScore(int _iKor, int _iMat, int _iEng);
float AverageScore(int _iTotal, int _iNum);
char GetGrade(float _fAver);
void PrintResult(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver, char _cGrade);


int main()
{
	int iKor(0), iMat(0), iEng(0), iTotal(0), iNum(3);
	char cGrade(' ');
	float fAver(0.f);

	iKor = InputScore();
	iMat = InputScore();
	iEng = InputScore();

	iTotal = TotalScore(iKor, iMat, iEng);
	fAver = AverageScore(iTotal, iNum);
	cGrade = GetGrade(fAver);

	PrintResult(iKor, iMat, iEng, iTotal, fAver, cGrade);


	return 0;
}

int InputScore()
{
	int iInput(0);

	cout << "성적을 입력하세요 :";
	cin >> iInput;

	Reset();

	return iInput;
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

int TotalScore(int _iKor, int _iMat, int _iEng)
{
	return _iKor + _iMat + _iEng;
}

float AverageScore(int _iTotal, int _iNum)
{
	return (float)_iTotal / (float)_iNum;
}

char GetGrade(float _fAver)
{
	char _cGrade(' ');

	switch ((int)_fAver / 10)
	{
	case 10:
	case 9:
		_cGrade = 'A';
		break;

	case 8:
		_cGrade = 'B';
		break;

	case 7:
		_cGrade = 'C';
			break;

	case 6:
		_cGrade = 'D';
		break;

	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		_cGrade = 'F';
		break;

	default:
		cout << "성적 평균 오류" << endl;
		_cGrade = ' ';
		break;
	}

	return _cGrade;
}

void PrintResult(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver, char _cGrade)
{
	if (_cGrade == ' ')
	{
		cout << "성적 오류입니다." << endl;
		cout << "올바른 성적을 입력하세요." << endl;
	}
	else
	{
		cout << "국어\t수학\t영어\t총점\t평균\t학점" << endl;
		cout << _iKor << "\t" << _iMat << "\t" << _iEng << "\t" << _iTotal << "\t" << _fAver << "\t" << _cGrade << endl;
	}
}




#pragma endregion