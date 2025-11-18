#pragma once
#include "ObjectPool.h"
#include "CHJMonster.h"
#include "CHJPlayerBullet.h"
#include "CHJMonsterBullet.h"

class CPoolMgr
{
private:
	CPoolMgr();
	CPoolMgr(const CPoolMgr& rhs) = delete;
	CPoolMgr& operator=(CPoolMgr& rObj) = delete;
	~CPoolMgr();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render(HDC hDC);
	void Release();

public:
	CHJPlayerBullet* Get_PlayerBullet();

public:
	static CPoolMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CPoolMgr;
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
	static CPoolMgr* m_pInstance;

	ObjectPool<CHJMonster> m_MonsterPool;					// 최대 50개
	ObjectPool<CHJPlayerBullet> m_PlayerBulletPool;			// 최대 100개
	ObjectPool<CHJMonsterBullet> m_MonsterBulletPool;			// 최대 500개


};

