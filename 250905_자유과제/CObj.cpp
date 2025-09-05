#include "pch.h"
#include "CObj.h"

CObj::CObj()
{
}

CObj::CObj(const char* pName, int iHp, int iAttack, int iMoney)
	: m_tInfo(pName, iHp, iAttack, iMoney)
{

}

CObj::~CObj()
{

}