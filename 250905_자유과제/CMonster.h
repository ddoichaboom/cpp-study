#pragma once
#include "CObj.h"

class CMonster	: public CObj
{
public:
	CMonster();
	CMonster(const char* pName, int iHp, int iAttack, int iMoney = 0);
	virtual ~CMonster();

public:
	void	Render() override;
};

