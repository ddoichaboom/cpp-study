#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame() : m_hDC(NULL)
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

	m_ObjList[PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj());
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Shield(&m_ObjList[SHIELD]);

	for (int i = 0; i < 3; ++i)
		m_ObjList[MONSTER].push_back(CAbstractFactory<CMonster>::Create_Obj(140.f * (i + 1), 120.f * (i + 1), DIR_CIRCLE, 0));

	for (auto& pObj : m_ObjList[MONSTER])
	{
		if (auto pMonster = dynamic_cast<CMonster*>(pObj))
			pMonster->Set_Bullet(&m_ObjList[MONSTER_BULLET]);
	}
}

void CMainGame::Update()
{
	if (m_ObjList[PLAYER].empty())
	{
		if (GetAsyncKeyState('R') & 0x8000)
		{
			m_ObjList[PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj());
			dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);
			dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Shield(&m_ObjList[SHIELD]);
		}
	}

	for (UINT i = 0; i < OBJ_END; i++)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();

			if (iResult == OBJ_DEAD)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CMainGame::Late_Update()
{
	for (UINT i = 0; i < OBJ_END; i++)
		for (auto& pObj : m_ObjList[i])
			pObj->Late_Update();

	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[MONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[MONSTER_BULLET], m_ObjList[PLAYER]);
	CCollisionMgr::Collision_Circle(m_ObjList[MONSTER_BULLET], m_ObjList[SHIELD]);
	CCollisionMgr::Collision_Circle(m_ObjList[MONSTER], m_ObjList[PLAYER]);
}

void CMainGame::Render()
{
	clock_t ckNow = clock();
	Rectangle(m_memDC, 0, 0, WINCX, WINCY);
	Rectangle(m_memDC, 100, 100, WINCX - 100, WINCY - 100);


	for (UINT i = 0; i < OBJ_END; i++)
		for (auto& pObj : m_ObjList[i])
			pObj->Render(m_memDC);
	if (m_ObjList[PLAYER].empty())
	{
		if (ckNow - TimeCheck >= 2000)
		{
			TimeCheck = ckNow;
		}
		else if (ckNow - TimeCheck <= 1500)
		{
			TCHAR szBuff[32] = L"";
			swprintf_s(szBuff, L"GAME OVER");
			TextOut(m_memDC, WINCX / 2 - 50, WINCY / 2, szBuff, lstrlen(szBuff));
			TCHAR szBuff2[32] = L"";
			swprintf_s(szBuff, L"PRESS THE 'R' KEY");
			TextOut(m_memDC, WINCX / 2 - 80, WINCY / 2 + 40, szBuff, lstrlen(szBuff));
		}
	}
	BitBlt(m_hDC, 0, 0, 800, 600, m_memDC, 0, 0, SRCCOPY);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

	for (UINT i = 0; i < OBJ_END; i++)
	{
		for_each (m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}
