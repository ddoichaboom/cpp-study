#pragma once
#include "pch.h"
#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define		PURE			= 0

enum ITEMTYPE { IT_WEAPON, IT_ARMOR, IT_END };
enum ITEMCLASS
{
	BEGINNER,
	RARE,
	UNIQUE,
	IC_END
};

typedef struct tagInfo
{
	char	cName[32];
	int		iHp;
	int		iAttack;
	int		iMoney;

	tagInfo()
	{
		memset(this, 0, sizeof(INFO));
	}
	tagInfo(const char* pName, int _iHp, int _iAttack, int _iMoney = 0)
		:iHp(_iHp), iAttack(_iAttack), iMoney(_iMoney)
	{
		strcpy_s(cName, sizeof(cName), pName);
	}
}INFO;