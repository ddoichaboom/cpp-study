#include "pch.h"
#include "CShield.h"

CShield::CShield()
{
}

CShield::~CShield()
{
    Release();
}

void CShield::Initialize()
{
    m_tInfo.fCX = 80.f;
    m_tInfo.fCY = 80.f;
    m_fSpeed = 0.f;
}

int CShield::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();
    

    return OBJ_NOEVENT;
}

void CShield::Late_Update()
{
}

void CShield::Render(HDC hDC)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(135, 206, 235));
    HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, hBrush);
    HPEN hPen = CreatePen(PS_NULL, 0, RGB(255, 255, 255));
    HGDIOBJ OldPen = SelectObject(hDC, hPen);
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
    SelectObject(hDC, OldBrush);
    SelectObject(hDC, OldPen);
    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void CShield::Release()
{
}
