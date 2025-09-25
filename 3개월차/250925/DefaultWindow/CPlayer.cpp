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
    m_fSpeed = 7.f;
}

int CPlayer::Update()
{
    __super::Update_Rect();

    Key_Input();

    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{

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
        {
            m_tInfo.fX -= m_fSpeed;
        }
    }

    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            m_tInfo.fX += m_fSpeed / sqrtf(2.f);
            m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            m_tInfo.fX += m_fSpeed / sqrtf(2.f);
            m_tInfo.fY += m_fSpeed / sqrtf(2.f);
        }
        else
        {
            m_tInfo.fX += m_fSpeed;
        }

    }

    else if (GetAsyncKeyState(VK_UP) & 0x8000)
        m_tInfo.fY -= m_fSpeed;


    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        m_tInfo.fY += m_fSpeed;

  
#pragma region WASD ÃÑ¾Ë ¹ß»ç
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

    //if (GetAsyncKeyState('M') & 0x0001)
    //{
    //    m_pMonster->push_back(CAbstractFactory<CMonster>::
    //        Create_Obj(350, 300, HR_MONSTER));
    //}
   
#pragma endregion

   if (GetAsyncKeyState(VK_SPACE) & 0x0001)
       m_pBullet->push_back(CAbstractFactory<CBullet>::
           Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_UP));
}

