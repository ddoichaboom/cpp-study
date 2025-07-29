#include <iostream>

using namespace std;

void GetScore(int* pKor, int*pMat, int* pEng);
void Reset();
void TotalScore(int _iKor, int _iMat, int _iEng, int* pTotal);
void AverageScore(float* pAver, int _iTotal, int _iNum);
void PrintResult(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver);

int main()
{
	int iKor(0), iMat(0), iEng(0), iTotal(0), iNum(3);
	float fAver(0.f);

	GetScore(&iKor, &iMat, &iEng);
	TotalScore(iKor, iMat, iEng, &iTotal);
	AverageScore(&fAver, iTotal, iNum);
	PrintResult(iKor, iMat, iEng, iTotal, fAver);

	return 0;
}

void GetScore(int* pKor, int* pMat, int* pEng)
{
	cout << "국어 성적을 입력하세요 : ";
	cin >> *pKor;

	Reset();

	cout << "수학 성적을 입력하세요 : ";
	cin >> *pMat;

	Reset();

	cout << "영어 성적을 입력하세요 : ";
	cin >> *pEng;

}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');

	cout << endl;
}

void TotalScore(int _iKor, int _iMat, int _iEng, int* pTotal)
{
	*pTotal = _iKor + _iMat + _iEng;
}

void AverageScore(float* pAver, int _iTotal, int _iNum)
{
	*pAver = (float)_iTotal / (float)_iNum;
}

void PrintResult(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver)
{
	system("cls");

	cout << "국어\t수학\t영어\t총점\t평균" << endl;
	cout << _iKor << "\t" << _iMat << "\t" << _iEng << "\t" << _iTotal << "\t" << _fAver << endl;
}

