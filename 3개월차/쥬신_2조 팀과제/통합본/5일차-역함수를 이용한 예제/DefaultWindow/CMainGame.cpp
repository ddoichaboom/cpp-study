#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CMouse.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"

CMainGame::CMainGame()
	: m_dwStartTime(GetTickCount()), m_iFPS(0), m_dwElapsed(0), m_iAmount(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	m_hBit = CreateCompatibleBitmap(m_hDC, 800, 600);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayer>::Create_Obj());


	// 플레이어 생성

	//m_ObjList[PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj());
	//dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);
	//dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Shield(&m_ObjList[SHIELD]);
	//
	//for (int i = 0; i < 2; ++i)
	//{
	//	m_ObjList[MONSTER].push_back(CAbstractFactory<CMonster>::Create_Obj(700.f, 200.f * (i + 1), DIR_END));
	//	m_ObjList[MONSTER].back()->Set_Target(m_ObjList[PLAYER].front());
	//}
	//
	//// 마우스
	//m_ObjList[MOUSE].push_back(CAbstractFactory<CMouse>::Create_Obj());

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();	

}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();	
}

void CMainGame::Render()
{

	Rectangle(m_memDC, 0, 0, WINCX, WINCY);

	Rectangle(m_memDC, BOUNDARY_LEFT, BOUNDARY_TOP, BOUNDARY_RIGHT, BOUNDARY_BOTTOM);

	Rectangle(m_memDC, 475, 100, 775, 300);

	++m_iFPS;



	if (m_dwStartTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwStartTime = GetTickCount();
	}


	CObjMgr::Get_Instance()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, 800, 600, m_memDC, 0, 0, SRCCOPY);

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Destroy_Instance();	

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}
