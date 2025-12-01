#include "pch.h"
#include "CHJMonsterBullet.h"

CHJMonsterBullet::CHJMonsterBullet()
{
}

CHJMonsterBullet::~CHJMonsterBullet()
{
}

void CHJMonsterBullet::Initialize()
{
	m_eID = MONSTER_BULLET;

	// 몬스터 총알 크기
	m_fSize = 3.f;

	// 몬스터 총알 속력
	m_fSpeed = 2.f;
}

int CHJMonsterBullet::Update()
{
	if (m_bDead)
	{
		// 해당 총알 비활성화 
		Deactivate();
		return OBJ_DEAD;
	}

	// 총알 움직임 
	Bullet_Movement();

	if ((m_tInfo.vPos.x < 0.f) || (m_tInfo.vPos.x > WINCX) ||
		(m_tInfo.vPos.y < 0.f) || (m_tInfo.vPos.y > WINCY))
	{
		Deactivate();
		return OBJ_DEAD;
	}

	return OBJ_NOEVENT;
}

void CHJMonsterBullet::Late_Update()
{
}

void CHJMonsterBullet::Render(HDC hDC)
{
	HBRUSH	hOldBrush = (HBRUSH)SelectObject(hDC, Color::g_hMonsterBulletBrush);
	HPEN	hOldPen = (HPEN)SelectObject(hDC, Color::g_hMonsterBulletPen);

	// 기본 원 모양 
	Ellipse(hDC,
		int(m_tInfo.vPos.x - m_fSize),
		int(m_tInfo.vPos.y - m_fSize),
		int(m_tInfo.vPos.x + m_fSize),
		int(m_tInfo.vPos.y + m_fSize));

	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
}

void CHJMonsterBullet::Release()
{
}

void CHJMonsterBullet::OnCollision(OBJ_ID eID)
{
	if (m_bDead)
		return;

	if (eID == PLAYER)
		Set_Dead();
	else if (eID == PLAYER_BULLET)
		Set_Dead();
}

void CHJMonsterBullet::Fire(const D3DXVECTOR3& vStartPos, const D3DXVECTOR3& vDir)
{
	// 시작 위치 설정 
	m_tInfo.vPos = vStartPos;

	// 방향 벡터 정규화 후 저장
	m_tInfo.vDir = vDir;
	if (D3DXVec3Length(&m_tInfo.vDir) > 0.f)
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
}

void  CHJMonsterBullet::Bullet_Movement()
{
	// 추가 총알 움직임 구현 시 해당 함수 내에 확장
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
}
