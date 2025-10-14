#pragma once

#include "CObj.h"
#include "CLine.h"
#include "CLineMgr.h"

class CObjMgr
{
private:
	CObjMgr();
	CObjMgr(const CObjMgr& rhs) = delete;		// 삭제
	CObjMgr& operator=(CObjMgr& rObj) = delete;	// 삭제
	~CObjMgr();

public:
	CObj* Get_Target(OBJID eID, CObj* pObj);		

public:
	void	Add_Object(OBJID eID, CObj* pObj);
	void	Update(double deltaTime);
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

private:
	list<CObj*>		m_ObjList[OBJ_END];

public:
	static CObjMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgr;
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
	static CObjMgr* m_pInstance;
};

