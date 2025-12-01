#include "pch.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"
#include "CShield.h"
#include "CScrewBullet.h"
#include "CObjMgr.h"
#include "CGuideBullet.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"

CPlayer::CPlayer()
    : m_pTargetLine(nullptr)
{
    ZeroMemory(KeyTimeCheck, sizeof(KeyTimeCheck));
    //ZeroMemory(&m_tPosin, sizeof(POINT));
}

CPlayer::~CPlayer()
{
    Release();
}

void CPlayer::Initialize()
{
    m_tInfo = { 50.f, 550.f, 50.f, 50.f };
    m_fSpeed = 10.f;
    m_fJumpSpeed = 600.f;
    m_fMaxMoveSpeed = 800.f;
    m_fAccelSpeed = m_fMaxMoveSpeed / 2.f;
}

int CPlayer::Update(double deltaTime)
{
    __super::Update_Rect();

    Key_Input(deltaTime);

    if (!m_bOnGround)
    {
        m_fVy += GC * deltaTime;

        if (m_fVy > 0)
            m_fVy -= AoF * deltaTime;
        else if (m_fVy < 0)
            m_fVy += AoF * deltaTime;

        if (m_fVx > 0)
            m_fVx -= AoF * deltaTime;
        else if (m_fVx < 0)
            m_fVx += AoF * deltaTime;
    }
    else if (m_bOnGround && (m_fVx != 0))
    {
        if (m_fVx < 0)
            m_fVx += CoF * deltaTime;
        else if (m_fVx > 0)
            m_fVx -= CoF * deltaTime;
    }

    m_tInfo.fY += m_fVy * deltaTime;

    m_tInfo.fX += m_fVx * deltaTime;

    return OBJ_NOEVENT;
}

void CPlayer::Late_Update(double deltaTime)
{
    m_pTargetLine = nullptr;

    if (m_tInfo.fX <= BOUNDARY_LEFT + m_tInfo.fCX / 2)
    {
        m_tInfo.fX = BOUNDARY_LEFT + m_tInfo.fCX / 2;
        m_fVx = 0;
    }

    if (m_tInfo.fY <= BOUNDARY_TOP + m_tInfo.fCY / 2)
        m_tInfo.fY = BOUNDARY_TOP + m_tInfo.fCY / 2;

    if (m_tInfo.fX >= BOUNDARY_RIGHT - m_tInfo.fCX / 2)
    {
        m_tInfo.fX = BOUNDARY_RIGHT - m_tInfo.fCX / 2;
        m_fVx = 0;
    }

    if (m_tInfo.fY >= BOUNDARY_BOTTOM - m_tInfo.fCY / 2)
    {
        m_tInfo.fY = BOUNDARY_BOTTOM - m_tInfo.fCY / 2;
        m_fVy = 0;
        m_bOnGround = true;
    }

    if (m_fVy >= 0)
    {
        m_pTargetLine = CLineMgr::Get_Instance()->Collision_Line(&m_tInfo);

        const auto& L = m_pTargetLine->Get_Info(); // tfTilt, tfYInter, tfRadian 등

        if (m_pTargetLine)
        {

            if (L.tfTilt == 0)
            {
                m_bOnGround = true;
                m_fVy = 0;
            }
            else if (L.tfTilt != 0)
            {
                m_bOnGround = true;
                m_fVy += GC * deltaTime;

                if (m_fVy > 0)
                {
                    m_fVy -= AoF * deltaTime;
                    m_fVy -= CoF * deltaTime;
                }

                if (m_fVx > 0)
                {
                    m_fVx -= AoF * deltaTime;
                    m_fVx -= CoF * deltaTime;
                }
                else if (m_fVx < 0)
                {
                    m_fVx += AoF * deltaTime;
                    m_fVx += CoF * deltaTime;
                }
            }

            // tfTilt, tfYInter, tfRadian 등
            float fDistance =
                sqrtf(((L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter) *
                    (L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter)) /
                    (L.tfTilt * L.tfTilt + 1.f));

            // 보정 적용 (기존 코드)
            __super::Set_Pos(
                m_tInfo.fX + ((m_tInfo.fCY / 2.f) * cosf(PI / 2.f - L.tfRadian) - fDistance * cosf(PI / 2.f - L.tfRadian)),
                m_tInfo.fY - (m_tInfo.fCY / 2.f * sinf(PI / 2.f - L.tfRadian) - fDistance * sinf(PI / 2.f - L.tfRadian)));

        }

     }

}


void CPlayer::Render(HDC hDC)
{

    Ellipse(hDC,
        m_tRect.left,
        m_tRect.top,
        m_tRect.right,
        m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input(double deltaTime)
{

#pragma region 기존 총알 발사 및 이동 로직
    //clock_t ckNow = clock();
    //int iInput(0);

    //if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    //{
    //    if (GetAsyncKeyState(VK_UP) & 0x8000)
    //    {
    //        m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
    //        m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
    //    }
    //    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    //    {
    //        m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
    //        m_tInfo.fY += m_fSpeed / sqrtf(2.f);
    //    }
    //    else
    //    {
    //        m_tInfo.fX -= m_fSpeed;
    //    }
    //}
    //else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    //{
    //    if (GetAsyncKeyState(VK_UP) & 0x8000)
    //    {
    //        m_tInfo.fX += m_fSpeed / sqrtf(2.f);
    //        m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
    //    }
    //    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    //    {
    //        m_tInfo.fX += m_fSpeed / sqrtf(2.f);
    //        m_tInfo.fY += m_fSpeed / sqrtf(2.f);
    //    }
    //    else
    //    {
    //        m_tInfo.fX += m_fSpeed;
    //    }
    //}
    //else if (GetAsyncKeyState(VK_UP) & 0x8000)
    //{
    //    m_tInfo.fY -= m_fSpeed;
    //}
    //else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    //{
    //    m_tInfo.fY += m_fSpeed;
    //}  
    //
    //if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    //{
    //    iInput = 1;
    //    if (ckNow - KeyTimeCheck[iInput] >= 100)
    //    {
    //        KeyTimeCheck[iInput] = ckNow;
    //        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CGuideBullet>::Create_Obj(m_tInfo.fX, m_tInfo.fY, 90));
    //    }


    //} 

#pragma endregion


    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        if (m_fVx > -m_fMaxMoveSpeed)
        {
            m_fVx -= m_fAccelSpeed * deltaTime;
        }
    }
    

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        if (m_fVx < m_fMaxMoveSpeed)
        {
            m_fVx += m_fAccelSpeed * deltaTime;
        }
    }
    

    if (GetAsyncKeyState(VK_RETURN) & 0x8000)
    {
        m_fVx = 0;
    }

    // 하단 내려가는 버튼 구현 
    //if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    //{
    //    m_bOnGround = false;
    //}
    
   

    if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (m_bOnGround)
        {
            m_fVy = -m_fJumpSpeed;
            m_bOnGround = false;
        }
        
    }





}

