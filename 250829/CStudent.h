#pragma once
#include "Define.h"

class CStudent
{
public:
	CStudent();
	~CStudent();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void Input_Data();
	void Output_Data();
	void Search_Data();

private:
	INFO*	m_pInfo;
	int		m_iSize;
};

