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
    m_tInfo.fCX = 10.f;
    m_tInfo.fCY = 10.f;

    m_fSpeed = 3.f;
}

int CBullet::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

    switch (m_eDir)
    {
    case DIR_LEFT:
        m_tInfo.fX -= m_fSpeed;
        break;

    case DIR_RIGHT:
        m_tInfo.fX += m_fSpeed;
        break;

    case DIR_UP:
        m_tInfo.fY -= m_fSpeed;
        break;

    case DIR_DOWN:
        m_tInfo.fY += m_fSpeed;
        break;

    case DIR_LU:
        m_tInfo.fX -= m_fSpeed;
        m_tInfo.fY -= m_fSpeed;
        break;

    case DIR_RU:
        m_tInfo.fX += m_fSpeed;
        m_tInfo.fY -= m_fSpeed;
        break;


    }

    return 0;
}

void CBullet::Late_Update()
{

}

void CBullet::Render(HDC hDC)
{
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
}

void CBullet::Release()
{
}