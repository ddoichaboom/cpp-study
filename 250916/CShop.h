#pragma once

#include "CItem.h"

class CShop
{
public:
	CShop();
	~CShop();

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	void	Set_Player(CObj* pPlayer) { m_pCopyPlayer = pPlayer; }

private:
	CObj*				m_pCopyPlayer;
	vector<CObj*>		m_vecItem;
	
};

