#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo		= { float(WINCX >> 1), float(WINCY >> 1), 100.f, 100.f };
	m_fSpeed	= 10.f;
}

int	CPlayer::Update()
{
	RECT rc = {100, 100, 700, 500};

	__super::Update_Rect();

	Key_Input();
	
	/*if ((m_tRect.left < BOUNDARY_LEFT && m_tRect.right < BOUNDARY_RIGHT) && (m_tRect.top > BOUNDARY_TOP && m_tRect.bottom < BOUNDARY_BOTTOM))
	{

	}*/
	
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom
	);
}

void CPlayer::Release()
{

}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState('W') & 0x8001)
	{
		
		m_tInfo.fY -= m_fSpeed;

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
			m_pBullet->push_back(Create_Bullet(UP));
	}

	if (GetAsyncKeyState('A') & 0x8001)
	{
		m_tInfo.fX -= m_fSpeed; 

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
			m_pBullet->push_back(Create_Bullet(LEFT));
	}

	if (GetAsyncKeyState('S') & 0x8001)
	{
		m_tInfo.fY += m_fSpeed;		

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
			m_pBullet->push_back(Create_Bullet(DOWN));
	}

	if (GetAsyncKeyState('D') & 0x8001)
	{
		m_tInfo.fX += m_fSpeed;

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
			m_pBullet->push_back(Create_Bullet(RIGHT));
	}

	if (GetAsyncKeyState('M') & 0x0001)
		m_pMonster->push_back(Create_Monster(LEFT));

}

CObj* CPlayer::Create_Bullet(DIRECTION Direction)
{
	CObj* pBullet = new CBullet;

	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Direction(Direction);


	return pBullet;
}

CObj* CPlayer::Create_Monster(DIRECTION Direction)
{
	CObj* pMonster = new CMonster;

	pMonster->Initialize();
	pMonster->Set_Pos(400.f, 200.f);

	pMonster->Set_Direction(Direction);

	return pMonster;

}