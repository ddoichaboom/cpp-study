#include "pch.h"
#include "CPoolMgr.h"

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
}

void CPoolMgr::Release()
{

}

CHJPlayerBullet* CPoolMgr::Get_PlayerBullet()
{
	return m_PlayerBulletPool.Acquire();
}
