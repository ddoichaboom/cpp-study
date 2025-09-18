#pragma once

#include "CObj.h"

class CItem : public CObj
{
public:
				CItem();
				CItem(const char* pName, int iHp, int iAttack, int iMoney);
				CItem(const CItem& rhs);
	virtual		~CItem();

public:
	void		Set_IsAvailable(bool bIsAvailable) { m_bIsAvailable = bIsAvailable; }
	void		Set_State(EQUIPSTATE eState) { m_eState = eState; }
	void		Set_Type(ITEMTYPE eType) { m_eType = eType; }
	void		Set_Class(ITEMCLASS eClass) { m_eClass = eClass; }

public:
	bool			Get_IsAvailable() { return m_bIsAvailable; }
	EQUIPSTATE		Get_State() { return m_eState; }
	ITEMTYPE		Get_Type() { return m_eType; }
	ITEMCLASS		Get_Class() { return m_eClass; }

public:
	void		Render() override;

private:
	bool			m_bIsAvailable;
	EQUIPSTATE		m_eState;
	ITEMTYPE		m_eType;
	ITEMCLASS		m_eClass;

};

