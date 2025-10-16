#include "pch.h"
#include "CPlayerCHA.h"
#include "CAbstractFactory.h"
#include "CShield.h"
#include "CScrewBullet.h"
#include "CObjMgr.h"
#include "CGuideBullet.h"
#include "CKeyMgr.h"
#include "CBmpMgr.h"
#include "CScrollMgrCHA.h"
#include "CLineMgrCHA.h"

CPlayerCHA::CPlayerCHA()
    : m_pTargetLine(nullptr), m_pVerticalLine(nullptr), m_ePlayerDir(PD_RIGHT)

{
    ZeroMemory(&m_tPosin, sizeof(POINT));
    ZeroMemory(&m_tCursor, sizeof(POINT));

}

CPlayerCHA::~CPlayerCHA()
{
    Release();
}

void CPlayerCHA::Initialize()
{
    m_tInfo = { 960.f, 955.f, 100.f, 100.f };
    m_fSpeed = 10.f;
    m_fJumpSpeed = 650.f;
    m_fMaxMoveSpeed = 900.f;
    m_fAccelSpeed = m_fMaxMoveSpeed / 3.f;
    m_fDistance = 10.f;
    m_ePlayerDir = PD_RIGHT;
    m_bOnGround = true;


    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/PlayerCHA/Player_LEFT.bmp", L"Player_LEFT");   
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/PlayerCHA/Player_RIGHT.bmp", L"Player_RIGHT");



}

int CPlayerCHA::Update(float deltaTime)
{
    __super::Update_Rect();

    Key_Input(deltaTime);

    if (!m_bOnGround)
    {
        m_fVy += GC * deltaTime;

        if (m_fVy > 0)
            m_fVy -= AoF_Y * deltaTime;
        else if (m_fVy < 0)
            m_fVy += AoF_Y * deltaTime;

        if (m_fVx > 0)
            m_fVx -= AoF_X * deltaTime;
        else if (m_fVx < 0)
            m_fVx += AoF_X * deltaTime;
    }
    else if (m_bOnGround)
    {
        if (m_fVx < 0)
            m_fVx += - m_fVx / CoF * deltaTime;
        else if (m_fVx > 0)
            m_fVx += -m_fVx / CoF * deltaTime;
    }

    m_tInfo.fY += m_fVy * deltaTime;

    m_tInfo.fX += m_fVx * deltaTime;


    return OBJ_NOEVENT;
}

void CPlayerCHA::Late_Update(float deltaTime)
{
    Circle_Col_Movement();

    Collision_Vertical_Line();

    Collision_Border_Line();

    m_pTarget = CObjMgr::Get_Instance()->Get_Target(MOUSE, this);

    if (m_pTarget)
    {
        float fDx = m_tInfo.fX - m_pTarget->Get_Info()->fX;
        float fDy = m_tInfo.fY - m_pTarget->Get_Info()->fY;

        int 		iScrollX = (int)CScrollMgrCHA::Get_Instance()->Get_ScrollX();
        int 		iScrollY = (int)CScrollMgrCHA::Get_Instance()->Get_ScrollY();

        float fDeg = atan2(fDy + iScrollY, fDx + iScrollX) * 180.f / PI;

        if (fabsf(fDeg) > 95.f )
        {
            m_ePlayerDir = PD_RIGHT;
        }
        else if (fabsf(fDeg) < 85.f)
        {
            m_ePlayerDir = PD_LEFT;
        }

    }

    Offset(deltaTime);

    __super::Update_Rect();

}


void CPlayerCHA::Render(HDC hDC)
{
    int 		iScrollX = (int)CScrollMgrCHA::Get_Instance()->Get_ScrollX();
    int 		iScrollY = (int)CScrollMgrCHA::Get_Instance()->Get_ScrollY();

    HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_ePlayerDir==PD_LEFT ? L"Player_LEFT": L"Player_RIGHT");


    GdiTransparentBlt(hDC,
        m_tRect.left + iScrollX,
        m_tRect.top + iScrollY,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        0,
        100.f,
        (int)m_tInfo.fCX,   // 복사할 이미지 가로
        (int)m_tInfo.fCY,   // 복사할 이미지 세로
        RGB(0, 94, 86));    // 제거할 픽셀 색상 값


}

void CPlayerCHA::Release()
{
}

void CPlayerCHA::Key_Input(float deltaTime)
{

    if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
    {
        if (m_fVx > -m_fMaxMoveSpeed)
            m_fVx -= m_fAccelSpeed * deltaTime;

    }

    if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
    {
        if (m_fVx < m_fMaxMoveSpeed)
            m_fVx += m_fAccelSpeed * deltaTime;
        
    }

    if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
    {
        m_bOnGround = false;
    }

    if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (m_bOnGround)
        {
            m_fVy = -m_fJumpSpeed;
            m_bOnGround = false;
        }

    }

}

void CPlayerCHA::Offset(float deltaTime)
{

    int     iOffSetMinX = 100;
    int     iOffSetMaxX = 700;

    int     iOffSetMinY = 100;
    int     iOffSetMaxY = 500;

    int	  iScrollX = (int)CScrollMgrCHA::Get_Instance()->Get_ScrollX();
    int	  iScrollY = (int)CScrollMgrCHA::Get_Instance()->Get_ScrollY();

    if (iOffSetMinX > m_tInfo.fX + iScrollX)
    {
        CScrollMgrCHA::Get_Instance()->Set_ScrollX(m_fAccelSpeed * deltaTime);
    }

    if (iOffSetMaxX < m_tInfo.fX + iScrollX)
    {
        CScrollMgrCHA:: Get_Instance()->Set_ScrollX(- m_fAccelSpeed * deltaTime);
    }

    if (iOffSetMinY > m_tInfo.fY + iScrollY)
    {
        CScrollMgrCHA::Get_Instance()->Set_ScrollY((m_fJumpSpeed) * deltaTime);
    }

    if (iOffSetMaxY < m_tInfo.fY + iScrollY)
    {
        CScrollMgrCHA::Get_Instance()->Set_ScrollY(-(m_fJumpSpeed)*deltaTime);
    }

    CScrollMgrCHA::Get_Instance()->Scroll_Lock();
}

