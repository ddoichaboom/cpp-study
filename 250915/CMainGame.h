#pragma once
#include "CStudent.h"
#include "pch.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	enum MENU { ADD = 1, PRINT, SEARCH, DELETE, EXIT };

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	void	Input_Data();
	void	Output_Data();
	void	Search_Data();
	void	Delete_Data();

private:
	vector<CStudent>	m_vStudents;
};

