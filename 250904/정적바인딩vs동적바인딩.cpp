#include "pch.h"

class CBase
{
public:
				void	Print()		{ cout << "CBase::Print()" << endl; }
	virtual		void	VPrint()	{ cout << "CBase::VPrint()" << endl; }
};

class CDerived : public CBase
{
public:
	void	Print()		{ cout << "CDerived::Print()" << endl; }
	void	VPrint()	{ cout << "CDerived::VPrint()" << endl; }
};

int main()
{
	CBase* pDerived = new CDerived;

	pDerived->Print();
	pDerived->VPrint();

	return 0;
}


