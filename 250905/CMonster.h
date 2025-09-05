#pragma once
#include "CObj.h"

class CMonster : public CObj
{
public:
	CMonster();
	CMonster(const char* pName, int iLv, int iMaxHp, int iHp, int iAttack);
	~CMonster();

public:
	void	Set_Ex(int iDrpEx) { m_iDrpEx = iDrpEx; }

public:
	void	Render() override;
	int		Get_Ex() override { return m_iDrpEx; }

private:
	int		m_iDrpEx;
};

