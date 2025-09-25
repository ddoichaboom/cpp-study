#include "pch.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"

CPlayer::CPlayer() : m_pBullet(nullptr)
{
    ZeroMemory(&m_tPosin, sizeof(POINT));
}

CPlayer::~CPlayer()
{
    Release();
}

void CPlayer::Initialize()
{
    m_tInfo = { float(WINCX >> 1), float(WINCY >> 1), 100.f, 100.f };
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
    m_tPosin.x = long(m_tInfo.fX + m_fDistance * cosf(m_fAngle * (PI / 180.f)));
    m_tPosin.y = long(m_tInfo.fY - m_fDistance * sinf(m_fAngle * (PI / 180.f)));
}

void CPlayer::Render(HDC hDC)
{
    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);

    // 포신
    MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
    LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
    // GetKeyState();

#pragma region 복습
   // if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
   // {
   //     if (GetAsyncKeyState(VK_UP) & 0x8000)
   //     {
   //         m_tInfo.fX += m_fSpeed / sqrtf(2.f);
   //         m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
   //     }
   //
   //     else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
   //     {
   //         m_tInfo.fX += m_fSpeed / sqrtf(2.f);
   //         m_tInfo.fY += m_fSpeed / sqrtf(2.f);
   //     }
   //     else
   //         m_tInfo.fX += m_fSpeed;
   // }
   //
   // else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
   // {
   //     if (GetAsyncKeyState(VK_UP) & 0x8000)
   //     {
   //         m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
   //         m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
   //     }
   //
   //     else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
   //     {
   //         m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
   //         m_tInfo.fY += m_fSpeed / sqrtf(2.f);
   //     }
   //     else
   //         m_tInfo.fX -= m_fSpeed;
   // }
   //
   // else if (GetAsyncKeyState(VK_UP) & 0x8000)
   //     m_tInfo.fY -= m_fSpeed;
   //
   // else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
   //     m_tInfo.fY += m_fSpeed;
#pragma endregion

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
        m_pBullet->push_back(Create_Bullet((float)m_tPosin.x, (float)m_tPosin.y, m_fAngle));
    } 
}

CObj* CPlayer::Create_Bullet(float fX, float fY, float fAngle)
{
    CObj* pBullet = new CBullet;

    pBullet->Initialize();

    pBullet->Set_Pos(fX, fY);
    pBullet->Set_Angle(fAngle);

    return pBullet;
}

