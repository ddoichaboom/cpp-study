#pragma once

#include "Define.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	void	Set_Damage(int iAttack) { m_tInfo.iHp -= iAttack; }
	void	Set_Hp(int iHp) { m_tInfo.iHp = iHp; }
	INFO	Get_Info() { return m_tInfo; }

public:
	void	Select_Job();
	void	Render();
private:
	INFO	m_tInfo;
};

