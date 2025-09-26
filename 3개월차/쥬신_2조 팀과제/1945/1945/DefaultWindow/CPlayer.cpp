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
    m_tInfo = { float(WINCX >> 1), float(WINCY - 125.f), 50.f, 50.f };
    m_fSpeed = 10.f;
}

int CPlayer::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
   __super::Update_Rect();

   Key_Input();

   return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
    if (!m_pShield->empty())
        m_pShield->front()->Set_Pos(m_tInfo.fX, m_tInfo.fY);
}

void CPlayer::Render(HDC hDC)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
    HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, hBrush);
    Rectangle(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
    SelectObject(hDC, OldBrush);
    DeleteObject(hBrush);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
    clock_t ckNow = clock();
    int iInput(0);
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        m_tInfo.fX += m_fSpeed;
        if (m_tRect.right >= WINCX - 100)
            m_tInfo.fX = WINCX - 100 - m_tInfo.fCX / 2;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        m_tInfo.fX -= m_fSpeed;
        if (m_tRect.left <= 100)
            m_tInfo.fX = 100 + m_tInfo.fCX / 2;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        m_tInfo.fY -= m_fSpeed;
        if (m_tRect.top <= 100)
            m_tInfo.fY = 100 + m_tInfo.fCY / 2;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        m_tInfo.fY += m_fSpeed;
        if (m_tRect.bottom >= WINCY - 100)
            m_tInfo.fY = WINCY - 100 - m_tInfo.fCY / 2;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        iInput = 1;
        if (ckNow - KeyTimeCheck[iInput] >= 100)
        {
            KeyTimeCheck[iInput] = ckNow;
            m_pBullet->push_back(CAbstractFactory<CBullet>::
                Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_UP, m_iAngle));
        }
    }
    if ((GetAsyncKeyState('Q') & 0x8000))
    {
        if (m_pShield->empty())
        {
            m_pShield->push_back(CAbstractFactory<CShield>::
                Create_Obj(m_tInfo.fX, m_tInfo.fY, DIR_END, m_iAngle));
        }
    }
}