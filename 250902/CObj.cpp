#include "pch.h"
#include "CObj.h"

CObj::CObj()
{

}

CObj::CObj(const char* pName, int iHp, int iAttack)
	: m_tInfo(pName, iHp, iAttack)
{

}

CObj::~CObj()
{

}

