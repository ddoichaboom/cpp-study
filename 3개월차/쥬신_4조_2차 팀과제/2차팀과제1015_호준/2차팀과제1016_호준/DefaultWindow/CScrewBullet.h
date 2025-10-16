#pragma once
#include "CObj.h"
class CScrewBullet :
    public CObj
{
public:
    CScrewBullet();
    virtual ~CScrewBullet();
    
public:
    void Initialize() override;
    int Update(float deltaTime) override;
    void Late_Update(float deltaTime) override;
    void Render(HDC hDC) override;
    void Release() override;

private:
    bool    m_bStart;

    POINT   m_tCenter;

    float   m_fRotAngle;
    float   m_fRotSpeed;

};

