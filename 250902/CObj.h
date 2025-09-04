#pragma once
#include "Define.h"

class CObj
{
public:
	CObj();
	CObj(const char* pName, int iHp, int iAttack);
	virtual ~CObj();

public:
	void Set_Damage(int iAttack) { m_tInfo.iHp -= iAttack; }
	INFO Get_INFO() { return m_tInfo; }

public:
	virtual		void	Set_Hp(int iHp) {}
	virtual		void	Select_Job()	{}
	virtual		void	Render()		{}

protected:
	INFO	m_tInfo;
};

