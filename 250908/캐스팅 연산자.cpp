#include "pch.h"

class CBase
{
public:
	virtual void Render() { cout << "CBase::Render()" << endl; }

};

class CDerived : public CBase
{
public:
	void Render() override { cout << "CDerived::Render()" << endl; }

public:
	void Print() { cout << "Only in CDerived Class" << endl; }
};

int main()
{
	// static_cast
	// 정적 캐스팅 연산자
	//int iData	= (int)3.14f;
	//int iData2	= static_cast<int>(3.14f);

	//cout << iData  << endl;
	//cout << iData2 << endl;

	// dynamic_cast
	//// 동적 캐스팅 연산자
	//CBase* pDerived = new CDerived;
	////pDerived->Print();									// 컴파일 에러 
	//dynamic_cast<CDerived*>(pDerived)->Print();					

	// const_cast 
	// const 성격을 벗겨내는 캐스팅 연산자
	//int			iNumber		= 100;
	//const int*	p1			= &iNumber;
	////*p1 = 200;											// const로 인해 참조하는 대상의 값 변경 불가
	//int*		p2			= const_cast<int*>(p1);
	//*p2 = 300;
	//cout << iNumber << endl;

	// reinterpret_cast
	// const가 붙은 포인터를 제외한 모든 포인터의 형 변환을 허용
	//int iNumber = 65;
	//char* pStr = reinterpret_cast<char*>(&iNumber);
	//cout << *pStr << endl;



	return 0;
}