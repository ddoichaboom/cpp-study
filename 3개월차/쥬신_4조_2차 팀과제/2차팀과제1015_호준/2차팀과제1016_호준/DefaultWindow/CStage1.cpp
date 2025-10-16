#include "pch.h"
#include "CStage1.h"
#include "CAbstractFactory.h"
#include "CMonster.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"
#include <ctime>
#include "CKeyMgr.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"
#include "CLineMgrCHA.h"
#include "CPlayerCHA.h"
#include "CScrollMgrCHA.h"
#include "CMouseCHA.h"

CStage1::CStage1()
	: m_currTime(GetTickCount64()), m_prevTime(m_currTime), m_deltaTime(0)
{
}

CStage1::~CStage1()
{
	Release();
}

void CStage1::Initialize()
{

	// 플레이어 생성
	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayerCHA>::Create_Obj());

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Floor_3.bmp", L"Ground");

	// 마우스 생성
	CObjMgr::Get_Instance()->Add_Object(MOUSE, CAbstractFactory<CMouseCHA>::Create_Obj());

	CLineMgrCHA::Get_Instance()->Initialize();
}

void CStage1::Update()
{
	m_currTime = GetTickCount64();
	m_deltaTime = (float)(m_currTime - m_prevTime) / 1000.0;

	CObjMgr::Get_Instance()->Update(m_deltaTime);

	CLineMgrCHA::Get_Instance()->Update();
	
}

void CStage1::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update(m_deltaTime);

	CObjMgr::Get_Instance()->Check_hit(PLAYERBULLET, MONSTER, CObjMgr::CIRCLE);
	CObjMgr::Get_Instance()->Check_hit(MONSTERBULLET, PLAYER, CObjMgr::CIRCLE);
	CObjMgr::Get_Instance()->Check_hit(MONSTER, PLAYER, CObjMgr::RECT);


	CLineMgrCHA::Get_Instance()->Late_Update();


	m_prevTime = m_currTime;
}

void CStage1::Render(HDC hDC)
{

	int		iScrollX = CScrollMgrCHA::Get_Instance()->Get_ScrollX();
	int		iScrollY = CScrollMgrCHA::Get_Instance()->Get_ScrollY();

	// 에디터 모드 쓰고 싶다면 라인 매니저 코드를 BitBlt보다 아래에 둘것 
	CLineMgrCHA::Get_Instance()->Render(hDC);

	HDC     hGroundDC = CBmpMgr::Get_Instance()->Find_Image(L"Ground");

	BitBlt(hDC, iScrollX, iScrollY, 1920, 1250, hGroundDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage1::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(PLAYER);
}
