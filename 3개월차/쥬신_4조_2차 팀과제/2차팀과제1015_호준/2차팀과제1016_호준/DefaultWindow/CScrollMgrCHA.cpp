#include "pch.h"
#include "CScrollMgrCHA.h"

CScrollMgrCHA* CScrollMgrCHA::m_pInstance = nullptr;

CScrollMgrCHA::CScrollMgrCHA() 
	: m_fScrollX(0.f), m_fScrollY(0.f)
{
}

CScrollMgrCHA::~CScrollMgrCHA()
{
}

void CScrollMgrCHA::Scroll_Lock()
{
	if (0.f < m_fScrollX)
		m_fScrollX = 0.f;

	if (0.f < m_fScrollY)
		m_fScrollY = 0.f;

	if (WINCX - 1920 > m_fScrollX)
		m_fScrollX = WINCX - 1920;

	if (WINCY - 1250 > m_fScrollY)
		m_fScrollY = WINCY - 1250;

}
