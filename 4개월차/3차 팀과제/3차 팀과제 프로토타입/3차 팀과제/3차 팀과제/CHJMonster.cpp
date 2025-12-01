#include "pch.h"
#include "CHJMonster.h"
#include "CObjMgr.h"
#include "CHJMonsterBullet.h"
#include "CPoolMgr.h"

CHJMonster::CHJMonster()
	: m_TimeCheck(0), m_fFireAngle(0.f), m_bSwitch(false),
	m_FireCoolTime(0), m_eMonsterType(DEFAULT_MONSTER)
{

}

CHJMonster::~CHJMonster()
{

}

void CHJMonster::Initialize()
{
	m_eID = MONSTER;

	m_tInfo.vLook = { 0.f, -1.f, 0.f };

}

int CHJMonster::Update()
{
	if (m_iHp <= 0)
		Set_Dead();

	if (m_bDead)
	{
		Deactivate();
		return OBJ_DEAD;
	}

	Monster_Movement();

	if ((m_eMonsterType == DEFAULT_MONSTER) && (D3DXVec3Length(&m_vToPlayer) != 0))
		Fire_Bullet();

	return OBJ_NOEVENT;
}

void CHJMonster::Late_Update()
{
}

void CHJMonster::Render(HDC hDC)
{
	if (m_eMonsterType == DEFAULT_MONSTER)
	{
		HBRUSH	hOldBrush = (HBRUSH)SelectObject(hDC, Color::g_hDefaultMonsterBrush);
		HPEN	hOldPen = (HPEN)SelectObject(hDC, Color::g_hDefaultMonsterPen);

		Ellipse(hDC,
			int(m_tInfo.vPos.x - m_fSize),
			int(m_tInfo.vPos.y - m_fSize),
			int(m_tInfo.vPos.x + m_fSize),
			int(m_tInfo.vPos.y + m_fSize));

		SelectObject(hDC, hOldBrush);
		SelectObject(hDC, hOldPen);
	}
	else if (m_eMonsterType == TRACE_MONSTER)
	{
		HBRUSH	hOldBrush = (HBRUSH)SelectObject(hDC, Color::g_hTraceMonsterBrush);
		HPEN	hOldPen = (HPEN)SelectObject(hDC, Color::g_hTraceMonsterPen);

		Ellipse(hDC,
			int(m_tInfo.vPos.x - m_fSize),
			int(m_tInfo.vPos.y - m_fSize),
			int(m_tInfo.vPos.x + m_fSize),
			int(m_tInfo.vPos.y + m_fSize));

		SelectObject(hDC, hOldBrush);
		SelectObject(hDC, hOldPen);
	}

}

void CHJMonster::Release()
{
}

void CHJMonster::OnCollision(OBJ_ID eID)
{
	if (m_bDead)
		return;

	if (eID == PLAYER_BULLET)
	{
		--m_iHp;

		if (m_iHp <= 0)
			Set_Dead();
	}

}

void CHJMonster::Spawn(const D3DXVECTOR3& vStartPos, MONSTER_TYPE eType)
{
	m_tInfo.vPos = vStartPos;
	m_vOriginPos = vStartPos;
	m_eMonsterType = eType;

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

	if (eType == TRACE_MONSTER)
	{
		m_eMonsterType = TRACE_MONSTER;
		m_fSize = 8.f;
		m_fSpeed = 1.0f;
		m_iHp = rand() % 3 + 3;
	}
	else if (eType == DEFAULT_MONSTER)
	{
		m_fSize = 10.f;
		m_fSpeed = 0.5f;
		m_iHp = rand() % 3 + 5;
	}
}

void CHJMonster::Monster_Movement()
{
	Set_vToPlayer();

	m_tInfo.vPos += m_vToPlayer * m_fSpeed;

	// m_fAngle 조정
	float fDot = D3DXVec3Dot(&m_tInfo.vLook, &m_vToPlayer);

	m_fAngle = acosf(fDot);

	D3DXVECTOR3 vCross;
	D3DXVec3Cross(&vCross, &m_tInfo.vLook, &m_vToPlayer);

	if (vCross.z < 0.f)
		m_fAngle = -m_fAngle;

	// 월드 행렬 구성 - S, R, T
	D3DXMATRIX matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		m_vPoint[i] -= m_vOriginPos;

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	m_vGunPoint = m_vOriginGunPoint;
	m_vGunPoint -= m_vOriginPos;

	D3DXVec3TransformCoord(&m_vGunPoint, &m_vGunPoint, &m_tInfo.matWorld);
}


