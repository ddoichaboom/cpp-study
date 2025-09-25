#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CCollisionMgr.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	
	m_ObjList[PLAYER].push_back(CAbstractFactory<CPlayer>::Create_Obj());

	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Monster(&m_ObjList[MONSTER]);

}

int CMainGame::Update()
{
	//m_ObjList[PLAYER].front()->Update();
	
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
}



void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	Rectangle(m_hDC, BOUNDARY_LEFT, BOUNDARY_TOP, BOUNDARY_RIGHT, BOUNDARY_BOTTOM);

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Render(m_hDC);
		}
	}
	
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}

}