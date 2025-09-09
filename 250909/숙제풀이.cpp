#include "pch.h"
#include "CMyString.h"

int main()
{
	CMyString		Temp("JUSHIN");		

	cout << Temp.Get_String() << endl;
	
	CMyString		Src;

	//Src = Temp;						// CMyString::operator=(CMyString& rString)이 존재해야 가능
	Src = "ACADEMY";					// CMyString::operator=(const char* pString)

	cout << Src.Get_String() << endl;

	CMyString		Dst;
	Dst = Temp + " ";			

	// (1) CMyString::operator+(const char* pString)
	// (1)의 결과로 Result가 반환되는데 이는 임시 객체로 CMyString&&가 rvalue를 매개변수로 받는다. 
	// (2) CMyString::operator=(CMyString&& rString)

	cout << Dst.Get_String() << endl;

	Temp = Dst + Src;
	// (1) CMyString::operator+(CMyString& rString) 호출
	// 임시 객체 반환 
	// (2) CMyString::operator=(CMyString&& rString) 호출

	cout << Temp.Get_String() << endl;

	Dst = Dst + "academy";
	// (1) CMyString::operator+(const char* pString) 호출
	// 결과로 임시객체 반환 
	// (2) CMyString::operator=(CMyString&& rString) 호출

	cout << Dst.Get_String() << endl;


	return 0;
}
