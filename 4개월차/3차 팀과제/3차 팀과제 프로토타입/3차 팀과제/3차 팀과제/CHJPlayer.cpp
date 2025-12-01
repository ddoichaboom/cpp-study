#include "pch.h"
#include "CHJPlayer.h"
#include "CKeyMgr.h"
#include "CHJPlayerBullet.h"
#include "CPoolMgr.h"

CHJPlayer::CHJPlayer()
	: m_iMaxBullet(50), m_iMaxBulletBuffer(5), m_iFireMode(SINGLE_SHOT),
	m_iCurBulletBuffer(0), m_iCurBullet(m_iMaxBullet), m_ckNow(0),
	m_bWantReload(false), m_iMaxHp(100), m_iCurHp(m_iMaxHp)
{
	m_eID = PLAYER;
	ZeroMemory(m_TimeCheck, sizeof(m_TimeCheck));
}

CHJPlayer::~CHJPlayer()
{
	Release();
}

void CHJPlayer::Initialize()
{
	// 플레이어 초기 좌표
	m_tInfo.vPos = { WINCX * 0.5f , WINCY * 0.5f , 0.f };

	// 플레이어 바라보는 방향
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	// 플레이어 사이즈 
	m_fSize = 20.f;
	m_fSpeed = 3.f;

	m_vPoint[0] = { m_tInfo.vPos.x - m_fSize * 0.5f, m_tInfo.vPos.y - m_fSize * 0.5f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + m_fSize * 0.5f, m_tInfo.vPos.y - m_fSize * 0.5f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + m_fSize * 0.5f, m_tInfo.vPos.y + m_fSize * 0.5f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - m_fSize * 0.5f, m_tInfo.vPos.y + m_fSize * 0.5f, 0.f };

	for (int i = 0; i < 4; ++i)
	{
		m_vOriginPoint[i] = m_vPoint[i];
	}

	// 포신
	m_vGunPoint = { m_tInfo.vPos.x, m_tInfo.vPos.y - m_fSize , 0.f };
	m_vOriginGunPoint = m_vGunPoint;
}

int CHJPlayer::Update()
{
	if (m_iCurHp <= 0)
		Set_Dead();

	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	m_ckNow = clock();
	
	Bullet_State();

	Key_Input();

	Player_Movement();

	Look_Mouse();

	// 월드 행렬 구성 - S, R, T
	D3DXMATRIX matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		m_vPoint[i] -= {WINCX * 0.5f , WINCY * 0.5f , 0.f};

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	m_vGunPoint = m_vOriginGunPoint;
	m_vGunPoint -= {WINCX * 0.5f, WINCY * 0.5f, 0.f};

	D3DXVec3TransformCoord(&m_vGunPoint, &m_vGunPoint, &m_tInfo.matWorld);

	return OBJ_NOEVENT;
}

void CHJPlayer::Late_Update()
{
}

void CHJPlayer::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - m_fSize * 0.5f),
		int(m_tInfo.vPos.y - m_fSize * 0.5f),
		int(m_tInfo.vPos.x + m_fSize * 0.5f),
		int(m_tInfo.vPos.y + m_fSize * 0.5f));

	// 포신 그리기
	MoveToEx(hDC, (int)m_tInfo.vPos.x, (int)m_tInfo.vPos.y, nullptr);
	LineTo(hDC, (int)m_vGunPoint.x, (int)m_vGunPoint.y);
}

void CHJPlayer::Release()
{
}

void CHJPlayer::OnCollision(OBJ_ID eID)
{
	if (m_bDead)
		return;

	if (eID == MONSTER)
	{
		--m_iCurHp;

		if (m_iCurHp <= 0)
		{
			Set_Dead();
		}
	}
	else if (eID == MONSTER_BULLET)
	{
		--m_iCurHp;

		if (m_iCurHp <= 0)
		{
			Set_Dead();
		}
	}
}

