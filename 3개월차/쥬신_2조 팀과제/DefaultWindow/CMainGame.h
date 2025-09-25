#pragma once

#include "Define.h"
#include "CPlayer.h"

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
	HDC				m_hDC;
	//CObj*			m_pPlayer;

	list<CObj*>		m_ObjList[OBJ_END];

};
