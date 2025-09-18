#pragma once

#include "CObj.h"

class CInven
{
public:
	CInven();
	~CInven();

public:
	void	Set_Player(CObj* pPlayer) { m_pCopyPlayer = pPlayer; }
	void	Set_Inven(CObj* pItem);

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	void	Render();
	void	Equip_Item();
	void	Unequip_Item();
	void	Equip_Item_Render();

private:
	CObj*				m_pCopyPlayer;
	vector<CObj*>		m_vecInven;
	vector<CObj*>		m_vecItemSlot;

};

