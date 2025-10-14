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
	LINEPOINT	tLinePoint[11] = 
	{
		{ 100.f, 500.f},	//0
		{ 200.f, 500.f},	//1
		{ 200.f, 400.f},	//2
		{ 300.f, 400.f},	//3
		{ 300.f, 300.f},	//4
		{ 400.f, 300.f},	//5
		{ 400.f, 200.f},	//6
		{ 500.f, 400.f},	//7
		{700.f, 200.f},		//8
		{700.f, 100.f},		//9
		{400.f, 100.f},		//10
	};

	m_LineList.push_back(new CLine(tLinePoint[0], tLinePoint[1]));
	m_LineList.push_back(new CLine(tLinePoint[1], tLinePoint[2]));
	m_LineList.push_back(new CLine(tLinePoint[2], tLinePoint[3]));
	m_LineList.push_back(new CLine(tLinePoint[3], tLinePoint[5]));
	//m_LineList.push_back(new CLine(tLinePoint[4], tLinePoint[5]));
	//m_LineList.push_back(new CLine(tLinePoint[5], tLinePoint[6]));
	m_LineList.push_back(new CLine(tLinePoint[5], tLinePoint[7]));
	//m_LineList.push_back(new CLine(tLinePoint[7], tLinePoint[8]));
	//m_LineList.push_back(new CLine(tLinePoint[8], tLinePoint[10]));
	//m_LineList.push_back(new CLine(tLinePoint[8], tLinePoint[9]));
	//m_LineList.push_back(new CLine(tLinePoint[9], tLinePoint[10]));


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
		if ((m_pInfo->fX >= pLine->Get_Info().tLeft.fX) &&
			(m_pInfo->fX <= pLine->Get_Info().tRight.fX) &&
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
