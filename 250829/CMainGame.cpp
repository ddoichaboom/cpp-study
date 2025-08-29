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
	m_pStudent->Initialize();					// �����Ǿ� ���� ������ ȣ���ϴ� ������?
}

void CMainGame::Update()
{
	int iInput(0);
	
	while (true)
	{
		system("cls");

		cout << "1. �߰� 2. ��� 3. �˻� 4. ���� : ";
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
