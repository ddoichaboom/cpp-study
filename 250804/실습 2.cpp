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


	cout << "성적표 프로그램 ON" << endl;

	while (bChoice)
	{
		system("cls");

		cout << "원하시는 메뉴를 선택하세요." << endl;
		cout << "1. 입력 | 2. 출력 | 3. 프로그램 종료" << endl;
		cout << " 입력 : ";
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
			cout << "프로그램을 종료합니다." << endl;
			bChoice = false;

			system("pause");
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
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
		cout << "학생 이름 입력 : ";
		cin >> pStudent[i]->cName;
		cout << "성적 입력" << endl;
		cout << "국어 성적 : ";
		cin >> pStudent[i]->iKor;
		cout << "영어 성적 : ";
		cin >> pStudent[i]->iEng;
		cout << "수학 성적 : ";
		cin >> pStudent[i]->iMat;
	}
}

void PrintStdInfo(Student* pStudent[])
{
	for (int i = 0; i < 3; ++i)
	{
		cout << "----------------------" << endl;
		cout << "학생 이름 : " <<  pStudent[i]->cName << endl;
		cout << "성적표" << endl;
		cout << "국어 성적 : " << pStudent[i]->iKor << " 점" << endl;
		cout << "영어 성적 : " << pStudent[i]->iEng << " 점" << endl;
		cout << "수학 성적 : " << pStudent[i]->iMat << " 점" << endl;
		
	}
}