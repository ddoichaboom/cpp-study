#include "pch.h"
#include "CMyString.h"

void	CMyString::Render()
{

}

CMyString::CMyString()
	:m_iSize(0), m_pString(nullptr)
{
}

CMyString::CMyString(const char* pString)
{
	m_iSize = (int)strlen(pString);
	m_pString = new char[m_iSize + 1];
	strcpy_s(m_pString, m_iSize + 1, pString);
}

CMyString::CMyString(const CMyString& rhs)
	: m_iSize(rhs.m_iSize)
{
	m_pString = new char[m_iSize + 1];
	strcpy_s(m_pString, m_iSize + 1, rhs.m_pString);
}

CMyString::~CMyString()
{
	Release();
}


CMyString& CMyString::operator=(CMyString&& rString)
{
	Release();

	m_iSize = (int)strlen(rString.m_pString);
	m_pString = new char [m_iSize + 1];
	strcpy_s(m_pString, m_iSize + 1, rString.m_pString);

	return *this;
}	


CMyString& CMyString::operator=(const char* pString)
{
	Release();

	m_iSize = (int)strlen(pString);

	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, pString);

	return *this;

}

CMyString	CMyString::operator+(CMyString& rString)
{
	char* pStr = new char[m_iSize + strlen(rString.m_pString) + 1];
	//char* pStr = new char[m_iSize + rString.m_iSize + 1];

	strcpy_s(pStr, m_iSize + strlen(rString.m_pString) + 1, m_pString);
	strcat_s(pStr, m_iSize + strlen(rString.m_pString) + 1, rString.m_pString);

	CMyString	Result(pStr);

	SAFE_DELETE_ARRAY(pStr);

	return Result;
}

CMyString	CMyString::operator+(const char* pString)
{
	char* pStr = new char[m_iSize + strlen(pString) + 1];

	strcpy_s(pStr, m_iSize + strlen(pString) + 1, m_pString);
	strcat_s(pStr, m_iSize + strlen(pString) + 1, pString);

	CMyString	Result(pStr);

	SAFE_DELETE_ARRAY(pStr);

	return Result;
}

bool		CMyString::operator==(CMyString& rString)
{
	return !strcmp(m_pString, rString.m_pString);
}

bool		CMyString::operator==(const char* pString)
{
	return !strcmp(m_pString, pString);
}

void CMyString::Release(void)
{
	SAFE_DELETE_ARRAY(m_pString);
}