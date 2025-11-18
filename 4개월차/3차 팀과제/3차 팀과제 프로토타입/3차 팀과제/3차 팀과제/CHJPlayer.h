#pragma once
#include "CObj.h"

class CHJPlayer : public CObj
{
public:
	CHJPlayer();
	virtual ~CHJPlayer();

private:
	void Key_Input();
	void Look_Mouse();
	void Player_Movement();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void OnCollision(OBJ_ID eID) override;


private:
	// 포신 사용 예정 
	D3DXVECTOR3		m_vInputDir;
	D3DXVECTOR3     m_vMouse;
	D3DXVECTOR3		m_vGunPoint;
	D3DXVECTOR3		m_vOriginGunPoint;
};

