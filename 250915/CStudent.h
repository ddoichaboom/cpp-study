#pragma once
#include "Define.h"

class CStudent
{
public:
	CStudent();
	CStudent(const char* pName, int _iKor, int _iEng, int _iMat);
	~CStudent();

public:
	 INFO	Get_Info();

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	//void	Input_Data();
	//void	Output_Data();
	//void	Delete_Data();
	
private:
	INFO	m_tInfo;
};

