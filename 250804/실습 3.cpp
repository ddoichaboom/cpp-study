#include <iostream>
#include <cstring>

using namespace std;

struct Patient
{
	bool bIsHosp;
	bool bIsRegistered;
	char cName[20];
	char cTrSub[20];
	int iAge;

};

void Reset();
void PatientInfoInput(Patient* pPatients[]);
void PrintAllPatientsInfo(Patient* pPatients[]);
void SearchPatientbyName(Patient* pPatients[]);
void PrintHospPatient(Patient* pPatients[]);
void ProgramExit(bool* pChoice);

int main()
{
	bool bChoice = true;
	int iInput(0);

	Patient p1 = { };
	Patient p2 = { };
	Patient p3 = { };
	Patient p4 = { };
	Patient p5 = { };

	Patient* pPatients[5] = { &p1, &p2, &p3, &p4, &p5 };


	// 함수 포인터
	void (*FuncArr[4])(Patient*[]) = { PatientInfoInput, PrintAllPatientsInfo, SearchPatientbyName, PrintHospPatient };

	while (bChoice)
	{
		system("cls");

		cout << "[ 병원 환자 정보 시스템 ]" << endl;
		cout << "1. 환자 정보 입력" << endl;
		cout << "2. 전체 정보 출력" << endl;
		cout << "3. 이름으로 검색" << endl;
		cout << "4. 입원 환자만 보기" << endl;
		cout << "5. 종료" << endl;
		cout << "입력 >> ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "숫자만 입력하세요!" << endl;
			Reset();
			system("pause");
			continue;
		}
		

		switch (iInput)
		{
		case 1:
			FuncArr[iInput - 1](pPatients);
			system("pause");

			break;

		case 2:
			FuncArr[iInput - 1](pPatients);
			system("pause");

			break;

		case 3:
			FuncArr[iInput - 1](pPatients);
			system("pause");

			break;

		case 4:
			FuncArr[iInput - 1](pPatients);
			system("pause");

			break;

		case 5:
			ProgramExit(&bChoice);
			break;

		default:
			cout << "1 ~ 5 선택지 중에서 입력해주세요!" << endl;
			Reset();
			system("pause");

			continue;

		}


	}

	return 0;
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void ProgramExit(bool* pChoice)
{
	cout << "프로그램을 종료합니다." << endl;
	*pChoice = false;
}

void PatientInfoInput(Patient* pPatients[])
{
	cout << "------환자 정보 입력------" << endl;
	char cInput = { };

	for (int i = 0; i < 5; ++i)
	{
		system("cls");

		cout << "환자 이름 : ";
		cin >> pPatients[i]->cName;

		cout << "환자 나이 : ";
		cin >> pPatients[i]->iAge;

		cout << "입원 여부 Y / N : ";
		cin >> cInput;

		if ((cInput == 'Y') || (cInput =='y'))
		{
			pPatients[i]->bIsHosp = true;
		}
		else if ((cInput == 'N') || (cInput == 'n'))
		{
			pPatients[i]->bIsHosp = false;
		}
		else
		{
			cout << "잘못된 입력 Y/N 만 입력하세요." << endl;
			cout << "해당 환자의 정보 처음부터 다시 입력" << endl;
			i--;
			system("pause");

			continue;
		}

		cout << "진료 받는 과목 : ";
		cin >> pPatients[i]->cTrSub;

		pPatients[i]->bIsRegistered = true;
	}
}

void PrintAllPatientsInfo(Patient* pPatients[])
{
	cout << "----- < 전체 환자 정보 출력 > -----" << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (!pPatients[i]->bIsRegistered) {
				cout << "[ " << i + 1 << " ] 환자 정보 없음" << endl;
				continue;
			}
			else 
			{
				cout << "환자 이름 : " << pPatients[i]->cName;
				cout << "\t 나이 : " << pPatients[i]->iAge << " 세" << endl;
				cout << "진료 과목 : " << pPatients[i]->cTrSub << endl;
				cout << "입원 여부 : ";
			
				if (pPatients[i]->bIsHosp)
				{
					cout << "입원 중" << endl;
				}
				else
				{
					cout << "통원 치료 환자" << endl;
				}
			}
		}
}

void SearchPatientbyName(Patient* pPatients[])
{
	char cInput[20] = { };
	int result(0);

	while (true)
	{
		cout << "검색하고 싶은 환자의 이름을 입력하세요" << endl;
		cin >> cInput;

		if (cin.fail())
		{
			cout << "이름을 입력하세요" << endl;
			Reset();
			continue;
		}

		for (int i = 0; i < 5; ++i)
		{
			result = strcmp(pPatients[i]->cName, cInput);

			if (result == 0)
			{
				cout << pPatients[i]->cName << " 님의 정보" << endl;
				cout << "환자 이름 : " << pPatients[i]->cName;
				cout << "\t 나이 : " << pPatients[i]->iAge << " 세" << endl;
				cout << "진료 과목 : " << pPatients[i]->cTrSub << endl;
				cout << "입원 여부 : ";
				if (pPatients[i]->bIsHosp)
				{
					cout << "입원 중" << endl;
				}
				else
				{
					cout << "통원 치료 환자" << endl;
				}

				return;
			}

		}

		cout << "찾으시는 이름의 환자가 존재하지 않습니다. \n";
		return;
	}


}

void PrintHospPatient(Patient* pPatients[])
{
	int iExist = 0;

	cout << "------ < 입원 중인 환자 리스트 > ------" << endl;

	for (int i = 0; i < 5; ++i)
	{
		if ((pPatients[i]->bIsHosp) && pPatients[i]->bIsRegistered)
		{	
			cout << "환자 이름 : " << pPatients[i]->cName;
			cout << "\t 나이 : " << pPatients[i]->iAge << " 세" << endl;
			cout << "진료 과목 : " << pPatients[i]->cTrSub << endl;
			iExist++;
		}
	}

	if (iExist == 0)
	{
		cout << "입원 중인 환자가 없습니다." << endl;
		return;
	}

	return;

}