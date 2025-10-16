#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0

#define	OBJ_NOEVENT		0
#define	OBJ_DEAD		1

#define PI				3.141592f
#define	VK_MAX			0xff

#pragma region 호준 - 새로 추가

#define GC				981.f			// 중력 상수 ( Gravitational Constant : 9.81f) 
#define CoF				2.f			// 바닥면 마찰 계수 (Coefficient of Friction)
#define AoF_X			70.f			// 공기 저항 계수 
#define AoF_Y			50.f
#define INV_SQRT2    0.70710678f		// 1.0f / sqrtf(2.0f) : 1 / 루트 2 

#define BOUNDARY_LEFT	0.f
#define BOUNDARY_TOP	0.f
#define BOUNDARY_RIGHT	1920.f
#define BOUNDARY_BOTTOM 1250.f

#define INFINITY		numeric_limits<float>::infinity()

#pragma endregion


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

#pragma region 호준 - 일부 수정 
// 총알 - 플레이어 총알, 몬스터 총알 구분
enum OBJID
{
	PLAYER,
	PLAYERBULLET,
	MONSTER,
	MONSTERBULLET,
	MOUSE,
	SHIELD,
	BUTTON,
	OBJ_END
};
#pragma endregion

typedef struct tagLinePoint
{
	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

	float	fX;
	float	fY;

}LINEPOINT;

#pragma region 호준 - 일부 수정
// LINE 구조체에 
// tfTilt(직선의 기울기), tfYInter(y 절편 : x가 0일 때의 y값), tfRadian(직선의 기울기를 통한 각도(라디안)반환 - 바로 사용 가능)
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
			tfTilt = INFINITY;
			tfYInter = 0;
		}
	}

	LINEPOINT		tLeft;
	LINEPOINT		tRight;

	float			tfTilt;		// 기울기
	float			tfYInter;	// y 절편 ( x가 0일 때의 y값 )
	float			tfRadian;

}LINE;
#pragma endregion



typedef struct tagPlayerInfo
{
	float fMoneny;
	float HP;
}PLAYERINFO;