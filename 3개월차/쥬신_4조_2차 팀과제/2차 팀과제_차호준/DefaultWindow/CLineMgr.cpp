#include "pch.h"
#include "CLineMgr.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	LINEPOINT	tLinePoint[8] = 
	{
		{ 0.f, 500.f },			//0
		{ 150.f, 500.f },		//1
		{ 150.f, 500.f },		//2
		{ 300.f, 350.f },		//3
		{ 0.f, 200.f },			//4
		{ 150.f, 200.f },		//5
		{ 150.f, 200.f },		//5
		{ 300.f, 500.f },

	};

	//for (int i = 0; i < size(tLinePoint) / 2; i++)
	//{
	//	m_LineList.push_back(new CLine(tLinePoint[2*i], tLinePoint[2*i+1]));
	//}
	m_LineList.push_back(new CLine(tLinePoint[0], tLinePoint[1]));
	m_LineList.push_back(new CLine(tLinePoint[2], tLinePoint[3]));



}

void CLineMgr::Render(HDC hDC)
{
	for (auto& pLine : m_LineList)
		pLine->Render(hDC);

}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

CLine* CLineMgr::Collision_Line(INFO* m_pInfo)
{
	CLine* pTargetLine = nullptr;

	float  fDistance(0.f);
	float  fDst(0.f);
	float  fSrc(numeric_limits<float>::infinity());

	if (m_LineList.empty())
		return nullptr;

	for (auto& pLine : m_LineList)
	{
		if ((m_pInfo->fX > pLine->Get_Info().tLeft.fX) &&
			(m_pInfo->fX < pLine->Get_Info().tRight.fX) &&
			(pLine->Get_Info().tLeft.fX != pLine->Get_Info().tRight.fX))
		{                         
			if (m_pInfo->fY <= pLine->Get_Info().tfTilt * m_pInfo->fX + pLine->Get_Info().tfYInter)
			{
				fDst = sqrt(
					((pLine->Get_Info().tfTilt * m_pInfo->fX - m_pInfo->fY +
						pLine->Get_Info().tfYInter)
						* (pLine->Get_Info().tfTilt * m_pInfo->fX - m_pInfo->fY +
							pLine->Get_Info().tfYInter))
					/ ((pLine->Get_Info().tfTilt * pLine->Get_Info().tfTilt) + 1));

 				if (fDst < fSrc)
				{
					fSrc = fDst;
					pTargetLine = pLine;
				}
			}
		}
	}

	if (!pTargetLine)
		return nullptr;

	fDistance = sqrt(
		((pTargetLine->Get_Info().tfTilt * m_pInfo->fX - m_pInfo->fY +
			pTargetLine->Get_Info().tfYInter)
			* (pTargetLine->Get_Info().tfTilt * m_pInfo->fX - m_pInfo->fY +
				pTargetLine->Get_Info().tfYInter))
		/ ((pTargetLine->Get_Info().tfTilt * pTargetLine->Get_Info().tfTilt) + 1));

	if (fDistance <= m_pInfo->fCX / 2.f)
	{
		return pTargetLine;
	}
	else
		return nullptr;


	return nullptr;
}
