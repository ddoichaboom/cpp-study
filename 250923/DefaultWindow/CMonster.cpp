#include "pch.h"
#include "CMonster.h"

CMonster::CMonster() 
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_fSpeed = 5.f;
}

int CMonster::Update()
{
	m_tInfo.fX += m_fSpeed;

	__super::Update_Rect();

	if (m_tRect.left <= BOUNDARY_LEFT || BOUNDARY_RIGHT <= m_tRect.right)
		m_fSpeed *= -1.f;


	return 0;
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
