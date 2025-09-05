#pragma once
#include "CObj.h"

class CItem	: public CObj
{
public:
	CItem();
	CItem(const char* pName, int iHp, int iAttack, int iMoney = 0);
	virtual	~CItem();

public:
	void	Render() override;
};

