#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer() : m_pBullet(nullptr)
{

}

CPlayer::~CPlayer()
{
    Release();
}

void CPlayer::Initialize()
{
    m_tInfo = { float(WINCX >> 1), float(WINCY >> 1), 100.f, 100.f };
    m_fSpeed = 10.f;
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
    if (GetAsyncKeyState(VK_UP) & 0x8000)
        m_tInfo.fY -= m_fSpeed;

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        m_tInfo.fX -= m_fSpeed;

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        m_tInfo.fX += m_fSpeed;

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        m_tInfo.fY += m_fSpeed;

    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        m_pBullet->push_back(Create_Bullet());
    }

    // if (GetAsyncKeyState('W'))
}

CObj* CPlayer::Create_Bullet(DIRECTION eDir)
{
    CObj*   pBullet = new CBullet;

    pBullet->Initialize();
    pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
    pBullet->Set_Direction(eDir);

    return pBullet;
}
