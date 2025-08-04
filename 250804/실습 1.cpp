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

		cout << "�л� �̸��� �Է� : ";
		cin >> pStudent[i]->cName;

		cout << "�л� ���� �Է� : ";
		cin >> pStudent[i]->iAge;

		cout << "�л� " << pStudent[i]->cName << " �� ���� �Է�" << endl;
		cout << "���� ���� �Է� : ";
		cin >> pStudent[i]->iKor;
		cout << "���� ���� �Է� : ";
		cin >> pStudent[i]->iEng;
		cout << "���� ���� �Է� : ";
		cin >> pStudent[i]->iMat;


		pStudent[i]->iTotal = ScoreTotal(pStudent[i]->iKor, pStudent[i]->iEng, pStudent[i]->iMat);

		pStudent[i]->fAver = ScoreAver(pStudent[i]->iTotal);

	}

	for (int i = 0; i < 3; ++i)
	{
		cout << "-------����ǥ-------" << endl;
		cout << "�̸� : " << pStudent[i]->cName << "  ���� : " << pStudent[i]->iAge << endl;
		cout << "���� ���� : " << pStudent[i]->iKor << " ��" << endl;
		cout << "���� ���� : " << pStudent[i]->iEng << " ��" << endl;
		cout << "���� ���� : " << pStudent[i]->iMat << " ��" << endl;
		cout << "���� : " << pStudent[i]->iTotal << " ��" << endl;
		cout << "��� : " << pStudent[i]->fAver << " ��" << endl;
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