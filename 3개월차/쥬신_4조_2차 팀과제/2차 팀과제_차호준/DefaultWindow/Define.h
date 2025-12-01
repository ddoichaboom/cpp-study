#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		=	0

#define	OBJ_NOEVENT		0
#define	OBJ_DEAD		1

#define PI				3.141592f
#define GC				981.f			// 중력 상수 ( Gravitational Constant : 9.81f) 
#define CoF				100.f			// 바닥면 마찰 계수 (Coefficient of Friction : 1.0f)
#define AoF				40.f			// 공기 저항 계수 ( 0.4f )
#define	VK_MAX			0xff

#define BOUNDARY_LEFT	0.f
#define BOUNDARY_TOP	0.f
#define BOUNDARY_RIGHT	800.f
#define BOUNDARY_BOTTOM 600.f

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
	MOUSE,
	SHIELD,
	OBJ_END
};

typedef struct tagLinePoint
{
	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

	float	fX;
	float	fY;

}LINEPOINT;

typedef struct tagLine
{
	tagLine() { ZeroMemory(this, sizeof(tagLine)); }

	tagLine(LINEPOINT& tLeftPoint, LINEPOINT& tRightPoint)
		: tLeft(tLeftPoint), tRight(tRightPoint) 
	{
		if (tLeft.fX != tRight.fX)
		{
			tfRadian = (float)atan2((tRight.fY - tLeft.fY), (tRight.fX - tLeft.fX));
			tfTilt = tanf(tfRadian);
			tfYInter = tLeft.fY - tfTilt * (tLeft.fX);
		}
		else
		{
			tfRadian = (float)atan2((tRight.fY - tLeft.fY), (tRight.fX - tLeft.fX));
			tfTilt = numeric_limits<float>::infinity();		 
			tfYInter = 0;
		}
	}

	LINEPOINT		tLeft;
	LINEPOINT		tRight;

	float			tfTilt;		// 기울기
	float			tfYInter;	// y 절편 ( x가 0일 때의 y값 )
	float			tfRadian;
	
}LINE;


