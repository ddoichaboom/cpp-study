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
    __super::Update_Rect();
    
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
