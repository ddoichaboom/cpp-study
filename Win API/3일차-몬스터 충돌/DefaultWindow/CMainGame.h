#pragma once

#include "Define.h"
#include "CPlayer.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();

private:
	HDC		m_hDC;

	//CObj* m_pPlayer;
	//list<CObj*>	m_BulletList;

	list<CObj*>		m_ObjList[OBJ_END];

	TCHAR			m_szFPS[32];
	int				m_iFPS;
	DWORD			m_dwTime;
};

// https://refactoring.guru/ko/design-patterns

// 1. 추상 팩토리 패턴 : 생성 패턴의 한 방법, 객체의 인스턴스를 만드는 방법을 추상화시킴
// 객체 생성 시, 동반되는 공통적인 작업을 추상화 시킨 것

// 2. 반복자 패턴(이터레이터) : 내부 표현 방식을 공개하지 않고 순차적인 접근 방법을 제공하는 패턴


// 1. 원충돌을 구현하라
// 2. 삼각함수를 이용하여 탱크 포신을 회전시켜라
// 3. 탱크의 포신이 바라보는 방향으로 이동시켜라
// 4. 포신이 바라보는 방향으로 총알을 쏴라