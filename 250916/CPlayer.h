#pragma once

#include "CObj.h"

class CPlayer	: public CObj
{
public:
			CPlayer();
	virtual ~CPlayer();

public:
	void	Set_Hp(int iHp)						{ m_tInfo.iHp = iHp; }
	void	Set_Money(int iMoney)				{ m_tInfo.iMoney += iMoney; }
	CObj*	Get_Item_Slot(ITEMTYPE eType)		{ return m_pItemSlot[eType]; }

public:
	void	Equip_item(CObj*	pInvenItem);
	void	UnEquip_item(CObj* pInvenItem);

	void	Item_Ability(int iAttack, int iHp);

public:
	void	Select_Job();
	void	Render() override;

private:
	CObj*	m_pItemSlot[IT_END];


};

