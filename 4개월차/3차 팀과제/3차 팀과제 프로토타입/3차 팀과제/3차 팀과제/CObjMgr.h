#pragma once
#include "CObj.h"

class CObjMgr
{
private:
	CObjMgr();
	CObjMgr(const CObjMgr& rhs) = delete;
	CObjMgr& operator=(CObjMgr& rObj) = delete;
	~CObjMgr();

public:
	CObj* Get_Player() 
	{ 
		if (!m_ObjList[PLAYER].empty()) 
			return m_ObjList[PLAYER].front(); 

		return nullptr;								// 호준 추가 ( 플레이어 사망 시 반환하는 것이 없음 ) 
	}
	const list<CObj*>& Get_List(OBJ_ID eID) { return m_ObjList[eID]; }


public:
	void Add_Object(OBJ_ID eID, CObj* pObj);
	void Update();
	void Late_Update();
	void Render(HDC hDC);
	void Release();

private:
	list<CObj*> m_ObjList[OBJ_END];

public:
	static CObjMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgr;
		}
		return m_pInstance;
	}

	static void Destroy_Instance()
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

