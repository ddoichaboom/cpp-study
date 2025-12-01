#pragma once

#include "CObj.h"
#include "CBullet.h"
#include "CMonster.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void			Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	void			Set_Monster(list<CObj*>* pMonster) { m_pMonster = pMonster; }

public:
	void			Initialize()	override;
	int				Update()		override;
	void			Late_Update()	override;
	void			Render(HDC hDC)	override;
	void			Release()		override;



private:
	void			Key_Input();
	



private:
	list<CObj*>*	m_pBullet;
	list<CObj*>*	m_pMonster;
	PLAYERINFO		m_tPInfo;
};
