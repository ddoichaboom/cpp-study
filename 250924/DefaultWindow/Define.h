#pragma once

#define WINCX			800
#define WINCY			600

#define PURE			= 0

#define OBJ_NOEVENT		0
#define OBJ_DEAD		1

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