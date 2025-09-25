#include "pch.h"
#include "CCollisionMgr.h"

bool CCollisionMgr::Collision_Rect(list<CObj*> Dst, list<CObj*> Src)
{
	RECT	rc{};

	for (auto& Dst : Dst)
	{
		for (auto& Src : Src)
		{
			if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}

	return false;
}
