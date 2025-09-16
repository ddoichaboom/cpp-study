#pragma once

#include "CObj.h"

class CMonster	: public CObj
{
public:
	CMonster();
	CMonster(const char* pName, int iHp, int iAttack);
	virtual		~CMonster();

public:
	virtual	void Render() override;

};

