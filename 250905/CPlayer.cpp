#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	m_iCurEx = 0;
	m_iMaxEx = 10;
}

CPlayer::~CPlayer()
{

}

void CPlayer::Set_CurEx(int iDrpEx)
{
	m_iCurEx += iDrpEx;
}

void CPlayer::Set_MaxEx(int iMaxEx)
{
	m_iMaxEx += iMaxEx;
}

void CPlayer::Set_Hp(int iMaxHp)
{
	m_tInfo.iHp = iMaxHp;
}

void CPlayer::Level_Up(int iDrpEx)
{
	int iRemainEx = m_iCurEx + iDrpEx - m_iMaxEx;
	m_tInfo.iLv++;
	m_tInfo.iAttack += 2;
	m_tInfo.iMaxHp += 20;
	m_tInfo.iHp = m_tInfo.iMaxHp;
	m_iMaxEx += 10;
	m_iCurEx = iRemainEx;

}

void CPlayer::Select_Job()
{
	int iInput(0);
	cout << "--------------------------------TXT-RPG--------------------------------\n" << endl;
	cout << "\t\t\t\t < 상세 설명 >\n" << endl;
	cout << "\t\t <1>  전사 \t- (체력 : 150 / 공격력 : 10 )" << endl;
	cout << "\t\t <2>  마법사 \t- (체력 : 100 / 공격력 : 14 )" << endl;
	cout << "\t\t <3>  도적 \t- (체력 : 120 / 공격력 : 12 )\n\n" << endl;

	cout << "직업을 선택하세요 (1. 전사 2. 마법사 3. 도적 ) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "전사");
		m_tInfo.iLv = 1;
		m_tInfo.iMaxHp = 150;
		m_tInfo.iHp = 150;
		m_tInfo.iAttack = 10;
		break;

	case 2:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "마법사");
		m_tInfo.iLv = 1;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 14;
		break;

	case 3:
		strcpy_s(m_tInfo.cName, sizeof(m_tInfo.cName), "도적");
		m_tInfo.iLv = 1;
		m_tInfo.iMaxHp = 120;
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 12;
		break;

	}
}

void CPlayer::Render()
{
	int iBarLen = 10;
	int iPHp = (m_tInfo.iHp * iBarLen) / m_tInfo.iMaxHp;
	int iPEx = (m_iCurEx * iBarLen) / m_iMaxEx;

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "<플레이어>\t\t\t" << "직업 \t: " << m_tInfo.cName << endl;
	//cout << "\t\t\t\t\t < 플레이어 >" << endl;
	//cout << "직업 \t: " << m_tInfo.cName << "\t\t\t\t"  << "소지금 \t: " << m_iMoney << " 원"<< endl;
	cout << "채력 \t: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << " | ";
	for (int i = 0; i < iPHp; ++i)
	{
		cout << "# ";
	}
	for (int i = iPHp; i < iBarLen; ++i)
	{
		cout << "- ";
	}
	cout << "\n레벨 \t: " << m_tInfo.iLv << "\t\t\t\t" << "공격력 \t: " << m_tInfo.iAttack << endl;
	cout << "경험치 \t: " << m_iCurEx << " / " << m_iMaxEx << " | ";
	for (int i = 0; i < iPEx; ++i)
	{
		cout << "# ";
	}
	for (int i = iPEx; i < iBarLen; ++i)
	{
		cout << "- ";
	}

	cout << endl;
}
