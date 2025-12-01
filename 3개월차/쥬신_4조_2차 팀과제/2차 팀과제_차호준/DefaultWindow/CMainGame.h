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
	HDC				m_hDC;
	HBITMAP			m_hBit;
	HDC				m_memDC;

	ULONGLONG		m_currTime;
	ULONGLONG		m_prevTime;
	double			m_deltaTime;
};

