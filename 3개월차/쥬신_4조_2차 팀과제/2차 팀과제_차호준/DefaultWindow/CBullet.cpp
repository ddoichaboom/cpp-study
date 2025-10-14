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

int CBullet::Update(double deltaTime)
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

   


	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
    //if (0 >= m_tRect.left || m_tRect.right >= WINCX ||
    //    0 >= m_tRect.top || m_tRect.bottom >= WINCY)
    //{
    //    m_bDead = true;
    //}

    m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
    m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
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

