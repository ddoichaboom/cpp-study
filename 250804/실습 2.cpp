#include <iostream>

using namespace std;

struct Student
{
	char cName[10];
	int iKor;
	int iEng;
	int iMat;
};

void GetStdInfo(Student* pStudent[]);
void PrintStdInfo(Student* pStudent[]);


int main()
{
	bool bChoice = true;
	char cName[10] = {};
	int iInput(0);
	void (*pFunc[2])(Student*[]) = {GetStdInfo, PrintStdInfo};

	Student s1 = {};
	Student s2 = {};
	Student s3 = {};
	
	Student* pStudent[3] = { &s1, &s2, &s3 };


	cout << "����ǥ ���α׷� ON" << endl;

	while (bChoice)
	{
		system("cls");

		cout << "���Ͻô� �޴��� �����ϼ���." << endl;
		cout << "1. �Է� | 2. ��� | 3. ���α׷� ����" << endl;
		cout << " �Է� : ";
		cin >>  iInput;

		switch (iInput)
		{
		case 1:
			pFunc[0](pStudent);
			system("pause");
			break;

		case 2:
			pFunc[1](pStudent);
			system("pause");
			break;

		case 3:
			cout << "���α׷��� �����մϴ�." << endl;
			bChoice = false;

			system("pause");
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;

		}

	}
	return 0;
}

void GetStdInfo(Student* pStudent[])
{
	for (int i = 0; i < 3; ++i)
	{
		cout << "----------------------" << endl;
		cout << "�л� �̸� �Է� : ";
		cin >> pStudent[i]->cName;
		cout << "���� �Է�" << endl;
		cout << "���� ���� : ";
		cin >> pStudent[i]->iKor;
		cout << "���� ���� : ";
		cin >> pStudent[i]->iEng;
		cout << "���� ���� : ";
		cin >> pStudent[i]->iMat;
	}
}

void PrintStdInfo(Student* pStudent[])
{
	for (int i = 0; i < 3; ++i)
	{
		cout << "----------------------" << endl;
		cout << "�л� �̸� : " <<  pStudent[i]->cName << endl;
		cout << "����ǥ" << endl;
		cout << "���� ���� : " << pStudent[i]->iKor << " ��" << endl;
		cout << "���� ���� : " << pStudent[i]->iEng << " ��" << endl;
		cout << "���� ���� : " << pStudent[i]->iMat << " ��" << endl;
		
	}
}