#pragma once
#include "Define.h"

class CObj
{
public:
	CObj();
	CObj(const char* pName, int iLv, int iMaxHp, int iHp, int iAttack);
	virtual		~CObj();

public:
	INFO		Get_Info() { return m_tInfo; }
	void		Set_Damage(int iAttack) { m_tInfo.iHp -= iAttack; }

public:
	virtual		void	Set_CurEx(int iEx) {}
	virtual		void	Set_MaxEx(int iMaxEx) {}
	virtual		void	Set_Hp(int iMaxHp) {}

public:
	virtual		int		Get_Ex() { return 1; }
	virtual		int		Get_CurEx() { return 1; }
	virtual		int		Get_MaxEx() { return 1; }

public:
	virtual		void	Level_Up(int iDrpEx) {}
	virtual		void	Select_Job() {}
	virtual		void	Render() {}

protected:
	INFO		m_tInfo;
};

