#pragma once

#include "CObj.h"

class CPlayer	: public CObj
{
public:
			CPlayer();
	virtual ~CPlayer();

public:
	void	Set_Hp(int iHp)			{ m_tInfo.iHp = iHp; }
	void	Set_Money(int iMoney)	{ m_tInfo.iMoney += iMoney; }

public:
	void	Select_Job();
	void	Render() override;


};

