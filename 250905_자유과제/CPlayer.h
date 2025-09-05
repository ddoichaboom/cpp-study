#pragma once
#include "CObj.h"

class CPlayer	: public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void	Select_Job();
	void	Set_Hp(int iHp) { m_tInfo.iHp = iHp; }

public:
	void	Render() override;

};

