#pragma once
#include "CObj.h"
#include "CBullet.h"
#include "CAbstractFactory.h"

class CMonster :
    public CObj
{
public:
    CMonster();
    ~CMonster();

public:
    void Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }

public:
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

private:
    list<CObj*>* m_pBullet;
    clock_t TimeCheck;
};

