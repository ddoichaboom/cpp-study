#pragma once

#include "CBase.h"
//#include "../../Base/CBase.h"
#include "CGraphicDev.h"

class CMainApp : public CBase
{
	// 持失切, 社瑚切

private:
	explicit CMainApp();
	virtual ~CMainApp();

public:
	HRESULT			Ready_MainApp();
	int				Update_MainApp(const float& fTimeDelta);
	void			LateUpdate_MainApp(const float& fTimeDelta);
	void			Render_MainApp();

private:
	LPDIRECT3DDEVICE9		m_pGraphicDev;
	Engine::CGraphicDev* m_pDeviceClass;

public:
	static CMainApp* Create();

private:
	virtual void		Free();

};

