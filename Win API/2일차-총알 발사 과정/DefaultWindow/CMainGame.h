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
	void	Render();
	void	Release();

private:
	HDC		m_hDC;
	CObj* m_pPlayer;

	list<CObj*>	m_BulletList;

};


// 1. 'W', 'A', 'S', 'D' 방향으로 키보드로 나가는 총알 쏘기
// 2. 전체화면보다 100사이즈 작은 사각형을 그리고 사각형 밖으로 나가는 총알 삭제하기
// 3. 사각형 안에서 좌 우로 왔다갔다하는 몬스터 만들기
// 4. 피타고라스의 정리를 읽어올 것