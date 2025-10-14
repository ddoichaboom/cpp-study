#pragma once

#include "CObj.h"
#include "CBullet.h"
#include "CLine.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:


public:
	void Initialize() override;
	int Update(double deltaTime) override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	void	Key_Input(double deltaTime);

private:

	clock_t			KeyTimeCheck[10];				// 특정 키 입력을 구분하고, 입력된 시점을 저장하는 변수
	CVector2		m_MoveVec;						// 이동할 벡터값을 저장하는 변수

	CLine*			m_pTargetLine;

};

