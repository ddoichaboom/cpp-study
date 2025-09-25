#pragma once
#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void	Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void					Set_Direction(DIRECTION eDir) { m_eDir = eDir; }
	void					Set_MonsterType(MONSTERTYPE eMtype) { m_eMtype = eMtype; }
	void					Set_Dead() { m_bDead = true; }
	const		RECT*		Get_Rect() { return &m_tRect; }
	void					Set_Angle(float _fAngle) { m_fAngle = _fAngle; }

public:
	virtual		void		Initialize()		PURE;
	virtual		int			Update()			PURE;
	virtual		void		Late_Update()		PURE;
	virtual		void		Render(HDC hDC)		PURE;
	virtual		void		Release()			PURE;

protected:
	void		Update_Rect();

protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	DIRECTION		m_eDir;
	MONSTERTYPE		m_eMtype;

	float			m_fSpeed;
	float			m_fDistance;
	bool			m_bDead;
	float			m_fAngle;
};
