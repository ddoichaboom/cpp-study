#include "pch.h"

class CBase
{
public:
	// 비 가상 함수
	void Print() { cout << "CBase::Print()" << endl; }

	// 가상함수
	virtual void Draw() { cout << "CBase::Draw()" << endl; }

	// 순수 가상함수
	virtual void Render() = 0;		

};

class CDerived : public CBase
{
	void	Print()					{ cout << "CDerived::Print()" << endl; }
	void	Draw()		override	{ cout << "CDerived::Draw()" << endl; }
	void	Render()	override	{ cout << "CDerived::Render()" << endl; }
};

class CChild : public CBase
{
	void	Print()					{ cout << "CChild::Print()" << endl; }
	void	Draw()		override	{ cout << "CChild::Draw()" << endl; }
	void	Render()	override	{ cout << "CChild::Render()" << endl; }

};


int main()
{
	CBase* pDerived = new CDerived;
	CBase* pChild	= new CChild;

	cout << "비 가상 함수 호출" << endl;
	pDerived->Print();
	pChild->Print();

	cout << "가상 함수 호출" << endl;
	pDerived->Draw();
	pChild->Draw();

	cout << "순수 가상함수 호출" << endl;
	pDerived->Render();
	pChild->Render();



	return 0;
}