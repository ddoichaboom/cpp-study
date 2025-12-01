#pragma once
#include "CObj.h"
class CMouse :
    public CObj
{
public:
    CMouse();
    virtual ~CMouse();

public:
    void Initialize() override;
    int Update(double deltaTime) override;
    void Late_Update(double deltaTime) override;
    void Render(HDC hDC) override;
    void Release() override;
};

