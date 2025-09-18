#pragma once

#include "CItem.h"
#include "CPlayer.h"
#include "CInven.h"

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
	vector<CObj*>	Get_Vector() { return m_vecItem; }

public:
	void	Set_Player(CObj* pPlayer) { m_pCopyPlayer = pPlayer; }
	void	Set_Inven(CInven* pInven) { m_pInven = pInven; }
	void	Render(ITEMCLASS eClass);
	void	Sell_Item();

private:
	CObj*				m_pCopyPlayer;
	vector<CObj*>		m_vecItem;
	CInven*				m_pInven;
	
};

