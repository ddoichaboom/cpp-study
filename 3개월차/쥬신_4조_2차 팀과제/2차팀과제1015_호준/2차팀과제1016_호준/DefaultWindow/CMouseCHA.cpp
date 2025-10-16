#include "pch.h"
#include "CMouseCHA.h"
#include "CBmpMgr.h"
#include "CScrollMgrCHA.h"

CMouseCHA::CMouseCHA()
{
}

CMouseCHA::~CMouseCHA()
{
    Release();
}

void CMouseCHA::Initialize()
{
    m_tInfo.fCX = 32.f;
    m_tInfo.fCY = 32.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Mouse/Aim.bmp", L"Cursor");

  }

int CMouseCHA::Update(float deltaTime)
{
    POINT       ptMouse{};

    GetCursorPos(&ptMouse);
    ScreenToClient(g_hWnd, &ptMouse);

    m_tInfo.fX = (float)ptMouse.x;
    m_tInfo.fY = (float)ptMouse.y;

    __super::Update_Rect();

    ShowCursor(false);

    return OBJ_NOEVENT;
}

void CMouseCHA::Late_Update(float deltaTime)
{
}

void CMouseCHA::Render(HDC hDC)
{

    HDC     hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Cursor");

    GdiTransparentBlt(hDC,
        m_tRect.left,
        m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        0,
        0,
        (int)m_tInfo.fCX,   // 복사할 이미지 가로
        (int)m_tInfo.fCY,   // 복사할 이미지 세로
        RGB(255, 0, 255));    // 제거할 픽셀 색상 값
}

void CMouseCHA::Release()
{
}
