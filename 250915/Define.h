#pragma once
#include "pch.h"


template <typename T>
void	Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

typedef struct tagInfo
{
	char	cName[12];
	int		iKor, iEng, iMat, iTotal;
	float	fAver;

	tagInfo() : cName{ 0 }, iKor(0), iEng(0), iMat(0), iTotal(0), fAver(0.f) {}

	tagInfo(const char* pName, int _iKor, int _iEng, int _iMat)
		: iKor(_iKor), iEng(_iEng), iMat(_iMat)
	{
		strcpy_s(cName, sizeof(cName), pName);
		iTotal = iKor + iEng + iMat;
		fAver = static_cast<float>(iTotal) / 3.f;
	}
}INFO;