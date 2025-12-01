#pragma once
#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO& Get_Info() const { return m_tInfo; }
	const OBJ_ID& Get_ObjID() const { return m_eID; }
	const float& Get_Size() const { return m_fSize; }

	void Set_Dead() { m_bDead = true; }

public:
	// PooledObj 에서 쓸 함수
	// 현재 풀에서 사용중인지 여부
	bool    IsInUse() const { return m_bInUse; }				// 호준 추가
	void    SetInUse(bool inUse) { m_bInUse = inUse; }			// 호준 추가 

	// 풀에서 꺼낼 때 / 풀에서 되돌릴 때
	void    Activate();											// 호준 추가
	void    Deactivate();										// 호준 추가 

	bool	Is_Dead() const { return m_bDead; }					// 호준 추가
	

public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;
	virtual void	OnCollision(OBJ_ID eID) PURE;

protected:
	OBJ_ID  m_eID;

	INFO	m_tInfo;
	float	m_fSpeed;
	float	m_fAngle;

	// TODO : 플레이어를 추가해놓긴 했는데 안 쓰는 미니 게임이면 만들 거 따로 만들고 주석 추가 해주세용

	// TODO : 객체 전체 사이즈, HSPlayer 참고, 
	// 정사각형이나 원 말고 다르게 하고 싶으면 
	// 본인이 만든 클래스에다 멤버로 추가하고 주석 좀...충돌 처리도 추가하셔야...
	float	m_fSize;

	D3DXVECTOR3	m_vPoint[4];							 
	D3DXVECTOR3	m_vOriginPoint[4];							// 호준 추가 		

	bool	m_bDead;
	bool    m_bInUse;										// 호준 추가 

};

