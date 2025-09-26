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
    m_tInfo = { float(100.f), float(WINCY >> 1), 100.f, 100.f };
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

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        m_fAngle += 5.f;

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        m_fAngle -= 5.f;

    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
        m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        m_tInfo.fX += -m_fSpeed * cosf(m_fAngle * (PI / 180.f));
        m_tInfo.fY -= -m_fSpeed * sinf(m_fAngle * (PI / 180.f));
    }  
    
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

