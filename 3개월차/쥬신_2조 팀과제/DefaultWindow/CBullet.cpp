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
    m_tInfo.fCX = 15.f;
    m_tInfo.fCY = 15.f;

    m_fSpeed = 5.f;

    switch (m_eBType)
    {
    case PL_BULLET:
        
        break;

    case MT_BULLET:
        
        break;

    case ST_BULLET:
        m_fAngle++;

        break;
    }
    m_tInfo.fCX = 15.f;
    m_tInfo.fCY = 15.f;

    m_fSpeed = 5.f;
}

int CBullet::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    if (m_eBType == ST_BULLET)
    {

    }
    else
    {
        __super::Update_Rect();

    }


    return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
    if (BOUNDARY_LEFT >= m_tRect.left || m_tRect.right >= BOUNDARY_RIGHT ||
        BOUNDARY_TOP >= m_tRect.top || m_tRect.bottom >= BOUNDARY_BOTTOM)
    {
        m_bDead = true;
    }

    switch (m_eBType)
    {
    case PL_BULLET:
        m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
        m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
        break;

    case MT_BULLET:
        m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
        m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
        break;

    case ST_BULLET:

        break;
    }
    

    
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