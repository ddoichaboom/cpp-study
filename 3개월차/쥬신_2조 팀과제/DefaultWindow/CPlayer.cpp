#include "pch.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr), m_pMonster(nullptr)
{

}

CPlayer::~CPlayer()
{
    Release();
}

void CPlayer::Initialize()
{
    m_tInfo = { float(WINCX >> 1), float(WINCY >> 1), 32.f, 32.f };
    m_fSpeed = 10.f;
}

int CPlayer::Update()
{
    Key_Input();
    
    __super::Update_Rect();


    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
    RECT    rcBounDary = { BOUNDARY_LEFT, BOUNDARY_TOP, BOUNDARY_RIGHT, BOUNDARY_BOTTOM };
    RECT    rc = {};

    if (BOUNDARY_LEFT >= m_tRect.left || BOUNDARY_RIGHT <= m_tRect.right ||
        BOUNDARY_TOP >= m_tRect.top || BOUNDARY_BOTTOM <= m_tRect.bottom)
    {
        IntersectRect(&rc, &m_tRect, &rcBounDary);          // 박스 안에 있으면 rc = m_tRect

        if (BOUNDARY_LEFT >= rc.left)
            m_tInfo.fX += BOUNDARY_LEFT - rc.left;

        if (BOUNDARY_TOP >= rc.top)
            m_tInfo.fY += BOUNDARY_TOP - rc.top;

        if (BOUNDARY_RIGHT >= rc.right)
            m_tInfo.fX -= rc.right - BOUNDARY_RIGHT;

        if (BOUNDARY_BOTTOM <= rc.bottom)
            m_tInfo.fY -= rc.bottom - BOUNDARY_BOTTOM;
    }

}

void CPlayer::Render(HDC hDC)
{
    Rectangle(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
            m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
            m_tInfo.fY += m_fSpeed / sqrtf(2.f);
        }
        else
            m_tInfo.fX -= m_fSpeed;
    }

    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            m_tInfo.fX += m_fSpeed / sqrtf(2.f);
            m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            m_tInfo.fX += m_fSpeed / sqrtf(2.f);
            m_tInfo.fY += m_fSpeed / sqrtf(2.f);
        }
        else
            m_tInfo.fX += m_fSpeed;
    }

    else if (GetAsyncKeyState(VK_UP) & 0x8000)
        m_tInfo.fY -= m_fSpeed;

    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        m_tInfo.fY += m_fSpeed;


#pragma region  WASD 발사
    //if (GetAsyncKeyState('W') & 0x0001)
    //{
    //    m_pBullet->push_back(CAbstractFactory<CBullet>::
    //        Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_UP));
    //}

    //if (GetAsyncKeyState('A') & 0x0001)
    //{
    //    m_pBullet->push_back(CAbstractFactory<CBullet>::
    //        Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_LEFT));
    //}

    //if (GetAsyncKeyState('D') & 0x0001)
    //{
    //    m_pBullet->push_back(CAbstractFactory<CBullet>::
    //        Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));
    //}

    //if (GetAsyncKeyState('S') & 0x0001)
    //{
    //    m_pBullet->push_back(CAbstractFactory<CBullet>::
    //        Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_DOWN));
    //}

    //if (GetAsyncKeyState('Q') & 0x0001)
    //{
    //    m_pBullet->push_back(CAbstractFactory<CBullet>::
    //        Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_LU));
    //}

    //if (GetAsyncKeyState('E') & 0x0001)
    //{
    //    m_pBullet->push_back(CAbstractFactory<CBullet>::
    //        Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_RU));
    //}

#pragma endregion

    if (GetAsyncKeyState(VK_SPACE) & 0x0001)
    {
       m_pBullet->push_back(CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, 90));
    }

    if (GetAsyncKeyState('M') & 0x0001)
    {
        m_pMonster->push_back(CAbstractFactory<CMonster>::
            Create_Obj((int)(BOUNDARY_RIGHT - BOUNDARY_LEFT) >> 1, (int)(BOUNDARY_TOP + 200), HR_MONSTER));
    }
    

    

    // if (GetAsyncKeyState('W'))
}

//CObj* CPlayer::Create_Bullet(DIRECTION eDir)
//{
//    CObj* pBullet = new CBullet;
//
//    pBullet->Initialize();
//
//    pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
//    pBullet->Set_Direction(eDir);
//
//    return pBullet;
//}