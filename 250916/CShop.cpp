#include "pch.h"
#include "CShop.h"

CShop::CShop()
	: m_pCopyPlayer(nullptr)
{}

CShop::~CShop()
{}

void	CShop::Initialize()
{
	for (int i = 0; i < 3; ++i)
	{
		if (i == BEGINNER)
		{
			CObj* pItem = new CItem("ÃÊ±Þ°Ë", 0 , 10, 1000);
			m_vecItem.push_back(pItem);

			CObj* pItem = new CItem("ÃÊ±Þ°©¿Ê", 10, 0, 1000);
			m_vecItem.push_back(pItem);
		}

		if (i == RARE)
		{
			CObj* pItem = new CItem("Áß±Þ°Ë", 0, 20, 2000);
			m_vecItem.push_back(pItem);

			CObj* pItem = new CItem("Áß±Þ¿Ê", 20, 0, 2000);
			m_vecItem.push_back(pItem);
		}

		if (i == UNIQUE)
		{
			CObj* pItem = new CItem("Áß±Þ°Ë", 0, 30, 3000);
			m_vecItem.push_back(pItem);

			CObj* pItem = new CItem("Áß±Þ°©¿Ê", 30, 0, 3000);
			m_vecItem.push_back(pItem);
		}
	}
}

void	CShop::Update()
{

}

void	CShop::Release()
{

}

