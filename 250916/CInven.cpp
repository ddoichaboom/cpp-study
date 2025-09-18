#include "pch.h"
#include "CInven.h"
#include "CPlayer.h"

CInven::CInven()
{
	m_pCopyPlayer = nullptr;
}

CInven::~CInven()
{
	Release();
}

void	CInven::Initialize()
{

}

void	CInven::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();

		cout << "1. 장착 2. 해제 3. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Equip_Item();
			break;

		case 2:
			Unequip_Item();
			break;

		case 3:
			return;
		}

		system("pause");
	}
}

void	CInven::Release()
{
	m_vecInven.clear();
}

void	CInven::Render()
{
	for (size_t i = 0; i < m_vecInven.size(); ++i)
	{
		cout << i + 1 << ". ";
		m_vecInven[i]->Render();
	}
}

void CInven::Equip_Item()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pCopyPlayer->Render();
		Render();

		cout << "0. 나가기";
		cin >> iInput;
		--iInput;

		if (iInput < 0)
			return;

		if ((size_t)iInput >= m_vecInven.size())
			return;
		dynamic_cast<CPlayer*>(m_pCopyPlayer)->Equip_item(m_vecInven[iInput]);
	}
}

void CInven::Unequip_Item()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_vecItemSlot.clear();

		m_pCopyPlayer->Render();

		if (static_cast<CPlayer*>(m_pCopyPlayer)->Get_Item_Slot(IT_WEAPON))
			m_vecItemSlot.push_back(static_cast<CPlayer*>(m_pCopyPlayer)->Get_Item_Slot(IT_WEAPON));
			
		if (static_cast<CPlayer*>(m_pCopyPlayer)->Get_Item_Slot(IT_ARMOR))
			m_vecItemSlot.push_back(static_cast<CPlayer*>(m_pCopyPlayer)->Get_Item_Slot(IT_ARMOR));
		
		if(m_vecItemSlot.size() != 0)
			Equip_Item_Render();

		cout << "0. 나가기 : ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if (size_t(iInput) >= m_vecItemSlot.size())
			return;

		dynamic_cast<CPlayer*>(m_pCopyPlayer)->UnEquip_item(m_vecItemSlot[iInput]);
	}
}

void CInven::Set_Inven(CObj* pItem)
{
	CObj* pPurchasedItem = pItem;
	m_vecInven.push_back(pPurchasedItem);
}

void CInven::Equip_Item_Render()
{
	for (size_t i = 0; i < m_vecItemSlot.size(); ++i)
	{
		cout << i + 1 << ". ";
		m_vecItemSlot[i]->Render();
	}
}