void CHJMonster::Fire_Bullet()
{
	clock_t ckNow = clock();

	// 1단계: 패턴 활성화 체크 (5초 쿨타임)
	const clock_t PATTERN_COOLTIME = 5000;  // 5초
	const clock_t PATTERN_DURATION = 5000;   // 5초 동안 패턴 실행

	clock_t elapsedTime = ckNow - m_FireCoolTime;

	// 패턴 쿨타임이 지나지 않았으면 발사 안 함
	if (elapsedTime < PATTERN_COOLTIME)
		return;

	// 10초(5초 쿨타임 + 5초 패턴)가 지나면 새로운 사이클 시작
	if (elapsedTime >= PATTERN_COOLTIME + PATTERN_DURATION)
	{
		m_FireCoolTime = ckNow;
		m_fFireAngle = 0.f;      // 스윙 각도 초기화
		m_bSwitch = false;       // 방향 초기화
		m_TimeCheck = ckNow;     // 발사 타이머 초기화
		return;
	}

	// 2단계: 스윙 각도 업데이트 (50ms마다)
	const clock_t ANGLE_UPDATE_INTERVAL = 50;  // 50ms마다 각도 조정
	static clock_t lastAngleUpdate = 0;

	if (ckNow - lastAngleUpdate >= ANGLE_UPDATE_INTERVAL)
	{
		lastAngleUpdate = ckNow;

		const float ANGLE_STEP = D3DX_PI * 0.025f;  // 약 4.5도
		const float MAX_SWING_ANGLE = D3DX_PI * 0.25f;  // ±45도

		// 스윙 방향에 따라 각도 증감
		if (!m_bSwitch)
		{
			m_fFireAngle += ANGLE_STEP;

			// 최대 각도 도달 시 방향 전환
			if (m_fFireAngle >= MAX_SWING_ANGLE)
			{
				m_fFireAngle = MAX_SWING_ANGLE;
				m_bSwitch = true;
			}
		}
		else
		{
			m_fFireAngle -= ANGLE_STEP;

			// 최소 각도 도달 시 방향 전환
			if (m_fFireAngle <= -MAX_SWING_ANGLE)
			{
				m_fFireAngle = -MAX_SWING_ANGLE;
				m_bSwitch = false;
			}
		}
	}

	// 3단계: 실제 총알 발사 (500ms마다)
	const clock_t FIRE_INTERVAL = 500;  // 500ms마다 발사

	if (ckNow - m_TimeCheck < FIRE_INTERVAL)
		return;

	m_TimeCheck = ckNow;

	// 4단계: 발사 방향 계산
	// 기준 방향 = 플레이어 방향
	D3DXVECTOR3 vBaseDir = m_vToPlayer;
	D3DXVec3Normalize(&vBaseDir, &vBaseDir);

	// 스윙 각도만큼 회전 행렬 적용
	D3DXMATRIX matRotZ;
	D3DXMatrixRotationZ(&matRotZ, m_fFireAngle);

	D3DXVECTOR3 vFinalDir;
	D3DXVec3TransformNormal(&vFinalDir, &vBaseDir, &matRotZ);
	D3DXVec3Normalize(&vFinalDir, &vFinalDir);

	// 5단계: 총알 생성 및 발사
	CHJMonsterBullet* pBullet = CPoolMgr::Get_Instance()->Get_MonsterBullet();

	if (pBullet)
	{
		// 시작 위치 = 포신 끝점 (월드 좌표)
		D3DXVECTOR3 vStartPos = m_vGunPoint;

		// 스윙 각도가 적용된 방향으로 발사
		pBullet->Fire(vStartPos, vFinalDir);
	}
}

void CHJMonster::Set_vToPlayer()
{
	CObj* pPlayerObj = CObjMgr::Get_Instance()->Get_Player();
	if (!pPlayerObj)
	{
		m_vToPlayer = { 0.f, 0.f, 0.f };
		return;
	}

	m_vToPlayer = pPlayerObj->Get_Info().vPos - m_tInfo.vPos;

	D3DXVec3Normalize(&m_vToPlayer, &m_vToPlayer);
}

