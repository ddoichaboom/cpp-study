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
	int		iInput(0);

	cout << "직업을 선택하세요 (1. 전사 2. 마법사 3. 도적 ) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "전사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;

	case 2:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "마법사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;

	case 3:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "도적");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;
	}
}

void CPlayer::Render()
{
	cout << "------------------------TXT-RPG------------------------" << endl;
	cout << " 직업 : " << m_tInfo.cName << endl;
	cout << " 체력 : " << m_tInfo.iHp << " \t공격력 : " << m_tInfo.iAttack << endl;
}
