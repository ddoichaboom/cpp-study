#pragma once
#include "Define.h"
#include "CHSScene.h"
#include "CHJScene.h"
#include "CCYScene.h"
#include "CSHScene.h"

class CSceneMgr
{
public:
	enum SCENE_ID { SC_HS, SC_HJ, SC_CY, SC_SH, SC_END };

private:
	CSceneMgr();
	~CSceneMgr();

public:
	void	 Set_SceneChange(SCENE_ID eScene) { m_eCurrentID = eScene; }

public:
	void	Scene_Change();
	void	Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

public:
	static CSceneMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CSceneMgr;
		}

		return m_pInstance;
	}

	static void	Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CSceneMgr* m_pInstance;

	CScene* m_pScene;

	SCENE_ID m_eCurrentID;
	SCENE_ID m_ePreID;
};

