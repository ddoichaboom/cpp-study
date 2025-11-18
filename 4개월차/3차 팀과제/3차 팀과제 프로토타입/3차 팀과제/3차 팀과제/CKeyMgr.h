#pragma once
#include "Define.h"

class CKeyMgr
{
private:
	CKeyMgr();
	CKeyMgr(const CKeyMgr& rhs) = delete;
	CKeyMgr& operator=(CKeyMgr& rObj) = delete;
	~CKeyMgr();

public:
	bool Key_Pressing(int iKey);
	bool Key_Up(int iKey);
	bool Key_Down(int iKey);
	void Key_Reset();

public:
	void Update();

public:
	static CKeyMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CKeyMgr;
		}

		return m_pInstance;
	}

	static void	Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CKeyMgr* m_pInstance;
	bool m_bKeyState[VK_MAX];

};

