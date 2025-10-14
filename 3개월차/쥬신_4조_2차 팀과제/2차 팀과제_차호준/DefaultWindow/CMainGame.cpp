#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CMouse.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"
#include <ctime>
#include "CLineMgr.h"
#include "CKeyMgr.h"


CMainGame::CMainGame()
	: m_currTime(GetTickCount64()), m_prevTime(m_currTime), m_deltaTime(0)
{
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

	srand(unsigned(time(NULL)));


	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayer>::Create_Obj());


	CLineMgr::Get_Instance()->Initialize();
	

}

void CMainGame::Update()
{
	m_currTime = GetTickCount64();
	m_deltaTime = (double)(m_currTime - m_prevTime) / 1000.0;

	CObjMgr::Get_Instance()->Update(m_deltaTime);	

	m_prevTime = m_currTime;
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();	

	CKeyMgr::Get_Instance()->Update();

}

void CMainGame::Render()
{
	Rectangle(m_memDC, 0, 0, WINCX, WINCY);

	CLineMgr::Get_Instance()->Render(m_memDC);

	CObjMgr::Get_Instance()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, 800, 600, m_memDC, 0, 0, SRCCOPY);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	//CLineMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();	

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}
