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
	void		Render() override;

private:
	EQUIPSTATE		m_eState;
	ITEMTYPE		m_eType;
	ITEMCLASS		m_eClass;
};

