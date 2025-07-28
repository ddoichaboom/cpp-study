#pragma region ���� ��� ����

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

// 1. �Է� �޴� �Լ� (����?) 
int InputKoreanScore()
{
	int iInputKor(0);
	cout << "���� ������ �Է��ϼ��� :";
	cin >> iInputKor;

	Reset();

	return iInputKor;
}

int InputMathScore()
{
	int iInputMat(0);
	cout << "���� ������ �Է��ϼ��� :";
	cin >> iInputMat;

	Reset();
	
	return iInputMat;
}

int InputEnglishScore()
{
	int iInputEng(0);
	cout << "���� ������ �Է��ϼ��� :";
	cin >> iInputEng;

	Reset();

	return iInputEng;
}

// 2. ���� ���� ���ϴ� �Լ�
int TotalScore(int _iKor, int _iMat, int _iEng)
{
	return _iKor + _iMat + _iEng;
}


// 3. ������ ���� ���� ����� ���ϴ� �Լ�
float AverageScore(int _iTotal, int _iNum)
{
	return (float)_iTotal / (float)_iNum;
}

// 4. �������� ����� ����ϴ� �Լ�
void Result(int _iKor, int _iMat, int _iEng, int _iTotal, float _fAver)
{
	cout << "����\t����\t����\t����\t���" << endl;
	cout << _iKor << "\t" << _iMat << "\t" << _iEng << "\t" << _iTotal << "\t" << _fAver << endl;
}

// 5. �ܼ� �Է�â ���� �ʱ�ȭ �Լ�
void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

#pragma endregion