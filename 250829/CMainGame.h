#pragma once
#include "CStudent.h"

class CMainGame
{
public:
	CMainGame();			
	~CMainGame();			

public:
	enum NUMBER { ADD = 1, RENDER, SEARCH, END };

public:
	void		Initialize();
	void		Update();
	void		Release();

private:
	CStudent*	m_pStudent;
};

