#pragma once

#include "CComponent.h"
#include "Engine_Define.h"

BEGIN(Engine)

class ENGINE_DLL CTexture : public CComponent
{
// 접근 제어 지시자 private 선언
// 반드시 Create()를 통해서만 생성하겠다~ 이런 의미
private:
	explicit CTexture();
	explicit CTexture(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTexture(const CTexture& rhs);
	virtual ~CTexture();

public:
	virtual HRESULT Ready_Texture(TEXTUREID eID, const _tchar* pPath, const _uint& iCnt);
	void			Set_Texture(const _uint& iIndex = 0);

private:
	vector<IDirect3DBaseTexture9*>		m_vecTexture;

public:
	static CTexture* Create(LPDIRECT3DDEVICE9 pGraphicDev,
							TEXTUREID eID, const _tchar* pPath,
							const _uint& iCnt = 1);

	virtual CComponent* Clone();

private:
	virtual void Free();

};

END