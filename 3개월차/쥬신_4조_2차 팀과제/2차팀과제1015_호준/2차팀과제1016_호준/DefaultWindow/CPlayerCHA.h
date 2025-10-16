#pragma once

#include "CObj.h"
#include "CBullet.h"
#include "CLine.h"

class CPlayerCHA : public CObj
{
public:
	CPlayerCHA();
	virtual ~CPlayerCHA();

public:
	enum PLAYER_DIRECTION { PD_LEFT = 1, PD_RIGHT };



public:
	void Initialize() override;
	int	 Update(float deltaTime) override;
	void Late_Update(float deltaTime) override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	void	Key_Input(float deltaTime);
	void	Offset(float deltaTime);

private:
	// 코드 너무 길어서 정리용
	void	Collision_Vertical_Line();
	void	Collision_Border_Line();
	void	Rect_Col_Movement();
	void	Circle_Col_Movement();

private:
	POINT				m_tPosin;
	POINT				m_tCursor;

	clock_t				KeyTimeCheck[10];				// 특정 키 입력을 구분하고, 입력된 시점을 저장하는 변수
	CVector2			m_MoveVec;						// 이동할 벡터값을 저장하는 변수

	CLine*				m_pTargetLine;
	CLine*				m_pVerticalLine;
	PLAYER_DIRECTION	m_ePlayerDir;

};

