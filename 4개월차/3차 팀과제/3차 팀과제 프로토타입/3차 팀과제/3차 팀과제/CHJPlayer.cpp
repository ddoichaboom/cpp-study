#include "pch.h"
#include "CHJPlayer.h"
#include "CKeyMgr.h"

CHJPlayer::CHJPlayer()
{
	m_eID = PLAYER;
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
	m_fSize = 50.f;

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
	Key_Input();

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

	return 0;
}

void CHJPlayer::Late_Update()
{
}

void CHJPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

		if (i > 1)
			continue;

		Ellipse(hDC,
			int(m_vPoint[i].x - 5.f),
			int(m_vPoint[i].y - 5.f),
			int(m_vPoint[i].x + 5.f),
			int(m_vPoint[i].y + 5.f));
	}
	LineTo(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y);

	// 포신 그리기
	MoveToEx(hDC, (int)m_tInfo.vPos.x, (int)m_tInfo.vPos.y, nullptr);
	LineTo(hDC, (int)m_vGunPoint.x, (int)m_vGunPoint.y);
}

void CHJPlayer::Release()
{
}

void CHJPlayer::OnCollision(OBJ_ID eID)
{
}

void CHJPlayer::Key_Input()
{

	// 시계방향 회전 
	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_fAngle += D3DXToRadian(5.f);
	}

	// 반시계방향 회전
	else if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		m_fAngle -= D3DXToRadian(5.f);
	}

	// 재장전 
	if (CKeyMgr::Get_Instance()->Key_Down('R'))
	{

	}

	// 마우스 상호작용
	// 1. 총알 발사 
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{

	}
}
