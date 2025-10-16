#pragma once
#include "CObj.h"
class CMouseCHA :
    public CObj
{
public:
    CMouseCHA();
    virtual ~CMouseCHA();

public:
    void Initialize() override;
    int Update(float deltaTime) override;
    void Late_Update(float deltaTime) override;
    void Render(HDC hDC) override;
    void Release() override;
};

