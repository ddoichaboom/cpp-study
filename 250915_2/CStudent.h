#pragma once
#include "Define.h"

class CStudent
{
public:
	CStudent();
	~CStudent();

public:
	const INFO& Get_Info()	const { return m_tInfo; }
	
public:
	void	Input_Data();
	void	Output_Data();


private:
	INFO	m_tInfo;
};

