#pragma once
#include "CObj.h"

class CHJMonsterBullet :
    public CObj
{
public:
    CHJMonsterBullet();
    virtual ~CHJMonsterBullet();

public:
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
    void OnCollision(OBJ_ID eID) override;
};

