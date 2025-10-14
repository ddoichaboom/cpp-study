#pragma once

#include "CLine.h"

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	enum LINEDIRECTION { LEFT, RIGHT, END };

public:
	void			Initialize();
	void			Render(HDC hDC);
	void			Release();

public:
	list<CLine*>	Get_LineList() { return m_LineList; };

	CLine*			Collision_Line(INFO* m_pInfo);

public:
	static CLineMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CLineMgr;
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

	static CLineMgr* m_pInstance;
	list<CLine*>	 m_LineList;

	LINEPOINT		m_tLinePoint[END];

};

