#pragma once

#define		WINCX			800
#define		WINCY			600

#define		BOUNDARY_LEFT	100.f
#define		BOUNDARY_RIGHT  700.f
#define		BOUNDARY_TOP	100.f
#define		BOUNDARY_BOTTOM	500.f

#define		PURE		= 0

#define		OBJ_NOEVENT	0
#define		OBJ_DEAD	1

extern	HWND	g_hWnd;



typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;
}INFO;

template <typename T>
void	Safe_Delete(T& p)
{
	if (p)
	{
		delete p; 
		p = nullptr;
	}
}