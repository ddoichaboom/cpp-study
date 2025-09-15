#include "pch.h"
#include "CStudent.h"

CStudent::CStudent()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CStudent::~CStudent()
{

}

void CStudent::Input_Data()
{
	cout << "이름 입력 : ";
	cin >> m_tInfo.cName;

	cout << "국어 성적 입력 : ";
	cin >> m_tInfo.iKor;

	cout << "영어 성적 입력 : ";
	cin >> m_tInfo.iEng;

	cout << "수학 성적 입력 : ";
	cin >> m_tInfo.iMath;

	m_tInfo.iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	m_tInfo.fAver = static_cast<float>(m_tInfo.iTotal) / 3.f;
}

void CStudent::Output_Data()
{
	cout << "------------------------------------" << endl;
	cout << "이름 : " << m_tInfo.cName << endl;
	cout << "국어 : " << m_tInfo.iKor << " 점" << endl;
	cout << "영어 : " << m_tInfo.iEng << " 점" << endl;
	cout << "수학 : " << m_tInfo.iMath << " 점" << endl;
	cout << "총점 : " << m_tInfo.iTotal << " 점" << endl;
	cout << "평균 : " << m_tInfo.fAver << " 점" << endl;
}

