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

	

public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeed;

};

