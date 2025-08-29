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

	cout << "�߰��� �л��� �� �� �Դϱ�? : ";
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
		cout << "�̸� �Է� : ";
		cin >> m_pInfo[i].cName;
		cout << "���� ���� �Է� : ";
		cin >> m_pInfo[i].iKor; 
		cout << "���� ���� �Է� : ";
		cin >> m_pInfo[i].iEng;
		cout << "���� ���� �Է� : ";
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
		cout << "�̸� : " << m_pInfo[i].cName << endl;
		cout << "���� : " << m_pInfo[i].iKor << " ��" << endl;
		cout << "���� : " << m_pInfo[i].iEng << " ��" << endl;
		cout << "���� : " << m_pInfo[i].iMath << " ��" << endl;
		cout << "���� : " << m_pInfo[i].iTotal << " ��" << endl;
		cout << "��� : " << m_pInfo[i].fAver << " ��" << endl;

	}
}

void CStudent::Search_Data()
{
	char	szFindName[32];

	cout << "ã�� �л��� �̸��� �Է� : ";
	cin >> szFindName;

	for (int i = 0; i < m_iSize; ++i)
	{
		if (!strcmp(szFindName, m_pInfo[i].cName))
		{
			cout << "------------------------------------" << endl;
			cout << "�̸� : " << m_pInfo[i].cName << endl;
			cout << "���� : " << m_pInfo[i].iKor << " ��" << endl;
			cout << "���� : " << m_pInfo[i].iEng << " ��" << endl;
			cout << "���� : " << m_pInfo[i].iMath << " ��" << endl;
			cout << "���� : " << m_pInfo[i].iTotal << " ��" << endl;
			cout << "��� : " << m_pInfo[i].fAver << " ��" << endl;
			continue;
		}
	}
}
