#pragma once

#include "Define.h"
#include "CPlayer.h"
#include "CUi.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void			Initialize();
	int				Update();
	void			Late_Update();
	void			Render();
	void			Release();

private:
	HBITMAP			m_hBit;
	HDC				m_hDC;
	HDC				m_memDC;

	list<CObj*>		m_ObjList[OBJ_END];
	//CUi*			m_pUI;

	int				m_iFPS;
	size_t			m_iAmount;
	DWORD			m_dwStartTime;
	DWORD			m_dwElapsed;

	TCHAR			m_szFPS[32];
	TCHAR			m_szBuff[32];

};
