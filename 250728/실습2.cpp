#pragma region 학점 부여 - if문 

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
	int InputScore(0);
	cout << "성적을 입력하세요 :";
	cin >> InputScore;

	Reset();

	return InputScore;
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
	if ((_fAver >= 90.f) && (_fAver <= 100.f))
	{
		return 'A';
	}
	else if ((_fAver >= 80.f) && (_fAver < 90.f))
	{
		return 'B';
	}
	else if ((_fAver >= 70.f) && (_fAver < 80.f))
	{
		return 'C';
	}
	else if ((_fAver >= 60.f) && (_fAver < 70.f))
	{
		return 'D';
	}
	else
		return 'F';
}

void PrintResult(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver, char _cGrade)
{
	cout << "국어\t수학\t영어\t총점\t평균\t학점" << endl;
	cout << _iKor << "\t" << _iMat << "\t" << _iEng << "\t" << _iTotal << "\t" << _fAver << "\t" << _cGrade << endl;
}

#pragma endregion