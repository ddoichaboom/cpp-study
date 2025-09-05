#pragma once
#include "CPlayer.h"
#include "CItem.h"

class CStore
{
public:
	CStore();
	~CStore();

public:
	void	Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

public:
	void	Initialize();
	void	Update();
	void	Release();
	void	Render(ITEMCLASS eClass) ;

private:
	CObj*	m_pPlayer;
	CObj*	m_pItem[IT_END][IC_END];

};