void CHJPlayer::Key_Input()
{

	m_vInputDir = { 0.f, 0.f, 0.f };

	if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		m_vInputDir.y -= 1.f;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		m_vInputDir.x -= 1.f;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		m_vInputDir.y += 1.f;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_vInputDir.x += 1.f;
	}

	// 재장전 
	if (CKeyMgr::Get_Instance()->Key_Down('R'))
	{
		if ((m_TimeCheck[TC_RELOAD] == 0) && (m_TimeCheck[TC_AUTO_RELOAD] == 0))
			m_bWantReload = true;
	}

	// 총알 발사 모드 변경 
	if (CKeyMgr::Get_Instance()->Key_Down('B'))
	{
		++m_iFireMode;
		if (m_iFireMode >= FT_END)
			m_iFireMode = SINGLE_SHOT;
	}

	// 현재 잔여 총알의 개수 
	if (m_iCurBullet > 0)
	{
		// 총알 발사 타입 - 단발
		if (m_iFireMode == SINGLE_SHOT)
		{
			if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
			{
				Fire_Bullet();
			}
		}
		// 총알 발사 타입 - 점사
		else if (m_iFireMode == BURST)
		{
			if (m_iCurBulletBuffer >= m_iMaxBulletBuffer)
				return;

			if (m_iCurBulletBuffer < m_iMaxBulletBuffer)
			{
				if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
				{
					Fire_Bullet();
					++m_iCurBulletBuffer;

					if (m_iCurBulletBuffer == m_iMaxBulletBuffer)
					{
						m_TimeCheck[TC_BURST] = m_ckNow;
					}
				}
			}
			
		}
		//  총알 발사 타입 - 자동(연발)
		else if (m_iFireMode == AUTO)
		{
			if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
			{
				Fire_Bullet();
			}
		}
	}
	
}

void CHJPlayer::Look_Mouse()
{
	m_vMouse = Get_Mouse();

	D3DXVECTOR3 vToMouse = m_vMouse - m_tInfo.vPos;

	D3DXVec3Normalize(&vToMouse, &vToMouse);

	float fDot = D3DXVec3Dot(&m_tInfo.vLook, &vToMouse);

	m_fAngle = acosf(fDot);

	D3DXVECTOR3 vCross;
	D3DXVec3Cross(&vCross, &m_tInfo.vLook, &vToMouse);

	if (vCross.z < 0.f)
		m_fAngle = -m_fAngle;

}

void CHJPlayer::Player_Movement()
{

	if ((m_vInputDir.x != 0.f) || (m_vInputDir.y != 0.f))
	{
		if (D3DXVec3Length(&m_vInputDir) > 0.f)
		{
			D3DXVec3Normalize(&m_vInputDir, &m_vInputDir);
		}
	}

	m_tInfo.vPos.x += m_vInputDir.x * m_fSpeed;
	m_tInfo.vPos.y += m_vInputDir.y * m_fSpeed;
}

void CHJPlayer::Fire_Bullet()
{
	// 현재 잔여 총알의 개수 
	if (m_iCurBullet > 0)
	{
		CHJPlayerBullet* pBullet = CPoolMgr::Get_Instance()->Get_PlayerBullet();

		if (pBullet)
		{
			// 총알 생성 기준 - 포신 끝 점
			D3DXVECTOR3 vStartPos = m_vGunPoint;

			// 총알 진행 방향 - 플레이어가 바라보는 방향
			D3DXVECTOR3 vDir = m_vGunPoint - m_tInfo.vPos;

			pBullet->Fire(vStartPos, vDir);

			// 발사 후 잔여 총알 개수 감소 
			m_iCurBullet--;
		}
	}
	
}

void CHJPlayer::Bullet_State()
{
	if (m_iCurBulletBuffer == m_iMaxBulletBuffer)
	{
		if (m_ckNow - m_TimeCheck[TC_BURST] >= 250)
		{
			m_iCurBulletBuffer = 0;
			m_TimeCheck[TC_BURST] = 0;
		}
	}

	if (m_bWantReload && (m_TimeCheck[TC_RELOAD] == 0))
	{
		m_TimeCheck[TC_RELOAD] = m_ckNow;
	}

	if (m_bWantReload && (m_TimeCheck[TC_RELOAD] != 0) &&
		(m_ckNow - m_TimeCheck[TC_RELOAD] >= 500))
	{
		m_iCurBullet	= m_iMaxBullet;
		m_bWantReload	= false;
		m_TimeCheck[TC_RELOAD] = 0;
	}

	// 잔여 탄약이 없을 때 일정 시간이 지난 후 자동 재장전
	if (m_iCurBullet == 0 && !m_bWantReload)
	{
		if (m_TimeCheck[TC_AUTO_RELOAD] == 0)
		{
			m_TimeCheck[TC_AUTO_RELOAD]= m_ckNow;
		}

		if (m_ckNow - m_TimeCheck[TC_AUTO_RELOAD] >= 1000)
		{
			m_iCurBullet = m_iMaxBullet;
			m_TimeCheck[TC_AUTO_RELOAD] = 0;
		}
	}
	else
	{
		m_TimeCheck[TC_AUTO_RELOAD] = 0;
	}

}
