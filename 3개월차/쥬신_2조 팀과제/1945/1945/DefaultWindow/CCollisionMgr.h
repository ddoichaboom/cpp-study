#pragma once
#include "CObj.h"

class CCollisionMgr
{
public:
	static bool Collision_Rect(list<CObj*> Dst, list<CObj*> Src);
	static bool Collision_Circle(list<CObj*> Dst, list<CObj*> Src);
};

