#pragma once

template <typename T>
void Safe_Delete(T& p)
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
	int		iKor, iEng, iMath, iTotal;
	float	fAver;
}INFO;