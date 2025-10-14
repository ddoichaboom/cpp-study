#pragma once

#include "CObj.h"
#include "CLine.h"
#include "CLineMgr.h"

class CCollisionMgr
{
public:
	static void	Collision_Rect(list<CObj*> Dst, list<CObj*> Src);

	static void	Collision_RectEx(list<CObj*> Dst, list<CObj*> Src);
	static bool Check_Rect(CObj* pDst, CObj* pSrc, float* pWidth, float* pHeight);

	static void	Collision_Circle(list<CObj*> Dst, list<CObj*> Src);
	static bool Check_Circle(CObj* pDst, CObj* pSrc);
	//static bool Collision_Line(list<CLine*> Dst, list<CObj*> Src);
	static bool Line_Movement(list<CLine*> Dst, list<CObj*> Src);

};

