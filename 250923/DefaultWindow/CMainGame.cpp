#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame() : m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Monster(&m_MonsterList);


}

void CMainGame::Update()
{
	m_pPlayer->Update();

	for (auto& pBullet : m_BulletList)
		pBullet->Update();

	for (auto& pMonster : m_MonsterList)
		pMonster->Update();

}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	m_pPlayer->Render(m_hDC);

	for (auto& pBullet : m_BulletList)
		pBullet->Render(m_hDC);

	for (auto& pMonster : m_MonsterList)
		pMonster->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	Safe_Delete<CObj*>(m_pPlayer);

	for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	m_BulletList.clear();

	for_each(m_MonsterList.begin(), m_MonsterList.end(), Safe_Delete<CObj*>);
	m_MonsterList.clear();
}
