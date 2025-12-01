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

bool CCollisionMgr::Collision_Circle(list<CObj*> Dst, list<CObj*> Src)
{
	for (auto& Dst : Dst)
	{
		for (auto& Src : Src)
		{
			if (pow((Src->Get_Info().fX - Dst->Get_Info().fX), 2) +
				pow((Src->Get_Info().fY - Dst->Get_Info().fY), 2) 
				<= pow((Src->Get_Info().fCX / 2 + Dst->Get_Info().fCX / 2), 2))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
	return false;

}
