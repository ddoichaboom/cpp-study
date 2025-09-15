#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	char cName[12];
	int _iKor, _iEng, _iMat;

	cout << "-------------성적표-------------" << endl;
	cout << "기본 학생 3명의 성적을 입력하세요." << endl;

	for (int i = 0; i < 3; ++i)
	{
		cout << "이름 입력 : ";
		cin >> cName;
		cout << "국어 성적 입력 : ";
		cin >> _iKor;
		cout << "영어 성적 입력 : ";
		cin >> _iEng;
		cout << "수학 성적 입력 : ";
		cin >> _iMat;

		m_vStudents.push_back(CStudent(cName, _iKor, _iEng, _iMat));
	}

}

void CMainGame::Update()
{
	int iInput(0);

	vector<CStudent>::iterator iter = m_vStudents.begin();

	iter->Get_Info().cName;

	while (true)
	{

		system("cls");

		cout << "1.추가 2.출력 3.검색 4.삭제 5.종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case ADD:
			Input_Data();
			break;

		case PRINT:
			Output_Data();
			break;

		case SEARCH:
			Search_Data();
			break;

		case DELETE:
			Delete_Data();
			break;

		case EXIT:
			return;
		}
		system("pause");
	}
}

void CMainGame::Release()
{
	//m_vStudents.clear();
	//m_vStudents.shrink_to_fit();

	vector<CStudent>().swap(m_vStudents);
}

void CMainGame::Input_Data()
{
	int iInput(0);

	char cName[12];
	int _iKor, _iEng, _iMat;

	cout << "추가할 학생은 몇 명 입니까? : ";
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		cout << "이름 입력 : ";
		cin >> cName;
		cout << "국어 성적 입력 : ";
		cin >> _iKor;
		cout << "영어 성적 입력 : ";
		cin >> _iEng;
		cout << "수학 성적 입력 : ";
		cin >> _iMat;

		m_vStudents.push_back(CStudent(cName, _iKor, _iEng, _iMat));
	}
	
}

void CMainGame::Output_Data()
{ 
	for (vector<CStudent>::iterator iter = m_vStudents.begin();
		iter != m_vStudents.end();
		++iter)
	{
		cout << "---------------------------" << endl;
		cout << "이름 : " << iter->Get_Info().cName << endl;
		cout << "국어 : " << iter->Get_Info().iKor << " 점" << endl;
		cout << "영어 : " << iter->Get_Info().iEng << " 점" << endl;
		cout << "수학 : " << iter->Get_Info().iMat << " 점" << endl;
		cout << "총점 : " << iter->Get_Info().iTotal << " 점" << endl;
		cout << "평균 : " << iter->Get_Info().fAver << " 점" << endl;

	}

}

void CMainGame::Search_Data()
{
	char	cFindName[12];

	cout << "찾는 학생의 이름을 입력 : ";
	cin >> cFindName;

	for (vector<CStudent>::iterator iter = m_vStudents.begin();
		iter != m_vStudents.end();
		++iter)
	{
		if (!strcmp(iter->Get_Info().cName, cFindName))
		{
			cout << "---------------------------" << endl;
			cout << "이름 : " << iter->Get_Info().cName << endl;
			cout << "국어 : " << iter->Get_Info().iKor << " 점" << endl;
			cout << "영어 : " << iter->Get_Info().iEng << " 점" << endl;
			cout << "수학 : " << iter->Get_Info().iMat << " 점" << endl;
			cout << "총점 : " << iter->Get_Info().iTotal << " 점" << endl;
			cout << "평균 : " << iter->Get_Info().fAver << " 점" << endl;
		}
		
	}
}

void CMainGame::Delete_Data()
{
	char	cFindName[12];

	cout << "성적을 삭제할 학생의 이름을 입력 : ";
	cin >> cFindName;

	for (vector<CStudent>::iterator iter = m_vStudents.begin();
		iter != m_vStudents.end();
		++iter)
	{
		if (!strcmp(iter->Get_Info().cName, cFindName))
		{
			cout << "---------------------------" << endl;
			cout << "이름 : " << iter->Get_Info().cName << endl;
			cout << "국어 : " << iter->Get_Info().iKor << " 점" << endl;
			cout << "영어 : " << iter->Get_Info().iEng << " 점" << endl;
			cout << "수학 : " << iter->Get_Info().iMat << " 점" << endl;
			cout << "총점 : " << iter->Get_Info().iTotal << " 점" << endl;
			cout << "평균 : " << iter->Get_Info().fAver << " 점" << endl;
		}

	}
}