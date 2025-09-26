#include "pch.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
    Release();
}

void CBullet::Initialize()
{
    m_tInfo.fCX = 30.f;
    m_tInfo.fCY = 30.f;
    m_fSpeed = 5.f;
}

int CBullet::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    
    __super::Update_Rect();

    switch (m_eDir)
    {
    case DIR_UP:
        m_tInfo.fY -= m_fSpeed;
        break;
    case DIR_DOWN:
        m_tInfo.fY += m_fSpeed;
        break; 
    case DIR_CIRCLE:
        m_tInfo.fX = m_tInfo.fX + m_fSpeed * cos(m_iAngle * 3.14 / 180);
        m_tInfo.fY = m_tInfo.fY + m_fSpeed * sin(m_iAngle * 3.14 / 180);
        break;
    }

    return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
    if (m_tRect.left <= 100 || m_tRect.right >= WINCX - 100
        || m_tRect.top <= 100 || m_tRect.bottom >= WINCY - 100)
        m_bDead = true;
}

void CBullet::Render(HDC hDC)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 0));
    HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, hBrush);
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
    SelectObject(hDC, OldBrush);
    DeleteObject(hBrush);
}

void CBullet::Release()
{
}
