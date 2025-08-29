#include "pch.h"
#include "CStudent.h"


CStudent::CStudent()
{
	m_pInfo = nullptr;
	m_iSize = 0;
}

CStudent::~CStudent()
{
	Release();
}

void CStudent::Initialize()
{
	
}

void CStudent::Update()
{

}

void CStudent::Release()
{
	SAFE_DELETE_ARRAY(m_pInfo);
}

void CStudent::Input_Data()
{
	int iInput(0);

	cout << "추가할 학생은 몇 명 입니까? : ";
	cin >> iInput;

	if (nullptr == m_pInfo)
	{
		m_pInfo = new INFO[iInput];
	}
	else
	{
		INFO* pNewInfo = new INFO[m_iSize + iInput];

		memcpy(pNewInfo, m_pInfo, sizeof(INFO) * m_iSize);

		Release();

		m_pInfo = pNewInfo;
	}

	for (int i = m_iSize; i < m_iSize + iInput; ++i)
	{
		cout << "이름 입력 : ";
		cin >> m_pInfo[i].cName;
		cout << "국어 성적 입력 : ";
		cin >> m_pInfo[i].iKor; 
		cout << "영어 성적 입력 : ";
		cin >> m_pInfo[i].iEng;
		cout << "수학 성적 입력 : ";
		cin >> m_pInfo[i].iMath;

		m_pInfo[i].iTotal = m_pInfo[i].iKor + m_pInfo[i].iEng + m_pInfo[i].iMath;
		m_pInfo[i].fAver = (float)m_pInfo[i].iTotal / 3.f;
	}

	m_iSize += iInput;
}

void CStudent::Output_Data()
{
	for (int i = 0; i < m_iSize; ++i)
	{
		cout << "------------------------------------" << endl;
		cout << "이름 : " << m_pInfo[i].cName << endl;
		cout << "국어 : " << m_pInfo[i].iKor << " 점" << endl;
		cout << "영어 : " << m_pInfo[i].iEng << " 점" << endl;
		cout << "수학 : " << m_pInfo[i].iMath << " 점" << endl;
		cout << "총점 : " << m_pInfo[i].iTotal << " 점" << endl;
		cout << "평균 : " << m_pInfo[i].fAver << " 점" << endl;

	}
}

void CStudent::Search_Data()
{
	char	szFindName[32];

	cout << "찾는 학생의 이름을 입력 : ";
	cin >> szFindName;

	for (int i = 0; i < m_iSize; ++i)
	{
		if (!strcmp(szFindName, m_pInfo[i].cName))
		{
			cout << "------------------------------------" << endl;
			cout << "이름 : " << m_pInfo[i].cName << endl;
			cout << "국어 : " << m_pInfo[i].iKor << " 점" << endl;
			cout << "영어 : " << m_pInfo[i].iEng << " 점" << endl;
			cout << "수학 : " << m_pInfo[i].iMath << " 점" << endl;
			cout << "총점 : " << m_pInfo[i].iTotal << " 점" << endl;
			cout << "평균 : " << m_pInfo[i].fAver << " 점" << endl;
			continue;
		}
	}
}
