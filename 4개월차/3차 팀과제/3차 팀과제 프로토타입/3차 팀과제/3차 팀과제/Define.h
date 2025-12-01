#pragma once
#define WINCX 800
#define WINCY 600

#define PURE = 0

#define VK_MAX 0xff

#define OBJ_NOEVENT 0
#define OBJ_DEAD 1

extern HWND g_hWnd;

// 호준 추가 
namespace Color
{
	extern HBRUSH	g_hDefaultMonsterBrush;
	extern HPEN		g_hDefaultMonsterPen;
	extern HBRUSH	g_hTraceMonsterBrush;
	extern HPEN		g_hTraceMonsterPen;
	extern HBRUSH	g_hPlayerBulletBrush;
	extern HPEN		g_hPlayerBulletPen	;
	extern HBRUSH	g_hMonsterBulletBrush;
	extern HPEN		g_hMonsterBulletPen	;
}

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;		// 위치 벡터

	D3DXVECTOR3		vDir;		// 방향 벡터
	D3DXVECTOR3		vLook;

	D3DXVECTOR3		vNormal;	// 법선(노말) 벡터

	D3DXMATRIX		matWorld;

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

// TODO : 추가 필요하면 추가하고 주석 쓰기
// 호준 추가 - PLAYER BULLET, MONSTER BULLET 추가
enum OBJ_ID
{
	PLAYER,
	MONSTER,
	PLAYER_BULLET,			// 호준 추가 
	MONSTER_BULLET,			// 호준 추가 
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
		: tLeft(tLeftPoint), tRight(tRightPoint) {
	}

	LINEPOINT	tLeft;
	LINEPOINT	tRight;

}LINE;

static D3DXVECTOR3	Get_Mouse()
{
	POINT	ptMouse{};
	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	return D3DXVECTOR3((float)ptMouse.x, (float)ptMouse.y, 0.f);
}