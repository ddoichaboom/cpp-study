#include "pch.h"
#include "CCollisionMgr.h"

void CCollisionMgr::Collision_Circle(list<CObj*> Dst, list<CObj*> Src)
{
	for (auto& Dst : Dst)
	{
		for (auto& Src : Src)
		{
			if (Check_Circle(Dst, Src))
			{
				Dst->OnCollision(Src->Get_ObjID());
				Src->OnCollision(Dst->Get_ObjID());
			}
		}
	}
}

bool CCollisionMgr::Check_Circle(CObj* pDst, CObj* pSrc)
{
	float	fWidth = pDst->Get_Info().vPos.x - pSrc->Get_Info().vPos.x;
	float	fHeight = pDst->Get_Info().vPos.y - pSrc->Get_Info().vPos.y;

	float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = ((pDst->Get_Size() + pSrc->Get_Size()) * 0.5f);

	return fRadius >= fDiagonal;
}
