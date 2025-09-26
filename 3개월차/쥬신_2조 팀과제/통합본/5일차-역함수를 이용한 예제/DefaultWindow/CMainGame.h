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



	TCHAR			m_szFPS[32];
	int				m_iFPS;
	DWORD			m_dwTime;
};

// https://refactoring.guru/ko/design-patterns

// 1. 추상 팩토리 패턴 : 생성 패턴의 한 방법, 객체의 인스턴스를 만드는 방법을 추상화시킴
// 객체 생성 시, 동반되는 공통적인 작업을 추상화 시킨 것

// 2. 반복자 패턴(이터레이터) : 내부 표현 방식을 공개하지 않고 순차적인 접근 방법을 제공하는 패턴

// 3. 중재자 패턴(메디에이터) : 상호작용하는 객체들이 서로 복잡한 관계를 맺고 있을 경우 별도의 형식을 정의하여 중재하는 객체를 두는 패턴
// N : 1의 관계를 지향

// 4. 싱글톤 패턴 : 단 하나의 인스턴스(객체)를 생성하여 사용하는 패턴


// 1. 유도 미사일 구현하기