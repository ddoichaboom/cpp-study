#include "pch.h"
#include "CField.h"

CField::CField()
{
	m_pCopyPlayer	= nullptr;
	m_pMonster		= nullptr;
}

CField::~CField()
{
	Release();
}

void	CField::Initialize()
{

}

void	CField::Update()
{
	int		iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();

		cout << "-----------------------------------------------------------------------" << endl;
		cout << "1. 쉬움 2. 보통 3. 어려움 4. 뒤로 가기 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("쉬움", 5, 50, 50, 5);
			dynamic_cast<CMonster*>(m_pMonster)->Set_Ex(3);
			break;

		case 2:
			m_pMonster = new CMonster("보통", 10, 150, 150, 10);
			dynamic_cast<CMonster*>(m_pMonster)->Set_Ex(6);
			break;

		case 3:
			m_pMonster = new CMonster("어려움", 20, 300, 300, 20);
			dynamic_cast<CMonster*>(m_pMonster)->Set_Ex(9);
			break;

		case 4:
			return;
		}

		int iResult = Fight();

		if (1 == iResult)
		{
			m_pCopyPlayer->Set_Hp(m_pCopyPlayer->Get_Info().iMaxHp);
		}

		if (nullptr != m_pMonster)
		{
			Release();
		}
	}
}

void	CField::Release()
{
	SAFE_DELETE(m_pMonster);
}

int		CField::Fight()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();
		m_pMonster->Render();

		cout << "-----------------------------------------------------------------------" << endl;
		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (1 == iInput)
		{
			m_pMonster->Set_Damage(m_pCopyPlayer->Get_Info().iAttack);
			m_pCopyPlayer->Set_Damage(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pCopyPlayer->Get_Info().iHp)
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				return 1;
			}

			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "몬스터 처치" << endl;
				cout << "경험치 \t " << m_pMonster->Get_Ex() << " 획득" << endl;


				if ((m_pCopyPlayer->Get_CurEx() + m_pMonster->Get_Ex()) >= m_pCopyPlayer->Get_MaxEx())
				{
					m_pCopyPlayer->Level_Up(m_pMonster->Get_Ex());
				}
				else
				{
					m_pCopyPlayer->Set_CurEx(m_pMonster->Get_Ex());
				}

				system("pause");
				return 0;
			}
		}
		else if (2 == iInput)
			return 0;


	}
}