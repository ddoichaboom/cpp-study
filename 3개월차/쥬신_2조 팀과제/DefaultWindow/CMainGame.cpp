#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CCollisionMgr.h"


CMainGame::CMainGame()
	: m_dwStartTime(GetTickCount()), m_iFPS(0), m_dwElapsed(0), m_iAmount(0), m_pUI(nullptr)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
	ZeroMemory(m_szFPS, sizeof(m_szBuff));

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
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Monster(&m_ObjList[MONSTER]);
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Monster(&m_ObjList[MONSTER_BULLET]);

}

int CMainGame::Update()
{
	
	for (UINT i = 0; i < OBJ_END; ++i)
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
			{
				++iter;
			}
		}

	}
	return 0;
}

void	CMainGame::Late_Update()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Late_Update();
		}
	}
	CCollisionMgr::Collision_Rect(m_ObjList[BULLET], m_ObjList[MONSTER]);
	//CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[MONSTER_BULLET]);
}



void CMainGame::Render()
{
	RECT rcTime		= { 477, 102, 773, 298 };
	RECT rcAmount	= { 477, 102, 773, 298 };

	Rectangle(m_memDC, 0, 0, WINCX, WINCY);

	Rectangle(m_memDC, BOUNDARY_LEFT, BOUNDARY_TOP, BOUNDARY_RIGHT, BOUNDARY_BOTTOM);

	Rectangle(m_memDC, 475, 100, 775, 300);

	++m_iFPS;

	m_dwElapsed = (GetTickCount() - m_dwStartTime) / 1000; 
	m_iAmount = m_ObjList[MONSTER].size();

	int minutes = m_dwElapsed / 60;
	int seconds = m_dwElapsed % 60;
	TCHAR szTime[16];

	wsprintf(szTime, TEXT("%02d:%02d"), minutes, seconds);
	wsprintf(m_szBuff, L"몬스터 수 : %d", m_iAmount);

	SetTextColor(m_memDC, RGB(0, 0, 0));      
	SetBkMode(m_memDC, TRANSPARENT);                 

	DrawText(m_memDC, szTime, -1, &rcTime, DT_RIGHT);
	DrawText(m_memDC, m_szBuff, -1, &rcAmount, DT_LEFT);


	RECT rc{ 475, 90, 500, 300 };

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Render(m_memDC);
		}
	}

	BitBlt(m_hDC, 0, 0, 800, 600, m_memDC, 0, 0, SRCCOPY);
	
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}