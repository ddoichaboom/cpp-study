#pragma once
#include "Define.h"
#include "CObj.h"

class CMonster : public CObj
{
public:
	CMonster();
	CMonster(const char* pName, int iHp, int iAttack);
	~CMonster();

public:
	void	Render() override;

};

