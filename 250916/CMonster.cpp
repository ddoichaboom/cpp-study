#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{

}

CMonster::CMonster(const char* pName, int iHp, int iAttack)
	:CObj(pName, iHp, iAttack)
{

}


CMonster::~CMonster()
{

}

void	CMonster::Render() 
{
	cout << "---------------------------------------" << endl;
	cout << "직업 : " << m_tInfo.cName  << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}


