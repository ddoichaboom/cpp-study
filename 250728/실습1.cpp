#pragma region 성적 평균 계산기

#include <iostream>

using namespace std;

void Reset();
int InputKoreanScore();
int InputMathScore();
int InputEnglishScore();
int TotalScore(int _iKor, int _iMat, int _iEng);
float AverageScore(int _iTotal, int _iNum);
void Result(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver);

int main()
{
	int iKor(0), iMat(0), iEng(0), iTotal(0), iNum(3);
	float fAver(0.f);

	iKor = InputKoreanScore();
	iMat = InputMathScore();
	iEng = InputEnglishScore();

	iTotal = TotalScore(iKor, iMat, iEng);

	fAver = AverageScore(iTotal, iNum);

	Result(iKor, iMat, iEng, iTotal, fAver);

	return 0;
}

// 1. 입력 받는 함수 (과목별?) 
int InputKoreanScore()
{
	int iInputKor(0);
	cout << "국어 성적을 입력하세요 :";
	cin >> iInputKor;

	Reset();

	return iInputKor;
}

int InputMathScore()
{
	int iInputMat(0);
	cout << "수학 성적을 입력하세요 :";
	cin >> iInputMat;

	Reset();
	
	return iInputMat;
}

int InputEnglishScore()
{
	int iInputEng(0);
	cout << "영어 성적을 입력하세요 :";
	cin >> iInputEng;

	Reset();

	return iInputEng;
}

// 2. 성적 총점 구하는 함수
int TotalScore(int _iKor, int _iMat, int _iEng)
{
	return _iKor + _iMat + _iEng;
}


// 3. 총점을 통해 성적 평균을 구하는 함수
float AverageScore(int _iTotal, int _iNum)
{
	return (float)_iTotal / (float)_iNum;
}

// 4. 최종적인 결과를 출력하는 함수
void Result(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver)
{
	cout << "국어\t수학\t영어\t총점\t평균" << endl;
	cout << _iKor << "\t" << _iMat << "\t" << _iEng << "\t" << _iTotal << "\t" << _fAver << endl;
}

// 5. 콘솔 입력창 버퍼 초기화 함수
void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

#pragma endregion