#pragma once

#include "CObj.h"

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj* Create_Obj()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObj* Create_Obj(float fX, float fY, DIRECTION eDir)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Direction(eDir);

		return pObj;
	}

};

