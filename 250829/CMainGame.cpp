#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
	m_pStudent = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (nullptr == m_pStudent)
		m_pStudent = new CStudent;
	m_pStudent->Initialize();					// 구현되어 있지 않은데 호출하는 이유가?
}

void CMainGame::Update()
{
	int iInput(0);
	
	while (true)
	{
		system("cls");

		cout << "1. 추가 2. 출력 3. 검색 4. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case CMainGame::ADD:
			if (m_pStudent)
				m_pStudent->Input_Data();
			break;

		case CMainGame::RENDER:
			if (m_pStudent)
				m_pStudent->Output_Data();
			break;

		case CMainGame::SEARCH:
			if (m_pStudent)
				m_pStudent->Search_Data();
			break;

		case CMainGame::END:
			return;

		default:
			continue;

		}

		system("pause");
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pStudent);
}
