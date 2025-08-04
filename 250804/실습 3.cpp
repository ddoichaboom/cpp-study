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


	// �Լ� ������
	void (*FuncArr[4])(Patient*[]) = { PatientInfoInput, PrintAllPatientsInfo, SearchPatientbyName, PrintHospPatient };

	while (bChoice)
	{
		system("cls");

		cout << "[ ���� ȯ�� ���� �ý��� ]" << endl;
		cout << "1. ȯ�� ���� �Է�" << endl;
		cout << "2. ��ü ���� ���" << endl;
		cout << "3. �̸����� �˻�" << endl;
		cout << "4. �Կ� ȯ�ڸ� ����" << endl;
		cout << "5. ����" << endl;
		cout << "�Է� >> ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "���ڸ� �Է��ϼ���!" << endl;
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
			cout << "1 ~ 5 ������ �߿��� �Է����ּ���!" << endl;
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
	cout << "���α׷��� �����մϴ�." << endl;
	*pChoice = false;
}

void PatientInfoInput(Patient* pPatients[])
{
	cout << "------ȯ�� ���� �Է�------" << endl;
	char cInput = { };

	for (int i = 0; i < 5; ++i)
	{
		system("cls");

		cout << "ȯ�� �̸� : ";
		cin >> pPatients[i]->cName;

		cout << "ȯ�� ���� : ";
		cin >> pPatients[i]->iAge;

		cout << "�Կ� ���� Y / N : ";
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
			cout << "�߸��� �Է� Y/N �� �Է��ϼ���." << endl;
			cout << "�ش� ȯ���� ���� ó������ �ٽ� �Է�" << endl;
			i--;
			system("pause");

			continue;
		}

		cout << "���� �޴� ���� : ";
		cin >> pPatients[i]->cTrSub;

		pPatients[i]->bIsRegistered = true;
	}
}

void PrintAllPatientsInfo(Patient* pPatients[])
{
	cout << "----- < ��ü ȯ�� ���� ��� > -----" << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (!pPatients[i]->bIsRegistered) {
				cout << "[ " << i + 1 << " ] ȯ�� ���� ����" << endl;
				continue;
			}
			else 
			{
				cout << "ȯ�� �̸� : " << pPatients[i]->cName;
				cout << "\t ���� : " << pPatients[i]->iAge << " ��" << endl;
				cout << "���� ���� : " << pPatients[i]->cTrSub << endl;
				cout << "�Կ� ���� : ";
			
				if (pPatients[i]->bIsHosp)
				{
					cout << "�Կ� ��" << endl;
				}
				else
				{
					cout << "��� ġ�� ȯ��" << endl;
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
		cout << "�˻��ϰ� ���� ȯ���� �̸��� �Է��ϼ���" << endl;
		cin >> cInput;

		if (cin.fail())
		{
			cout << "�̸��� �Է��ϼ���" << endl;
			Reset();
			continue;
		}

		for (int i = 0; i < 5; ++i)
		{
			result = strcmp(pPatients[i]->cName, cInput);

			if (result == 0)
			{
				cout << pPatients[i]->cName << " ���� ����" << endl;
				cout << "ȯ�� �̸� : " << pPatients[i]->cName;
				cout << "\t ���� : " << pPatients[i]->iAge << " ��" << endl;
				cout << "���� ���� : " << pPatients[i]->cTrSub << endl;
				cout << "�Կ� ���� : ";
				if (pPatients[i]->bIsHosp)
				{
					cout << "�Կ� ��" << endl;
				}
				else
				{
					cout << "��� ġ�� ȯ��" << endl;
				}

				return;
			}

		}

		cout << "ã���ô� �̸��� ȯ�ڰ� �������� �ʽ��ϴ�. \n";
		return;
	}


}

void PrintHospPatient(Patient* pPatients[])
{
	int iExist = 0;

	cout << "------ < �Կ� ���� ȯ�� ����Ʈ > ------" << endl;

	for (int i = 0; i < 5; ++i)
	{
		if ((pPatients[i]->bIsHosp) && pPatients[i]->bIsRegistered)
		{	
			cout << "ȯ�� �̸� : " << pPatients[i]->cName;
			cout << "\t ���� : " << pPatients[i]->iAge << " ��" << endl;
			cout << "���� ���� : " << pPatients[i]->cTrSub << endl;
			iExist++;
		}
	}

	if (iExist == 0)
	{
		cout << "�Կ� ���� ȯ�ڰ� �����ϴ�." << endl;
		return;
	}

	return;

}