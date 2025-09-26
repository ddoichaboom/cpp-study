#pragma once

#include "Define.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCollisionMgr.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();

private:
	HDC		m_hDC;
	HBITMAP m_hBit;
	HDC m_memDC;
	list<CObj*> m_ObjList[OBJ_END];
	clock_t TimeCheck;
};

