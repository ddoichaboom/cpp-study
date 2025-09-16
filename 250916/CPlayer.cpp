#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CPlayer::~CPlayer()
{
}

void CPlayer::Select_Job()
{
	int iInput(0);

	cout << "직업을 선택하세요 ( 1. 전사 2. 마법사 3. 도적 ) : ";
	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "전사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iMoney = 10000;
		break;

	case MAGE:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "마법사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "도적");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iMoney = 10000;
		break;

	}
}

void CPlayer::Render()
{
	cout << "---------------------------------------" << endl;
	cout << "직업 : " << m_tInfo.cName << "\t소지금 : " << m_tInfo.iMoney << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}