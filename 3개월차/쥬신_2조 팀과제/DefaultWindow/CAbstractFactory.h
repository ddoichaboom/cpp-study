#pragma once

#include "CObj.h"

template <typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj*	Create_Obj()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObj* Create_Obj(float _fX, float _fY, DIRECTION eDir)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Direction(eDir);

		return pObj;
	}

	static CObj* Create_Obj(float _fX, float _fY, float _fAngle, BULLETTYPE eBType, float _fDistance = 0)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Angle(_fAngle);
		pObj->Set_Bullet_Type(eBType);
		//pObj->Set_Distance(_fDistance);

		return pObj;
	}

	static CObj* Create_Obj(float _fX, float _fY, MONSTERTYPE eMtype)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_MonsterType(eMtype);

		return pObj;
	}

	 
	


};