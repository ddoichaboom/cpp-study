#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Set_Pos(float fX, float fY) 
	{
		m_tInfo.fX = fX;
		m_tInfo.fY = fY;
	}
	void		Set_Direction(DIRECTION eDir)
	{
		m_eDir = eDir;
	}

	void		Set_PosX(float fX) { m_tInfo.fX += fX; }
	void		Set_PosY(float fY) { m_tInfo.fY += fY; }

	const RECT* Get_Rect() { return &m_tRect; }
	const INFO* Get_Info() { return &m_tInfo; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_Angle(float fAngle) { m_fAngle = fAngle; }
	void		Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
	bool		Get_Dead() { return m_bDead; }

public:
	//void		Set_Speed(DWORD  )	{ }

public:
	virtual void	Initialize()					PURE;
	virtual int		Update(double deltaTime)		PURE;
	virtual void	Late_Update()					PURE;
	virtual void	Render(HDC hDC)					PURE;
	virtual void	Release()						PURE;

protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;

	float		m_fSpeed;

	bool		m_bOnGround;
	bool		m_bOnLine;
	float		m_fVx;					// 좌우 이동 속도
	float		m_fVy;					// 수직 이동 속도
	float		m_fMaxMoveSpeed;
	float		m_fAccelSpeed;			// 평지 이동 속도
	float		m_fJumpSpeed;
	float		m_decel_ground;			// 지표면에서의 좌우 감속
	float		m_decel_air;			// 공중에서의 좌우 감속
	double		m_deltaTime;

	float		m_fDistance;
	float		m_fAngle;
	bool		m_bDead;

	CObj* m_pTarget;

};

