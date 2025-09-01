#pragma once

#define		SAFE_DELETE(p)	{ delete p; p = nullptr; }

typedef struct tagInfo
{
	char		cName[32];
	int			iHp;
	int			iAttack;

	tagInfo()
	{
		memset(this, 0, sizeof(INFO));
	}
	tagInfo(const char* pName, int  _iHp, int _iAttack)
		: iHp(_iHp), iAttack(_iAttack)
	{
		strcpy_s(cName, sizeof(cName), pName);
	}

}INFO;