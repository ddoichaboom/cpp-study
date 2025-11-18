#include "pch.h"
#include "CObj.h"

CObj::CObj() 
	: m_fSpeed(0.f), m_fAngle(0.f), m_bDead(false),
	m_eID(OBJ_END), m_fSize(0.f), m_bInUse(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	D3DXMatrixIdentity(&m_tInfo.matWorld);

	ZeroMemory(m_vPoint, sizeof(D3DXVECTOR3) * size(m_vPoint));
	ZeroMemory(m_vOriginPoint, sizeof(D3DXVECTOR3) * size(m_vOriginPoint));
}

CObj::~CObj()
{
}

// 호준 추가 
void CObj::Activate()
{
	m_bInUse	=	true;
	m_bDead		=	false;		
}

// 호준 추가 
void CObj::Deactivate()
{
	m_bInUse =	false;
	m_bDead	 =	true;
}
