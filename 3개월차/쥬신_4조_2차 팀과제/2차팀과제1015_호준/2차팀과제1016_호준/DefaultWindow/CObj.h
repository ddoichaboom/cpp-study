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

	void		Set_FrameKey(const TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

public:
	virtual void	Initialize()	PURE;

#pragma region 호준 - 일부 수정 

	// Update 함수에 매개변수로 deltaTime 사용
	virtual int 	Update(float deltaTime = 0.f)	PURE;
	virtual void	Late_Update(float deltaTime = 0.f)	PURE;

#pragma endregion

	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;

	float		m_fSpeed;
	float		m_fDistance;
	float		m_fAngle;
	bool		m_bDead;

	const		TCHAR* m_pFrameKey;

#pragma region 호준 - 신규 추가 

	bool		m_bOnGround;			// 지면 판정 ( 점프 가능 유무, 중력 적용 유무 판단 용도 - 기존 m_bJump랑 비슷함 )
	float		m_fVx;					// x축 이동 속도
	float		m_fVy;					// y축 이동 속도
	float		m_fMaxMoveSpeed;		// x축 최대 이동 속도
	float		m_fAccelSpeed;			// x축 가속도
	float		m_fJumpSpeed;			// 점프 초기 속도


#pragma endregion

	CObj* m_pTarget;

};

