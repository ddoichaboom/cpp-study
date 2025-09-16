#pragma once

#include "CObj.h"

class CInven
{
public:
	CInven();
	~CInven();

public:
	void	Set_Player(CObj* pPlayer) { m_pCopyPlayer = pPlayer; }
	void	Set_Inven(vector<CObj*>& vecItem) { m_vecInven = vecItem; }
public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	void	Render();

private:
	CObj*				m_pCopyPlayer;
	vector<CObj*>		m_vecInven;

};

