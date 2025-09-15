#pragma once
#include "CStudent.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	enum MENU { ADD = 1, RENDER, SEARCH, DELETE, EXIT };

public:
	void	Add_Data();
	void	Render_Data();
	void	Search_Data();
	void	Delete_Data();

private:
	vector<CStudent*>	m_vecStu;
};

