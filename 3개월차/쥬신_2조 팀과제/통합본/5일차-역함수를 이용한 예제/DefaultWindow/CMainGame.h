#pragma once

#include "Define.h"
#include "CPlayer.h"

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
	HBITMAP	m_hBit;
	HDC		m_memDC;
	size_t			m_iAmount;
	DWORD			m_dwElapsed;

	TCHAR			m_szFPS[32];
	TCHAR			m_szBuff[32];
	int				m_iFPS;
	DWORD			m_dwStartTime;
};


