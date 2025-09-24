#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0

extern HWND g_hWnd;

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;

}INFO;

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

