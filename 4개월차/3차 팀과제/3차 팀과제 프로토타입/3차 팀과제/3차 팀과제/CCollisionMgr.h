#pragma once
#include "CObj.h"

class CCollisionMgr
{
public:
	// TODO : 충돌 처리 추가하려면 추가하고 주석 달아주세용
	static void Collision_Circle(list<CObj*> Dst, list<CObj*> Src);
	static bool Check_Circle(CObj* pDst, CObj* pSrc);
};

