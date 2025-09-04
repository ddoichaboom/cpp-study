#pragma once
#include "Define.h"
#include "CObj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	~CPlayer();

public:
	void	Set_Hp(int iHp) override { m_tInfo.iHp = iHp; }

public:
	void	Select_Job() override;
	void	Render() override;

};

