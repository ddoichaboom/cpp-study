#pragma once
#include "CObj.h"
class CMonster :
    public CObj
{
public:
    CMonster();
    virtual ~CMonster();
    
public:
    void Initialize() override;
    int Update(double deltaTime) override;
    void Late_Update(double deltaTime) override;
    void Render(HDC hDC) override;
    void Release() override;
};

