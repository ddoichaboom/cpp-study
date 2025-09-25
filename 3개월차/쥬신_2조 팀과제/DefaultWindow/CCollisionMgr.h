#pragma once

#include "CObj.h"

class CCollisionMgr
{
public:
	static bool Collision_Rect(list<CObj*>  Dst, list<CObj*> Src);
	//static bool Collision_Bullet(list<CObj*> Dst, list<RECT*> Src);
	//static bool Collision_Monster(list<CObj*> Dst, list<RECT*> Src);
};

