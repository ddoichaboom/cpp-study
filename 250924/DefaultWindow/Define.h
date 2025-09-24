#pragma once

#define WINCX		800
#define WINCY		600

#define PURE		= 0

extern	HWND g_hWnd;

enum DIRECTION
{
	DIR_UP,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LU,
	DIR_RU,
	DIR_LD,
	DIR_RD,
	DIR_END = 9
};

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