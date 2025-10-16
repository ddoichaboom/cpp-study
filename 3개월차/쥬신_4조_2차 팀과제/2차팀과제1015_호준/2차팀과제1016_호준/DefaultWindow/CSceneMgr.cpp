#include "pch.h"
#include "CSceneMgr.h"

#include "CStage1.h"
#include "CStage2.h"
#include "CStage3.h"
#include "CStage4.h"
#include "CScrollMgr.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr() : m_pScene(nullptr),
m_eCurrentID(SC_LOGO), m_ePreID(SC_END)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	m_eCurrentID = eScene;

	if (m_ePreID != m_eCurrentID)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurrentID)
		{
		case SC_LOGO:
			m_pScene = new CLogo;
			break;

		case SC_MENU:
			m_pScene = new CMenu;
			break;

		case SC_EDIT:
			break;

		case SC_STAGE:
			m_pScene = new CStage1;
		case SC_STAGE1:
			m_pScene = new CStage1;
			break;
		case SC_STAGE2:
			m_pScene = new CStage2;
			break;
		case SC_STAGE3:
			m_pScene = new CStage3;
			break;
		case SC_STAGE4:
			m_pScene = new CStage4;
			break;

		}

		m_pScene->Initialize();

		m_ePreID = m_eCurrentID;
	}

}

void CSceneMgr::Update()
{
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
