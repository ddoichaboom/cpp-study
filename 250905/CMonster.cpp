#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(const char* pName, int iLv, int iMaxHp, int iHp, int iAttack)
	: CObj(pName, iLv, iMaxHp, iHp, iAttack)
{

}

CMonster::~CMonster()
{
}

void CMonster::Render()
{
	int iBarLen = 10;
	int iPHp = (m_tInfo.iHp * iBarLen) / m_tInfo.iMaxHp;

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "<몬스터>\t\t\t"  << "난이도 \t: " << m_tInfo.cName << endl;
	cout << "채력 \t: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << " | ";
	for (int i = 0; i < iPHp; ++i)
	{
		cout << "# ";
	}
	for (int i = iPHp; i < iBarLen; ++i)
	{
		cout << "- ";
	}
	cout << "\n레벨 \t: " << m_tInfo.iLv << "\t\t\t\t" << "공격력 \t: " << m_tInfo.iAttack << endl;
	cout << "드랍 경험치 \t: " << m_iDrpEx << endl;

}

