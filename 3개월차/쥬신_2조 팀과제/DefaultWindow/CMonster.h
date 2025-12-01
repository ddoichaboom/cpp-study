#pragma once

#include "CObj.h"

class CMonster
	: public	CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	void Set_Bullet(list<CObj*> pBullet) { m_pBullet = pBullet; }

public:
	void Initialize() override;
	int Update() override;
	void Late_Update()	override;
	void Render(HDC hDC) override;
	void Release() override;

public:
	list<CObj*>		m_pBullet;

};
