#include "pch.h"
#include "CPoolMgr.h"

// 호준 추가
CPoolMgr* CPoolMgr::m_pInstance = nullptr;

CPoolMgr::CPoolMgr()
{

}

CPoolMgr::~CPoolMgr()
{

}

void CPoolMgr::Initialize()
{
	m_PlayerBulletPool.Initialize(100);
	m_MonsterPool.Initialize(50);
	m_MonsterBulletPool.Initialize(500);

}

void CPoolMgr::Update()
{
	m_PlayerBulletPool.ForEachActivate([](CHJPlayerBullet& bullet)
		{
			bullet.Update();
		});
	m_MonsterPool.ForEachActivate([](CHJMonster& Monster)
		{
			Monster.Update();
		});
	m_MonsterBulletPool.ForEachActivate([](CHJMonsterBullet& bullet)
		{
			bullet.Update();
		});
}

void CPoolMgr::Late_Update()
{

}

void CPoolMgr::Render(HDC hDC)
{
	m_PlayerBulletPool.ForEachActivate([&](CHJPlayerBullet& bullet)
		{
			bullet.Render(hDC);
		});
	m_MonsterPool.ForEachActivate([&](CHJMonster& Monster)
		{
			Monster.Render(hDC);
		});
	m_MonsterBulletPool.ForEachActivate([&](CHJMonsterBullet& bullet)
		{
			bullet.Render(hDC);
		});
}

void CPoolMgr::Release()
{
	m_PlayerBulletPool.DeactivateAll();
	m_MonsterBulletPool.DeactivateAll();
	m_MonsterPool.DeactivateAll();

}

CHJPlayerBullet* CPoolMgr::Get_PlayerBullet()
{
	return m_PlayerBulletPool.Acquire();
}

CHJMonster* CPoolMgr::Get_Monster()
{
	return m_MonsterPool.Acquire();
}

CHJMonsterBullet* CPoolMgr::Get_MonsterBullet()
{
	return m_MonsterBulletPool.Acquire();
}
