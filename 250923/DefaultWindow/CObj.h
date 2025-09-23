#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

	
public:
	enum DIRECTION { UP, LEFT, RIGHT, DOWN, D_END = 4};

public:
	void	Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void	Set_Direction(DIRECTION Direction) { m_eDirection = Direction; }
	void	Set_Speed(float fSpeed) { m_fSpeed = fSpeed; }
	RECT*	Get_Info() { return &m_tRect; }
	float*	Get_Speed() { return &m_fSpeed; }


public:
	virtual	void	Initialize()		PURE;
	virtual int		Update()			PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release()			PURE;

protected:
	void			Update_Rect();

protected:
	INFO			m_tInfo;
	RECT			m_tRect;

	float			m_fSpeed;
	DIRECTION		m_eDirection;
};

