#include "pch.h"
#include "CStore.h"

CStore::CStore()
	: m_pPlayer(nullptr)
{
	memset(m_pItem, 0, sizeof(CObj*) * IT_END * IC_END);
}

CStore::~CStore()
{
	Release();
}

void CStore::Initialize()
{
	m_pItem[IT_WEAPON][BEGINNER]	= new CItem("초급검", 0, 10, 1000);
	m_pItem[IT_WEAPON][RARE]		= new CItem("중급검", 0, 20, 2000);
	m_pItem[IT_WEAPON][RARE]		= new CItem("고급검", 0, 30, 3000);

	m_pItem[IT_ARMOR][BEGINNER]		= new CItem("초급옷", 10, 0, 1000);
	m_pItem[IT_ARMOR][RARE]			= new CItem("중급옷", 20, 0, 2000);
	m_pItem[IT_ARMOR][RARE]			= new CItem("고급옷", 30, 0, 3000);
}

void CStore::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. 초급 2. 중급 3. 고급 4. 뒤로 가기 :";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render(BEGINNER);
			break;

		case 2:
			Render(RARE);
			break;

		case 3:
			Render(UNIQUE);
			break;

		case 4:
			return;
		}
	}
}

void CStore::Release()
{
	for (int i = 0; i < IT_END; ++i)
	{
		for (int j = 0; j < IC_END; ++j)
		{
			SAFE_DELETE(m_pItem[i][j]);
		}
	}
}

void CStore::Render(ITEMCLASS eClass)
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		m_pItem[IT_WEAPON][eClass]->Render();
		m_pItem[IT_ARMOR][eClass]->Render();

		cout << "1. 무기 구매 2. 방어구 구매 3. 뒤로 가기 :";
		cin >> iInput;

		if (1 == iInput)
		{
			if (m_pPlayer->Get_Info().iMoney >= m_pItem[IT_WEAPON][eClass]->Get_Info().iMoney)
			{

			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}
		else if (2 == iInput)
		{
			if (m_pPlayer->Get_Info().iMoney >= m_pItem[IT_ARMOR][eClass]->Get_Info().iMoney)
			{

			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}

		else if (3 == iInput)
		{
			return;
		}
	}
}

