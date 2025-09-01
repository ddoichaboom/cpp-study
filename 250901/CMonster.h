#pragma once

#include "Define.h"

class CMonster
{
public:
	CMonster();
	CMonster(const char* pName, int iHp, int iAttack);
	~CMonster();

public:
	void		Set_Damage(int iAttack) { m_tInfo.iHp -= iAttack; }
	INFO		Get_INFO() { return m_tInfo; }

public:
	void		Render();

private:
	INFO		m_tInfo;
};

