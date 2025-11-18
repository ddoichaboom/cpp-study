#pragma once
#include "CObj.h"

class CHJPlayerBullet :
    public CObj
{
public:
    CHJPlayerBullet();
    virtual ~CHJPlayerBullet();

public:
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
    void OnCollision(OBJ_ID eID) override;

};

