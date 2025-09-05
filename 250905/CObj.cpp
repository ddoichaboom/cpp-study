#include "pch.h"
#include "CObj.h"

CObj::CObj()
{
}

CObj::CObj(const char* pName, int iLv, int iMaxHp, int iHp, int iAttack)
	: m_tInfo(pName, iLv, iMaxHp, iHp, iAttack)
{
}

CObj::~CObj()
{
}



