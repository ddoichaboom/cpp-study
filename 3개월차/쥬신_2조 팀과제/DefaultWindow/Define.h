#pragma once

#define		WINCX			800
#define		WINCY			600

#define		PURE			= 0

#define		OBJ_NOEVENT		0
#define		OBJ_DEAD		1

#define		BOUNDARY_LEFT	 50.f
#define		BOUNDARY_TOP	 0.f
#define		BOUNDARY_RIGHT   450.f
#define		BOUNDARY_BOTTOM	 600.f

#define		PI	 3.141592f

extern	HWND g_hWnd;


typedef	struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
	
}INFO;

template <typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

enum DIRECTION
{
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN,
	DIR_LU,
	DIR_RU,
	DIR_END
};

enum OBJID
{
	PLAYER,
	BULLET,
	MONSTER,
	SHIELD,
	OBJ_END
};

enum MONSTERTYPE
{
	HR_MONSTER,
	VT_MONSTER,
	UQ_MONSTER,
	MT_END
};