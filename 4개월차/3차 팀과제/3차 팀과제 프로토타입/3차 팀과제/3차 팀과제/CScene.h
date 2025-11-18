#pragma once
#include "Define.h"
#include "CObjMgr.h"
#include "CAbstractFactory.h"

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	// TODO : 미니게임 만들 거 맞춰서 OBJ_ID에 추가하고 ObjMgr에 넣어주세용
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Late_Update() PURE;
	virtual void Render(HDC hDC) PURE;
	virtual void Release() PURE;
};

