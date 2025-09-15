#include "pch.h"
#include "CStudent.h"

CStudent::CStudent()
{ }

CStudent::CStudent(const char* pName, int _iKor, int _iEng, int _iMat)
	: m_tInfo(pName, _iKor, _iEng, _iMat)
{ }


CStudent::~CStudent()
{
}

 INFO	CStudent::Get_Info()
{
	return m_tInfo;
}

void CStudent::Initialize()
{
}

void CStudent::Update()
{
}

void CStudent::Release()
{
}



//void CStudent::Input_Data()
//{
//
//}
//
//void CStudent::Output_Data()
//{
//}
//
//void CStudent::Delete_Data()
//{
//}
