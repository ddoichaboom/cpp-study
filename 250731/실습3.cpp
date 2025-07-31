#pragma region 야구 게임

#include <iostream>

using namespace std;

void Reset();
void InitArray(int pArray[], int iSizeA);
void GetRandomNumber(int* pRandom);
void InputNumber(int pInput[], int iSize);
void SetAnswer(int pArray[], int pAnswer[], int* pRandom, int iSizeAn);
void PrintArray(int pArray[], int iSize);
void PrintScore(int iStrike, int iBall);
void CheckAnswer(int pInput[], int pAnswer[], int* pStrike, int* pBall, int* pMatch, int iSize);
void ResetArray(int pArray[], int iSize);


int main()
{
	srand(unsigned(time(0)));

	int iArray[9] = { }, iInput[3] = { }, iAnswer[3] = { }, iStrike(0), iBall(0), iMatch(0), iRandom(0);

	InitArray(iArray, size(iArray));
	SetAnswer(iArray, iAnswer, &iRandom, size(iAnswer));

	cout << "==================야구 게임을 시작합니다.===================" << endl;
	cout << " 정답 : ";

	PrintArray(iAnswer, size(iAnswer));

	cout << endl;
	
	while ((iStrike < 3) && (iMatch < 9))
	{
		iStrike = 0, iBall = 0;

		InputNumber(iInput, size(iInput));
		CheckAnswer(iInput, iAnswer, &iStrike, &iBall, &iMatch, size(iInput));
		cout << iMatch << "회 : \t";
		PrintArray(iInput, size(iInput));
		PrintScore(iStrike, iBall);
		ResetArray(iInput, size(iInput));

	} 
	
	if (iStrike == 3)
	{
		cout << "야구 게임을 승리하셨습니다." << endl;
		cout << "최종 스코어 : ";
		PrintScore(iStrike, iBall);
	}
	else
	{
		cout << "9회 동안 3 스트라이크를 맞추지 못해 패배 하셨습니다." << endl;
	}

	cout << "==================야구 게임을 종료합니다.===================" << endl;

	return 0;
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void ResetArray(int pArray[], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		pArray[i] = 0;
	}
}


void InitArray(int pArray[], int iSizeA)
{
	for (int i = 0; i < iSizeA; ++i)
	{
		pArray[i] = i + 1;
	}
}


void InputNumber(int pInput[], int iSize)
{
	int iInput(0);


	for (int i = 0; i < iSize;)
	{
		cout << "예상되는 결과를 입력하세요 : ";
		cin >> iInput;

		if (cin.fail()) {
			cout << "숫자만 입력하세요!" << endl;
			Reset();
			continue;
		}

		bool bExist = false;

		for (int j = 0; j < i; ++j)
		{
			if (pInput[j] == iInput)
			{
				cout << "이미 입력한 숫자입니다." << endl;
				bExist = true;
				break;
			}
		}

		if (!bExist)
		{
			pInput[i] = iInput;
			++i;
		}

	}
}

void GetRandomNumber(int* pRandom)
{
	*pRandom = rand() % 9;
}

void SetAnswer(int pArray[], int pAnswer[], int* pRandom, int iSizeAn)
{

	for (int i = 0; i < iSizeAn;)
	{
		GetRandomNumber(pRandom);

		bool bExist = false;

		for (int j = 0; j < i; ++j)
		{
			if (pAnswer[j] == pArray[*pRandom])
			{
				bExist = true;
				break;
			}
		}

		if (!bExist)
		{
			pAnswer[i] = pArray[*pRandom];
			++i;
		}
	}
}

void PrintArray(int pArray[], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		cout << pArray[i] << "\t";
	}
}


void PrintScore(int iStrike, int iBall)
{
	cout << "\t" << iStrike << " - 스트라이크 \t" << iBall << " - 볼" << endl;
}


void CheckAnswer(int pInput[], int pAnswer[], int* pStrike, int* pBall, int* pMatch, int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if ((i == j) && (pInput[i] == pAnswer[j]))
			{
				++*pStrike;
				break;
			}
			else if ((i != j) && (pInput[i] == pAnswer[j]))
			{
				++*pBall;
				break;
			}
			
		}
	}

	++*pMatch;
}

#pragma endregion