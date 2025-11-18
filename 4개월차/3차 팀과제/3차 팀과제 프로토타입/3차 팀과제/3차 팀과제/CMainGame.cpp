#include "pch.h"
#include "CMainGame.h"
#include "CSceneMgr.h"
#include <ctime>
#include "CKeyMgr.h"

CMainGame::CMainGame() : m_dwTime(GetTickCount()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	srand(unsigned(time(NULL)));
	m_hDC = GetDC(g_hWnd);

	m_hBit = CreateCompatibleBitmap(m_hDC, 800, 600);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	CSceneMgr::Get_Instance()->Set_SceneChange(CSceneMgr::SC_HJ);
}

void CMainGame::Update()
{
	Key_Input();
	CKeyMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

	Rectangle(m_memDC, 0, 0, WINCX, WINCY);

	CSceneMgr::Get_Instance()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, 800, 600, m_memDC, 0, 0, SRCCOPY);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

	CSceneMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
}

void CMainGame::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_F1))
	{
		CSceneMgr::Get_Instance()->Set_SceneChange(CSceneMgr::SC_HS);
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_F2))
	{
		CSceneMgr::Get_Instance()->Set_SceneChange(CSceneMgr::SC_HJ);
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_F3))
	{
		CSceneMgr::Get_Instance()->Set_SceneChange(CSceneMgr::SC_CY);
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_F4))
	{
		CSceneMgr::Get_Instance()->Set_SceneChange(CSceneMgr::SC_SH);
	}
}
