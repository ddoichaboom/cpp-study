#include <iostream>

using namespace std;

int GetScoreTotal(int iKor, int iEng, int iMat);
float GetScoreAver(int iTotal);



struct Score
{
	char cName[8];
	int iAge;
	int iKor;
	int iEng;
	int iMat;
	int iTotal;
	float fAver;
};

int main()
{
	int (*ScoreTotal)(int, int, int) = NULL;
	ScoreTotal = GetScoreTotal;

	float (*ScoreAver)(int) = NULL;
	ScoreAver = GetScoreAver;

	Score s1	= { };
	Score s2	= {};
	Score s3 = {};

	Score* pStudent[3] = { &s1, &s2, &s3};

	for (int i = 0; i < 3; ++i)
	{
		system("cls");

		cout << "학생 이름을 입력 : ";
		cin >> pStudent[i]->cName;

		cout << "학생 나이 입력 : ";
		cin >> pStudent[i]->iAge;

		cout << "학생 " << pStudent[i]->cName << " 의 성적 입력" << endl;
		cout << "국어 성적 입력 : ";
		cin >> pStudent[i]->iKor;
		cout << "영어 성적 입력 : ";
		cin >> pStudent[i]->iEng;
		cout << "수학 성적 입력 : ";
		cin >> pStudent[i]->iMat;


		pStudent[i]->iTotal = ScoreTotal(pStudent[i]->iKor, pStudent[i]->iEng, pStudent[i]->iMat);

		pStudent[i]->fAver = ScoreAver(pStudent[i]->iTotal);

	}

	for (int i = 0; i < 3; ++i)
	{
		cout << "-------성적표-------" << endl;
		cout << "이름 : " << pStudent[i]->cName << "  나이 : " << pStudent[i]->iAge << endl;
		cout << "국어 성적 : " << pStudent[i]->iKor << " 점" << endl;
		cout << "영어 성적 : " << pStudent[i]->iEng << " 점" << endl;
		cout << "수학 성적 : " << pStudent[i]->iMat << " 점" << endl;
		cout << "총점 : " << pStudent[i]->iTotal << " 점" << endl;
		cout << "평균 : " << pStudent[i]->fAver << " 점" << endl;
	}
	


	return 0;
}

int GetScoreTotal(int iKor, int iEng, int iMat)
{
	return iKor + iEng + iMat;
}

float GetScoreAver(int iTotal)
{
	return (float)iTotal / 3.f;
}