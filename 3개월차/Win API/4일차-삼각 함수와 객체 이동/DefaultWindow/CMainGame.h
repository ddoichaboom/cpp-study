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


// 1. 플레이어 중심을 기준으로 회전하는 위성 객체 만들기(공전)
// 2. 스크류 미사일 구현
// 3. 플레이어를 따라다니는 몬스터 구현하기(역함수를 사용할 것)