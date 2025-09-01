#pragma once

#include "CPlayer.h"
#include "CMonster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void Set_Player(CPlayer* pPlayer) { m_pCopyPlayer = pPlayer; }

public:
	void		Initialize();
	void		Update();
	void		Release();

private:
	int			Fight();

private:
	CPlayer*	m_pCopyPlayer;
	CMonster*	m_pMonster;

};

