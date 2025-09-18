#include "pch.h"
#include "CShop.h"

CShop::CShop()
	: m_pCopyPlayer(nullptr), m_pInven(nullptr)
{}

CShop::~CShop()
{}

void	CShop::Initialize()
{
	for (int i = 0; i < 3; ++i)
	{
		if (i == BEGINNER)
		{
			CObj* pItem = new CItem("초급검", 0 , 10, 1000);
			static_cast<CItem*>(pItem)->Set_Type(IT_WEAPON);
			static_cast<CItem*>(pItem)->Set_Class(BEGINNER);
			m_vecItem.push_back(pItem);

			pItem = new CItem("초급갑옷", 10, 0, 1000);
			static_cast<CItem*>(pItem)->Set_Type(IT_ARMOR);
			static_cast<CItem*>(pItem)->Set_Class(BEGINNER);
			m_vecItem.push_back(pItem);
		}

		if (i == RARE)
		{
			CObj* pItem = new CItem("중급검", 0, 20, 2000);
			static_cast<CItem*>(pItem)->Set_Type(IT_WEAPON);
			static_cast<CItem*>(pItem)->Set_Class(RARE);
			m_vecItem.push_back(pItem);

			pItem = new CItem("중급옷", 20, 0, 2000);
			static_cast<CItem*>(pItem)->Set_Type(IT_ARMOR);
			static_cast<CItem*>(pItem)->Set_Class(RARE);
			m_vecItem.push_back(pItem);
		}

		if (i == UNIQUE)
		{
			CObj* pItem = new CItem("고급검", 0, 30, 3000);
			static_cast<CItem*>(pItem)->Set_Type(IT_WEAPON);
			static_cast<CItem*>(pItem)->Set_Class(UNIQUE);
			m_vecItem.push_back(pItem);

			pItem = new CItem("고급갑옷", 30, 0, 3000);
			static_cast<CItem*>(pItem)->Set_Type(IT_ARMOR);
			static_cast<CItem*>(pItem)->Set_Class(UNIQUE);
			m_vecItem.push_back(pItem);
		}
	}
}

void	CShop::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();

		cout << "1. 초급 2. 중급 3. 고급 4. 판매 5. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			Render(BEGINNER);
			break;

		case NORMAL:
			Render(RARE);
			break;

		case HARD:
			Render(UNIQUE);
			break;

		case 4:
			Sell_Item();
			break;

		case 5:
			return;
		}
	}
}

void	CShop::Release()
{

}

void	CShop::Render(ITEMCLASS eClass)
{
	int iInput(0);



	while (true)
	{
		CObj* w_iter = nullptr;
		CObj* a_iter = nullptr;

		system("cls");

		m_pCopyPlayer->Render();

		for (vector<CObj*>::iterator		iter = m_vecItem.begin();
			iter != m_vecItem.end();
			++iter)
		{
			if (static_cast<CItem*>(*iter)->Get_Class() == eClass)
			{

				if (static_cast<CItem*>(*iter)->Get_Type() == IT_WEAPON)
				{
					(*iter)->Render();

					if (static_cast<CItem*>(*iter)->Get_IsAvailable() == true)
					{
						w_iter = *iter;
						
					}

				}
				if (static_cast<CItem*>(*iter)->Get_Type() == IT_ARMOR)
				{
					(*iter)->Render();

					if (static_cast<CItem*>(*iter)->Get_IsAvailable() == true)
					{
						a_iter = (*iter);
						
					}

				}
			}
		}

		if ((w_iter == nullptr) && (a_iter == nullptr))
		{
			cout << "구매하실 수 있는 상품이 없습니다." << endl;
			system("pause");
			return;
		}

		cout << "1. 무기 구매 2. 방어구 구매 3. 전 단계 : ";
		cin >> iInput;

		if ((1 == iInput ) && w_iter != nullptr)
		{
			if ((m_pCopyPlayer->Get_Info().iMoney) >= (w_iter->Get_Info().iMoney))
			{
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_Money(-w_iter->Get_Info().iMoney);
				static_cast<CItem*>(w_iter)->Set_IsAvailable(false);
				m_pInven->Set_Inven(w_iter);
				cout << "구매 완료" << endl;
				system("pause");
				continue;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}
		else if ((1 == iInput) && w_iter == nullptr)
		{
			cout << "이미 구매하신 상품입니다." << endl;
		}
		else if ((2 == iInput) && a_iter != nullptr)
		{
			if (m_pCopyPlayer->Get_Info().iMoney >= a_iter->Get_Info().iMoney)
			{
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_Money(-a_iter->Get_Info().iMoney);
				static_cast<CItem*>(a_iter)->Set_IsAvailable(false);
				m_pInven->Set_Inven(a_iter);
				cout << "구매 완료" << endl;
				system("pause");
				continue;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}
		else if ((2 == iInput) && a_iter == nullptr)
		{
			cout << "이미 구매하신 상품입니다." << endl;
		}
		else if (3 == iInput)
		{
			return;
		}

		system("pause");
	}
}

void	CShop::Sell_Item()
{

}
