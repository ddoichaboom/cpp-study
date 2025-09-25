#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{

}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 5.f;
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eMtype)
	{
	case HR_MONSTER:
		m_tInfo.fX += m_fSpeed;
		break;

	case VT_MONSTER:
		m_tInfo.fY += m_fSpeed;
		break;

	case UQ_MONSTER:

		break;

	}

	__super::Update_Rect();

	

	return OBJ_NOEVENT;

}

void CMonster::Late_Update()
{
	if (m_tRect.left <= BOUNDARY_LEFT || BOUNDARY_RIGHT <= m_tRect.right)
		m_fSpeed *= -1.f;

	if (m_tRect.top <= BOUNDARY_TOP || BOUNDARY_BOTTOM >= WINCX - 100)
		m_fSpeed *= -1.f;
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CMonster::Release()
{
}