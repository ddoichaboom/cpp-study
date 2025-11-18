#include "pch.h"
#include "CSceneMgr.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr() : m_pScene(nullptr), m_eCurrentID(SC_END), m_ePreID(SC_END)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change()
{
	if (m_ePreID != m_eCurrentID)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurrentID)
		{
		case SC_HS:
			m_pScene = new CHSScene;
			break;

		case SC_HJ:
			m_pScene = new CHJScene;
			break;

		case SC_CY:
			m_pScene = new CCYScene;
			break;

		case SC_SH:
			m_pScene = new CSHScene;
			break;
		}

		m_pScene->Initialize();

		m_ePreID = m_eCurrentID;
	}
}

void CSceneMgr::Update()
{
	Scene_Change();

	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}
