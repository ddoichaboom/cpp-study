#pragma once

#include "CObj.h"
#include "CBullet.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
	
public:
	//void	Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	//void	Set_Shield(list<CObj*>* pShield) { m_pShield = pShield; }

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	void	Key_Input();
	//template<typename T>
	//CObj* Create_Bullet(float fX, float fY, float fAngle);
	//CObj* Create_Shield();
private:
	//list<CObj*>*	m_pBullet;
	//list<CObj*>*	m_pShield;

	POINT			m_tPosin;
};

