#include "pch.h"
#include "CItem.h"

CItem::CItem()
	: m_eType(IT_END), m_eState(EQ_END), m_eClass(IC_END), m_bIsAvailable(true)
{}

CItem::CItem(const char* pName, int iHp, int iAttack, int iMoney)
	: CObj(pName, iHp, iAttack, iMoney), m_eType(IT_END), m_eState(EQ_END), m_eClass(IC_END), m_bIsAvailable(true)
{}

CItem::CItem(const CItem& rhs)
	:CObj(rhs), m_eType(rhs.m_eType), m_eState(rhs.m_eState), m_eClass(rhs.m_eClass), m_bIsAvailable(true)
{}

CItem::~CItem()
{}

void	CItem::Render()
{
	cout << "---------------------------------------" << endl;
	cout << "이름 : " << m_tInfo.cName << "\t가격 : " << m_tInfo.iMoney << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
