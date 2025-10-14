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
	HDC				m_hDC;
	HBITMAP			m_hBit;
	HDC				m_memDC;

	ULONGLONG		m_currTime;
	ULONGLONG		m_prevTime;
	double			m_deltaTime;
};






// 3. 중재자 패턴(메디에이터) : 상호작용하는 객체들이 서로 복잡한 관계를 맺고 있을 경우 별도의 형식을 정의하여 중재하는 객체를 두는 패턴
// N : 1의 관계를 지향

// 4. 싱글톤 패턴 : 단 하나의 인스턴스(객체)를 생성하여 사용하는 패턴


// 1. 두 점을 지나는 직선의 방정식을 이용하여 선을 타며 이동하는 플레이어 상태를 구현해라
// 2. 스페이스를 눌렀을 때 점프하는 상태를 구현해라(포물선 공식)
