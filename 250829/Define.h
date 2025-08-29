#pragma once

#define SAFE_DELETE(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) { delete[] p; p = nullptr; }

typedef struct tagInfo
{
	char cName[32];
	int iKor, iEng, iMath, iTotal;
	float fAver;

}INFO;