#include "pch.h"
#include "CPlayer.h"
#include "CItem.h"

CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	memset(&m_pItemSlot, 0, sizeof(CObj*) * IT_END);
}

CPlayer::~CPlayer()
{
}

void CPlayer::Select_Job()
{
	int iInput(0);

	cout << "직업을 선택하세요 ( 1. 전사 2. 마법사 3. 도적 ) : ";
	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "전사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iMoney = 10000;
		break;

	case MAGE:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "마법사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "도적");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iMoney = 10000;
		break;

	}
}

void CPlayer::Render()
{
	cout << "---------------------------------------" << endl;
	cout << "직업 : " << m_tInfo.cName << "\t소지금 : " << m_tInfo.iMoney << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}

void	CPlayer::Equip_item(CObj* pInvenItem)
{
	ITEMTYPE eType = dynamic_cast<CItem*>(pInvenItem)->Get_Type();

	if (nullptr != m_pItemSlot[eType])
	{
		Item_Ability(-m_pItemSlot[eType]->Get_Info().iAttack, -m_pItemSlot[eType]->Get_Info().iHp);
		dynamic_cast<CItem*>(m_pItemSlot[eType])->Set_State(UNEQUIP);
		m_pItemSlot[eType] = nullptr;
	}

	Item_Ability(pInvenItem->Get_Info().iAttack, pInvenItem->Get_Info().iHp);
	dynamic_cast<CItem*>(pInvenItem)->Set_State(EQUIP);
	m_pItemSlot[eType] = pInvenItem;
}

void	CPlayer::UnEquip_item(CObj* pInvenItem)
{
	ITEMTYPE eType = dynamic_cast<CItem*>(pInvenItem)->Get_Type();

	if (nullptr != m_pItemSlot[eType])
	{
		Item_Ability(-m_pItemSlot[eType]->Get_Info().iAttack, -m_pItemSlot[eType]->Get_Info().iHp);
		dynamic_cast<CItem*>(m_pItemSlot[eType])->Set_State(UNEQUIP);
		m_pItemSlot[eType] = nullptr;
	}

}

void	CPlayer::Item_Ability(int iAttack, int iHp)
{
	m_tInfo.iAttack += iAttack;
	m_tInfo.iHp += iHp;
}