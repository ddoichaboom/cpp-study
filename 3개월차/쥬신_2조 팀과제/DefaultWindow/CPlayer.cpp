#include "pch.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr), m_pMonster(nullptr)
{
    ZeroMemory(&m_tPInfo, 0);
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
  

    __super::Update_Rect();

    Key_Input();

    //__super::Update_Rect();



    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
    if (m_tInfo.fX <= BOUNDARY_LEFT + m_tInfo.fCX / 2)
    {
        m_tInfo.fX = BOUNDARY_LEFT + m_tInfo.fCX / 2;
    }
    
     if (m_tInfo.fY <= BOUNDARY_TOP + m_tInfo.fCY / 2)
        {
            m_tInfo.fY = BOUNDARY_TOP + m_tInfo.fCY / 2;
        }

      if (m_tInfo.fX >= BOUNDARY_RIGHT - m_tInfo.fCX / 2)
         {
           m_tInfo.fX = BOUNDARY_RIGHT - m_tInfo.fCX / 2;
         }

     if (m_tInfo.fY >= BOUNDARY_BOTTOM - m_tInfo.fCY / 2)
        {
           m_tInfo.fY = BOUNDARY_BOTTOM - m_tInfo.fCY / 2;
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




    if (GetAsyncKeyState(VK_SPACE) & 0x0001)
    {
       m_pBullet->push_back(CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, 90, PL_BULLET));
    }

    if (GetAsyncKeyState('M') & 0x0001)
    {
        m_pMonster->push_back(CAbstractFactory<CMonster>::
            Create_Obj((int)(BOUNDARY_RIGHT - BOUNDARY_LEFT) >> 1, (int)(BOUNDARY_TOP + 200), HR_MONSTER));
    }
    
    if (GetAsyncKeyState('R') & 0x0001)
    {
        m_pBullet->push_back(CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, 0.f, ST_BULLET, 50.f));
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