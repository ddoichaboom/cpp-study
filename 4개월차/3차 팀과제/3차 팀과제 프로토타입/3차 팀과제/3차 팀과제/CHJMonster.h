#pragma once
#include "CObj.h"

class CHJPlayer;

class CHJMonster :
    public CObj
{
public:
    CHJMonster();
    virtual ~CHJMonster();

public:
    enum MONSTER_TYPE
    {
        DEFAULT_MONSTER, TRACE_MONSTER, MT_END
    };

public:
    void Initialize() override;
    int  Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
    void OnCollision(OBJ_ID eID) override;


public:
    // CHJScene에서 몬스터 생성 호출 함수
    void Spawn(const D3DXVECTOR3& vStartPos, MONSTER_TYPE eType);

private:
    void Monster_Movement();
    void Fire_Bullet();
    void Set_vToPlayer();


private:
    D3DXVECTOR3		m_vGunPoint;
    D3DXVECTOR3		m_vOriginGunPoint;
    D3DXVECTOR3     m_vOriginPos;
    D3DXVECTOR3     m_vToPlayer;
    D3DXVECTOR3     m_vGunTarget;

    DWORD			m_TimeCheck;
    int             m_iHp;
    float           m_fFireAngle;
    bool            m_bSwitch;
    DWORD           m_FireCoolTime;
    MONSTER_TYPE    m_eMonsterType;
};

