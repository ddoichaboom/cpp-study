#include "pch.h"
#include "Define.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{

}

void CMainGame::Initialize()
{
	cout << "기본 학생 3명의 성적 정보를 입력하세요 : " << endl;
	for (int i = 0; i < 3; ++i)
	{
		CStudent* pStudent = new CStudent;
		pStudent->Input_Data();

		m_vecStu.push_back(pStudent);
	}
}

void CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		cout << "1. 추가 2. 출력 3. 검색 4. 삭제 5. 종료 : ";
		cin >> iInput;
		
		switch (iInput)
		{
		case ADD:
			Add_Data();
			break;

		case RENDER:
			Render_Data();
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

}

void	CMainGame::Add_Data()
{
	int		iInput(0);

	cout << "추가할 학생 수 입력 : ";
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		CStudent* pStudent = new CStudent;
		pStudent->Input_Data();

		m_vecStu.push_back(pStudent);
	}
}

void	CMainGame::Render_Data()
{
	for (vector<CStudent*>::iterator iter = m_vecStu.begin();
		iter != m_vecStu.end();
		++iter)
	{
		(*iter)->Output_Data();
	}
}

void	CMainGame::Search_Data()
{
	char	cFindName[32] = "";
	cout << "찾는 학생의 이름 : ";
	cin >> cFindName;

	for (vector<CStudent*>::iterator iter = m_vecStu.begin()
		; iter != m_vecStu.end(); ++iter)
	{
		if (!strcmp((*iter)->Get_Info().cName, cFindName))
		{
			(*iter)->Output_Data();
			break;
		}
	}
}

void	CMainGame::Delete_Data()
{

	char	cFindName[32];
	cout << "찾는 학생의 이름 : ";
	cin >> cFindName;

	for (vector<CStudent*>::iterator iter = m_vecStu.begin();
		iter != m_vecStu.end();)
	{
		if (!strcmp((*iter)->Get_Info().cName, cFindName))
		{	
			Safe_Delete<CStudent*>(*iter);
			iter = m_vecStu.erase(iter);

		}
		else
		{
			++iter;
		}
	}
}