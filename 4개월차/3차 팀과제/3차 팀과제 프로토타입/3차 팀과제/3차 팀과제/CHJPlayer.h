#pragma once
#include "CObj.h"

class CHJPlayer : public CObj
{
public:
	CHJPlayer();
	virtual ~CHJPlayer();

public:
	enum FIRE_TYPE
	{
		SINGLE_SHOT, BURST, AUTO, FT_END
	};
	enum TIME_CHECK_TYPE
	{
		TC_BURST = 0,		// 점사 쿨타임
		TC_RELOAD,			// 수동 재장전 대기 시간 
		TC_AUTO_RELOAD,		// 자동 재장전 대기 시간
		TC_END
	};

private:
	void Key_Input();
	void Look_Mouse();
	void Player_Movement();
	void Fire_Bullet();
	void Bullet_State();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void OnCollision(OBJ_ID eID) override;

public:
	int			Get_CurBullet() const { return m_iCurBullet; }
	int			Get_MaxBullet() const { return m_iMaxBullet; }
	int			Get_MaxHp()		const { return m_iMaxHp; }
	int			Get_CurHp()		const { return m_iCurHp; }

private:
	DWORD			m_TimeCheck[TC_END];
	DWORD			m_ckNow;

	bool			m_bWantReload;
	int				m_iFireMode;
	int				m_iMaxBullet;
	int				m_iCurBullet;

	// 발사 타입 - 점사 구현 위한 현재 버퍼 / 최대 버퍼 변수 
	int				m_iMaxBulletBuffer;
	int				m_iCurBulletBuffer;

	int				m_iMaxHp;
	int				m_iCurHp;


	// 포신 사용 예정 
	D3DXVECTOR3		m_vInputDir;
	D3DXVECTOR3     m_vMouse;
	D3DXVECTOR3		m_vGunPoint;
	D3DXVECTOR3		m_vOriginGunPoint;


};

