#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
	:m_pShop(nullptr)
{
	m_pPlayer	= nullptr;
	m_pField	= nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void	CMainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		static_cast<CPlayer*>(m_pPlayer)->Select_Job();
	}

	if (!m_pField)
	{
		m_pField = new CField;
		m_pField->Initialize();
	}

	m_pField->Set_Player(m_pPlayer);

	if (!m_pShop)
	{
		m_pShop = new CShop;
		m_pShop->Initialize();
	}

	m_pShop->Set_Player(m_pPlayer);

	if (!m_pInven)
	{
		m_pInven = new CInven;
		m_pInven->Initialize();
	}

	m_pInven->Set_Player(m_pPlayer);
	m_pShop->Set_Inven(m_pInven);
}
 
void	CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case FIELD:
			if (m_pField)
				m_pField->Update();
			break;

		case SHOP:
			if (m_pShop)
				m_pShop->Update();
			break;

		case INVENTORY:
			if (m_pInven)
				m_pInven->Update();
			break;

		case EXIT:
			return;
		}
	}
}

void	CMainGame::Release()
{
	Safe_Delete<CInven*>(m_pInven);
	Safe_Delete<CShop*>(m_pShop);
	Safe_Delete<CField*>(m_pField);
	Safe_Delete<CObj*>(m_pPlayer);

}
