#include "pch.h"

class CObj
{
public:
	CObj();
	CObj(int _x, int _y) : m_iX(_x), m_iY(_y) {}

	// 대입 연산자 = 오버로딩
	CObj& operator=(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;

		return *this;
	}

public:
	void Render()
	{
		cout << "m_iX : " << m_iX << "\t" << "m_iY : " << m_iY << endl;
	}

public:
	// 연산자 + 오버로딩
	CObj	operator+(CObj& rSrc)
	{
		CObj	Tmp(m_iX + rSrc.m_iX, m_iY + rSrc.m_iY);
		return Tmp;
	}
	CObj	operator+(int iData)
	{
		CObj	Tmp(m_iX + iData, m_iY + iData);
		return Tmp;
	}

	CObj& operator++()
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}

	CObj operator++(int)
	{
		CObj Tmp(*this);

		m_iX += 1;
		m_iY += 1;

		return Tmp;
	}

private:
	int		m_iX;
	int		m_iY;
};

// 교환 법칙 - 비 멤버 함수이므로 전역 함수로 선언
CObj	operator+(int iData, CObj& rObj)
{
	CObj	Tmp(rObj + iData);
	return Tmp;
}


int main()
{
	CObj		Dst(10, 20);
	CObj		Src(30, 40);

	//CObj		Result = Dst + Src;
	//CObj	Result = Dst + 50;
	//CObj	Result = 50 + Dst;

	//Result.Render();

	//++(++Dst);
	(Dst)++;
	//(Dst++)++;

	Dst.Render();

	return 0;
}


