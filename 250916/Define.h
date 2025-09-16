#pragma once

#define		PURE = 0

enum CLASS
{
	WARRIOR = 1,
	MAGE,
	THIEF
};
enum MENU
{
	FIELD = 1,
	SHOP,
	INVENTORY,
	EXIT
};
enum DIFFICULTY
{
	EASY = 1, 
	NORMAL,
	HARD
};
enum BATTLE
{
	ATTACK = 1,
	RUN
};
enum EQUIPSTATE
{
	EQUIP,
	UNEQUIP,
	EQ_END
};
enum ITEMTYPE
{
	IT_WEAPON,
	IT_ARMOR,
	IT_END
};
enum ITEMCLASS
{
	BEGINNER,
	RARE,
	UNIQUE,
	IC_END
};

template <typename T>
void	Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}


typedef struct tagInfo
{
	char	cName[32];
	int		iAttack, iHp, iMoney;

	tagInfo()
	{
		memset(this, 0, sizeof(INFO));
	}
	tagInfo(const char* pName, int _iHp, int _iAttack, int _iMoney = 0)
		: iHp(_iHp), iAttack(_iAttack), iMoney(_iMoney)
	{
		strcpy_s(cName, sizeof(cName), pName);
	}
	tagInfo(const tagInfo& rhs)
		: iHp(rhs.iHp), iAttack(rhs.iAttack), iMoney(rhs.iMoney)
	{
		strcpy_s(cName, sizeof(cName), rhs.cName);
	}

}INFO;