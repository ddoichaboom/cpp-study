#pragma once
#include "CObj.h"
#include "ObjectPool.h"

class CCollisionMgr
{
public:
	// TODO : 충돌 처리 추가하려면 추가하고 주석 달아주세용
	static void Collision_Circle(list<CObj*> Dst, list<CObj*> Src);
	static bool Check_Circle(CObj* pDst, CObj* pSrc);

	// 호준 추가
	// 1. PoolObj - PoolObj 간의 충돌
	template<typename T1, typename T2>
	static void Collision_Pool_To_Pool(ObjectPool<T1>& pool1, ObjectPool<T2>& pool2)
	{
		pool1.ForEachActivate([&](T1& obj1)
			{
				if (obj1.Is_Dead() || !obj1.IsInUse())
					return;

				pool2.ForEachActivate([&](T2& obj2)
					{
						if (obj2.Is_Dead() || !obj2.IsInUse())
							return;

						if (Check_Circle(&obj1, &obj2))
						{
							obj1.OnCollision(obj2.Get_ObjID());
							obj2.OnCollision(obj1.Get_ObjID());
						}
					});
			});
	}

	// 호준 추가 
	// 2. List - Pool 간의 충돌
	template<typename T>
	static void Collision_List_To_Pool(const list<CObj*>& ObjList, ObjectPool<T>& pool)
	{
		for (auto& pObj : ObjList)
		{
			if (!pObj || pObj->Is_Dead())
				continue;

			pool.ForEachActivate([&](T& poolObj)
				{
					if (poolObj.Is_Dead() || !poolObj.IsInUse())
						return;

					if (pObj->Is_Dead())
						return;

					if (Check_Circle(pObj, &poolObj))
					{
						pObj->OnCollision(poolObj.Get_ObjID());
						poolObj.OnCollision(pObj->Get_ObjID());
					}
				});
		}
	}
};

