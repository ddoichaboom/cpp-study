#pragma once
#include "CGameObject.h"

class CBackGround : public CGameObject
{
private:
	explicit				CBackGround(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit				CBackGround(const CGameObject& rhs);
	virtual					~CBackGround();

public:
	virtual	HRESULT			Ready_GameObject();
	virtual	_int			Update_GameObject(const _float& fTimeDelta);
	virtual	void			LateUpdate_GameObject(const _float& fTimeDelta);
	virtual	void			Render_GameObject();

public:
	static	CBackGround*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual		void		Free();
};

