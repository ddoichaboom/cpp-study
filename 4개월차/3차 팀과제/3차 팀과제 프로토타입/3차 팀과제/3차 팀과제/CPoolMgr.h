#pragma once
#include "ObjectPool.h"
#include "CHJMonster.h"
#include "CHJPlayerBullet.h"
#include "CHJMonsterBullet.h"

// 호준 추가 
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
	CHJPlayerBullet*	Get_PlayerBullet();
	CHJMonster*			Get_Monster();
	CHJMonsterBullet*	Get_MonsterBullet();
	ObjectPool<CHJPlayerBullet>& Get_PlayerBulletPool() { return m_PlayerBulletPool; }
	ObjectPool<CHJMonster>& Get_MonsterPool() { return m_MonsterPool; }
	ObjectPool<CHJMonsterBullet>& Get_MonsterBulletPool() { return m_MonsterBulletPool; }

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

