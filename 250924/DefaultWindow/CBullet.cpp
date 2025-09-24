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
    // 탄환 사이즈 지정
    m_tInfo.fCX = 30.f;
    m_tInfo.fCY = 30.f;

    // 탄환 이동 속도 지정
    m_fSpeed = 5.f;
}

int CBullet::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();
    
    switch (m_eDir)
    {
    case DIR_LEFT:
    case DIR_RIGHT:
    case DIR_UP:
    case DIR_DOWN:
    case DIR_LU:
    case DIR_RU:
    
    }

    m_tInfo.fY -= m_fSpeed;

    return 0;
}

void CBullet::Render(HDC hDC)
{
    // 원 형태의 탄환 그리기 함수 (Ellipse)
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
}

void CBullet::Release()
{
}
