#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CMouse.h"
#include "CCollisionMgr.h"

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

	/*if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}*/

	//m_pPlayer = CAbstractFactory<CPlayer>::Create_Obj();
	//dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);

	// 플레이어 생성

	m_ObjList[PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj());
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);


	for (int i = 0; i < 3; ++i)
	{
		m_ObjList[MONSTER].push_back(CAbstractFactory<CMonster>::Create_Obj(140.f * (i + 1), 120.f * (i + 1), DIR_END));
	}

	// 마우스
	m_ObjList[MOUSE].push_back(CAbstractFactory<CMouse>::Create_Obj());

}

void CMainGame::Update()
{

#pragma region 복습
	//m_pPlayer->Update();
	//
	//for (auto iter = m_BulletList.begin();
	//	iter != m_BulletList.end(); )
	//{
	//	int iResult = (*iter)->Update();
	//
	//	if (iResult == OBJ_DEAD)
	//	{
	//		Safe_Delete<CObj*>(*iter);
	//		iter = m_BulletList.erase(iter);
	//	}
	//	else
	//	{
	//		++iter;
	//	}
	//}
#pragma endregion

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (iResult == OBJ_DEAD)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	
}

void CMainGame::Late_Update()
{
	//m_pPlayer->Late_Update();
	//
	//for (auto& pBullet : m_BulletList)
	//	pBullet->Late_Update();

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Late_Update();
		}
	}
	CCollisionMgr::Collision_Circle(m_ObjList[MOUSE], m_ObjList[MONSTER]);
	//CCollisionMgr::Collision_Rect(m_ObjList[BULLET], m_ObjList[MONSTER]);
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

	//Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Render(m_hDC);
		}
	}

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

	//Safe_Delete<CObj*>(m_pPlayer);
	//
	//for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	//m_BulletList.clear();

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
	
}
