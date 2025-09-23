#include "pch.h"
#include "CBullet.h"

CBullet::CBullet()
{

}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fSpeed	= 5.f;
}

int CBullet::Update()
{
	__super::Update_Rect();

	switch (m_eDirection)
	{
	case UP:
		m_tInfo.fY -= m_fSpeed;
		break;

	case LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;

	case RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;

	case DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	}


	return 0;
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{

}