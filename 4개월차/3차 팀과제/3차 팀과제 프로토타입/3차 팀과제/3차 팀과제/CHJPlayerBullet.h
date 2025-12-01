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

public:
    void    Fire(const D3DXVECTOR3& vStartPos, const D3DXVECTOR3& vDir);

private:
    void    Bullet_Movement();
};

