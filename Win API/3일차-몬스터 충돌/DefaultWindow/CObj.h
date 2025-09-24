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

	const RECT* Get_Rect() { return &m_tRect; }
	void		Set_Dead() { m_bDead = true; }


public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;

	float		m_fSpeed;
	bool		m_bDead;

};

