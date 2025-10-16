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
    int Update(float deltaTime) override;
    void Late_Update(float deltaTime) override;
    void Render(HDC hDC) override;
    void Release() override;
};

