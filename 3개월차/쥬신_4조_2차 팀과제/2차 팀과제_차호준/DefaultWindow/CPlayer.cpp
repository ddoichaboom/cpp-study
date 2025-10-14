#include "pch.h"
#include "CPlayer.h"
#include "CAbstractFactory.h"
#include "CShield.h"
#include "CScrewBullet.h"
#include "CObjMgr.h"
#include "CGuideBullet.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"


// 추가 
namespace {
    // 실행 중 1회만 BOM을 쓰기 위한 플래그
    static bool g_logInited = false;

    void LogLine(const wchar_t* fmt, ...)
    {
        HANDLE h = CreateFileW(L"../AAAAAAAAAAAAA.txt",
            FILE_APPEND_DATA | GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS,
            FILE_ATTRIBUTE_NORMAL, nullptr);
        if (h == INVALID_HANDLE_VALUE) return;

        // 새 파일이면 BOM 한 번
        if (!g_logInited) {
            LARGE_INTEGER sz{}; GetFileSizeEx(h, &sz);
            if (sz.QuadPart == 0) {
                DWORD w; const WCHAR bom = 0xFEFF;
                WriteFile(h, &bom, sizeof(bom), &w, nullptr);
            }
            g_logInited = true;
        }

        // 파일 끝으로
        SetFilePointerEx(h, { 0 }, nullptr, FILE_END);

        // 타임스탬프 (로컬)
        SYSTEMTIME st; GetLocalTime(&st);

        // 가변 포맷
        wchar_t body[1024];
        va_list ap; va_start(ap, fmt);
        _vsnwprintf_s(body, _TRUNCATE, fmt, ap);
        va_end(ap);

        // 최종 라인: [YYYY-MM-DD hh:mm:ss.mmm] + 본문 + \r\n
        wchar_t line[1400];
        _snwprintf_s(line, _TRUNCATE,
            L"[%04u-%02u-%02u %02u:%02u:%02u.%03u] %s\r\n",
            st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
            body);

        DWORD w; WriteFile(h, line, DWORD(wcslen(line) * sizeof(wchar_t)), &w, nullptr);
        CloseHandle(h);
    }
}

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
    m_fJumpSpeed = 500.f;
    m_fMaxMoveSpeed = 720.f;
    m_fAccelSpeed = m_fMaxMoveSpeed / 3.f;
}

int CPlayer::Update(double deltaTime)
{

    __super::Update_Rect();

    Key_Input(deltaTime);



    if (!m_bOnGround)
    {
        // deltaTime 은 double형
        // GC는 98.1f 로 선언된 매크로 상수
        m_fVy += GC * deltaTime;
    }

    m_tInfo.fY += m_fVy * deltaTime;

    m_tInfo.fX += m_fVx * deltaTime;



    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
    m_pTargetLine = nullptr;

    if (m_tInfo.fX <= BOUNDARY_LEFT + m_tInfo.fCX / 2)
        m_tInfo.fX = BOUNDARY_LEFT + m_tInfo.fCX / 2;

    if (m_tInfo.fY <= BOUNDARY_TOP + m_tInfo.fCY / 2)
        m_tInfo.fY = BOUNDARY_TOP + m_tInfo.fCY / 2;

    if (m_tInfo.fX >= BOUNDARY_RIGHT - m_tInfo.fCX / 2)
        m_tInfo.fX = BOUNDARY_RIGHT - m_tInfo.fCX / 2;

    if (m_tInfo.fY >= BOUNDARY_BOTTOM - m_tInfo.fCY / 2)
    {
        m_tInfo.fY = BOUNDARY_BOTTOM - m_tInfo.fCY / 2;
        m_fVy = 0;
        m_bOnGround = true;
    }

    if (m_fVy >= 0)
        m_pTargetLine = CLineMgr::Get_Instance()->Collision_Line(&m_tInfo);

    if (m_pTargetLine)
    {
        const auto& L = m_pTargetLine->Get_Info(); // tfTilt, tfYInter, tfRadian 등

        float fDistance =
            sqrtf(((L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter) *
                (L.tfTilt * m_tInfo.fX - m_tInfo.fY + L.tfYInter)) /
                (L.tfTilt * L.tfTilt + 1.f));

        // 보정 적용 (기존 코드)
        __super::Set_Pos(
            m_tInfo.fX + ((m_tInfo.fCY / 2.f) * cosf(PI / 2.f - L.tfRadian) - fDistance * cosf(PI / 2.f - L.tfRadian)),
            m_tInfo.fY - (m_tInfo.fCY / 2.f * sinf(PI / 2.f - L.tfRadian) - fDistance * sinf(PI / 2.f - L.tfRadian)));


        m_bOnGround = true;
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
    else if (!(GetAsyncKeyState(VK_LEFT) & 0x8000))
    {
        if (m_fVx < 0)
        {
            //m_fVx += m_fAccelSpeed * deltaTime;
            m_fVx = 0;
        }
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        if (m_fVx < m_fMaxMoveSpeed)
        {
            m_fVx += m_fAccelSpeed * deltaTime;
        }
    }
    else if (!(GetAsyncKeyState(VK_RIGHT) & 0x8000))
    {
        if (m_fVx > 0)
        {
            //m_fVx -= m_fAccelSpeed * deltaTime;
            m_fVx = 0;
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