void	CPlayerCHA::Collision_Border_Line()
{
    if (m_tInfo.fX <= BOUNDARY_LEFT + m_tInfo.fCX / 2)
    {
        m_tInfo.fX = BOUNDARY_LEFT + m_tInfo.fCX / 2;
        m_fVx = 0;
    }

    if (m_tInfo.fY <= BOUNDARY_TOP + m_tInfo.fCY / 2)
    {
        m_tInfo.fY = BOUNDARY_TOP + m_tInfo.fCY / 2;
        m_fVy = 0;
    }

    if (m_tInfo.fX >= BOUNDARY_RIGHT - m_tInfo.fCX / 2)
    {
        m_tInfo.fX = BOUNDARY_RIGHT - m_tInfo.fCX / 2;
        m_fVx = 0;
    }

    if (m_tInfo.fY >= BOUNDARY_BOTTOM - m_tInfo.fCY / 2)
    {
        m_tInfo.fY = BOUNDARY_BOTTOM - m_tInfo.fCY / 2;
        m_bOnGround = true;
        m_fVy = 0;
    }
}

void CPlayerCHA::Rect_Col_Movement()
{
    if (m_fVy >= 0)
{
    m_pTargetLine = CLineMgrCHA::Get_Instance()->Line_Movement_Rect(&m_tInfo);

    // tfTilt, tfYInter, tfRadian 등
    if (m_pTargetLine)
    {
        const auto& L = m_pTargetLine->Get_Info(); // tfTilt, tfYInter, tfRadian 등

        // tfTilt, tfYInter, tfRadian 등
        float fDistance =
            sqrtf(((L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter) *
                (L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter)) /
                (L.tfTilt * L.tfTilt + 1.f));

        m_bOnGround = true;

        if (L.tfTilt == 0)
        {
            m_fVy = 0;
        }

        if (fabsf(L.tfTilt) == 1)
        {
            m_tInfo.fX = m_tInfo.fX + (INV_SQRT2 * m_tInfo.fCX * cosf(L.tfRadian) - fDistance * cosf(L.tfRadian));
            m_tInfo.fY = m_tInfo.fY - (INV_SQRT2 * m_tInfo.fCX * sinf(L.tfRadian) - fDistance * sinf(L.tfRadian));
        }
        else
        {
            m_tInfo.fX = m_tInfo.fX + ((INV_SQRT2 * m_tInfo.fCX * INV_SQRT2) - 
                (fDistance / sinf((PI / 4.0f + L.tfRadian)) * INV_SQRT2));
            m_tInfo.fY = m_tInfo.fY - ((INV_SQRT2 * m_tInfo.fCY * INV_SQRT2) -
                (fDistance / sinf((PI / 4.0f + L.tfRadian)) * INV_SQRT2));
        }
    }
    else
        m_bOnGround = false;

    m_pTargetLine = nullptr;

}
}

void CPlayerCHA::Circle_Col_Movement()
{
    if (m_fVy >= 0)
    {
        m_pTargetLine = CLineMgrCHA::Get_Instance()->Line_Movement_Circle(&m_tInfo);

        // tfTilt, tfYInter, tfRadian 등
        if (m_pTargetLine)
        {
            const auto& L = m_pTargetLine->Get_Info(); // tfTilt, tfYInter, tfRadian 등

            m_bOnGround = true;

            if (L.tfTilt == 0)
            {
                m_fVy = 0;
            }


            // tfTilt, tfYInter, tfRadian 등
            float fDistance =
                sqrtf(((L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter) *
                    (L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter)) /
                    (L.tfTilt * L.tfTilt + 1.f));

            m_tInfo.fX = m_tInfo.fX + ((m_tInfo.fCY / 2.f) * cosf(PI / 2.f - L.tfRadian) - fDistance * cosf(PI / 2.f - L.tfRadian));
            m_tInfo.fY = m_tInfo.fY - (m_tInfo.fCY / 2.f * sinf(PI / 2.f - L.tfRadian) - fDistance * sinf(PI / 2.f - L.tfRadian));

        }
        else
            m_bOnGround = false;
        m_pTargetLine = nullptr;
    }

    return;
}

void	CPlayerCHA::Collision_Vertical_Line()
{
    //  플레이어 - 수직선 충돌 처리 및 보정 
    m_pVerticalLine = CLineMgrCHA::Get_Instance()->Collision_Vertical_Line(&m_tInfo);

    if (m_pVerticalLine)
    {
        const auto& Vl = m_pVerticalLine->Get_Info();

        float Distance = m_tInfo.fX - Vl.tLeft.fX;

        if (Distance < 0)
        {
            Distance = -Distance;

            if (Distance < m_tInfo.fCX / 2.f)
            {
                m_fVx = 0;
                m_tInfo.fX += -(m_tInfo.fCX / 2.f - Distance);
            }
            else
                m_pVerticalLine = nullptr;

        }
        else if (Distance > 0)
        {
            if (Distance < m_tInfo.fCX / 2.f)
            {
                m_fVx = 0;
                m_tInfo.fX += (m_tInfo.fCX / 2.f - Distance);
            }
            else
                m_pVerticalLine = nullptr;
        }

    }
}