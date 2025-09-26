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
    m_tInfo.fCX = 40.f;
    m_tInfo.fCY = 40.f;
    m_fSpeed = 5.f;
}

int CMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    clock_t ckNow = clock();
    m_tInfo.fX += m_fSpeed;
    __super::Update_Rect();
    if (ckNow - TimeCheck >= 1000)
    {
        m_iAngle += 10;
        TimeCheck = ckNow;
        /*m_pBullet->push_back(CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_CIRCLE, m_iAngle));*/
        // 원을 그리며 발사
        
        m_pBullet->push_back(CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_DOWN, m_iAngle));
        // 아래로 발사

        /*m_pBullet->push_back(CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_DOWN, m_iAngle));*/
        
    }
    return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
    if (m_tRect.left <= 100 || m_tRect.right >= WINCX - 100)
        m_fSpeed *= -1.f;
}

void CMonster::Render(HDC hDC)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, hBrush);
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
    SelectObject(hDC, OldBrush);
    DeleteObject(hBrush);
}

void CMonster::Release()
{
}
