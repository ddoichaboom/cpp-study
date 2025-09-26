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

	static CObj* Create_Obj(float fX, float fY, float fAngle = 0)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Angle(fAngle);

		return pObj;
	}

	static CObj* Create_Obj(float fX, float fY, DIRECTION eDir, float fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Direction(eDir);
		pObj->Set_Angle(fAngle);
		return pObj;
	}


	//static CObj* Create_Obj(float fX, float fY, MON_MV_PATTERN ePattern, float fAngle)
	//{
	//	CObj* pObj = new T;
	//	pObj->Initialize();
	//	pObj->Set_Pos(fX, fY);
	//	pObj->Set_Pattern(ePattern);
	//	pObj->Set_Angle(fAngle);
	//	return pObj;
	//}

	

};

