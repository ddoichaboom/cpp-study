#pragma once
#include "CObj.h"
class CShield :
    public CObj
{
public:
    CShield();
    virtual ~CShield();

public:
    void Initialize() override;
    int Update(double deltaTime) override;
    void Late_Update(double deltaTime) override;
    void Render(HDC hDC) override;
    void Release() override;
};

