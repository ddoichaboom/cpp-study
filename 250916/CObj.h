#pragma once
#include "Define.h"

class CObj
{
public:
					CObj();
					CObj(const char* pName, int iHp, int iAttack, int iMoney = 0);
					CObj(const CObj& rhs);
	virtual			~CObj();

public:
			void	Set_Damage(int iAttack) { m_tInfo.iHp -= iAttack; }
			INFO	Get_Info()				{ return m_tInfo; }

public:
	virtual	void	Render() PURE;

protected:
			INFO	m_tInfo;

};

