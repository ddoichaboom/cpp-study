#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    m_tInfo.fCX = 60.f;
    m_tInfo.fCY = 60.f;
    m_fSpeed = 5.f;
}

int CMonster::Update(double deltaTime)
{
    if (m_bDead)
        return OBJ_DEAD;


    __super::Update_Rect();


    return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
    //float   fWidth(0.f), fHeight(0.f), fDiagonal(0.f);
    //
    //fWidth  = m_pTarget->Get_Info()->fX - m_tInfo.fX;
    //fHeight = m_pTarget->Get_Info()->fY- m_tInfo.fY;
    //
    //fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
    //
    //float fRadian = acosf(fWidth / fDiagonal);
    //
    //m_fAngle = fRadian * 180.f / PI;
    //
    //if (m_tInfo.fY < m_pTarget->Get_Info()->fY)
    //    m_fAngle *= -1.f;
    //
    //m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
    //m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

    //if (m_tInfo.fY < m_pTarget->Get_Info()->fY)
    //    fRadian = 2.f * PI - fRadian;
    //
    //m_tInfo.fX += m_fSpeed * cosf(fRadian);
    //m_tInfo.fY -= m_fSpeed * sinf(fRadian);
}

void CMonster::Render(HDC hDC)
{
    Rectangle(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
}

void CMonster::Release()
{
}
