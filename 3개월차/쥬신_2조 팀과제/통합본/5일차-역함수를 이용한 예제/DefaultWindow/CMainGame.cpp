#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CMouse.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"

CMainGame::CMainGame()// : m_pPlayer(nullptr)
	: m_dwTime(GetTickCount()), m_iFPS(0)
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
	// FPS 출력

	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	CObjMgr::Get_Instance()->Render(m_hDC);
	
	// 문자열 출력 함수

	//TCHAR	szBuff[32] = L"Hello";
	//TextOut(m_hDC, 100, 100, szBuff, lstrlen(szBuff));
	
	//RECT	rc{ 300, 300, 400, 400 };
	//DrawText(m_hDC, szBuff, lstrlen(szBuff), &rc, DT_CENTER);
	
	//TCHAR	szBuff[32] = L"";
	//wsprintf(szBuff, L"Bullet : %d", m_ObjList[BULLET].size());

	// 모든 서식 지원
	//swprintf_s(szBuff, L"Bullet : %f", 3.14f);
	//TextOut(m_hDC, 50, 50, szBuff, lstrlen(szBuff));

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Destroy_Instance();	
}
