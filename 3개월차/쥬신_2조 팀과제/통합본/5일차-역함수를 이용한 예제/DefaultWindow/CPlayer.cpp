#include "pch.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"
#include "CShield.h"
#include "CScrewBullet.h"
#include "CObjMgr.h"

CPlayer::CPlayer() 
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

    m_fDistance = 100.f;
}

int CPlayer::Update()
{

   __super::Update_Rect();

   Key_Input();

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
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);

    // Æ÷½Å
    //MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
    //LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
    clock_t ckNow = clock();
    int iInput(0);
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
        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CBullet>::
            Create_Obj(m_tInfo.fX, m_tInfo.fY, 90));
    }

    if (GetAsyncKeyState('M') & 0x0001)
    {
        //m_pMonster->push_back(CAbstractFactory<CMonster>::
        //    Create_Obj((int)(BOUNDARY_RIGHT - BOUNDARY_LEFT) >> 1, (int)(BOUNDARY_TOP + 200), HR_MONSTER));
        CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CMonster>::
            Create_Obj((int)(BOUNDARY_RIGHT - BOUNDARY_LEFT) >> 1, (int)(BOUNDARY_TOP + 200)));
    }

    //if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    //{
    //    iInput = 1;
    //    if (ckNow - KeyTimeCheck[iInput] >= 100)
    //    {
    //        KeyTimeCheck[iInput] = ckNow;
    //       /* m_pBullet->push_back(CAbstractFactory<CBullet>::
    //            Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_UP, m_iAngle));*/
    //    }
    //}


 
    
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
       // m_pBullet->push_back(Create_Bullet<CScrewBullet>((float)m_tPosin.x, (float)m_tPosin.y, m_fAngle));
        //CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CScrewBullet>::Create_Obj((float)m_tPosin.x, (float)m_tPosin.y, m_fAngle));
    } 

    //if (GetAsyncKeyState('S') & 0x8000)
    //{
    //    m_pShield->push_back(Create_Shield());
    //}
}

//template<typename T>
//CObj* CPlayer::Create_Bullet(float fX, float fY, float fAngle)
//{
//    CObj* pBullet = new T;
//
//    pBullet->Initialize();
//
//    pBullet->Set_Pos(fX, fY);
//    pBullet->Set_Angle(fAngle);
//
//    return pBullet;
//}
//
//CObj* CPlayer::Create_Shield()
//{
//    CObj* pShield = new CShield;
//
//    pShield->Initialize();
//    pShield->Set_Target(this);
//
//    return pShield;
//}

