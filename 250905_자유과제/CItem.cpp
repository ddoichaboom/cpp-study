#include "pch.h"
#include "CItem.h"

CItem::CItem()
{
	
}

CItem::CItem(const char* pName, int iHp, int iAttack, int iMoney)
	: CObj(pName, iHp, iAttack, iMoney)
{

}

CItem::~CItem()
{

}

void CItem::Render()
{
	cout << "------------------------------------------" << endl;
	cout << "이름 : " << m_tInfo.cName << "\t가격 : " << m_tInfo.iMoney << " 원" << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}