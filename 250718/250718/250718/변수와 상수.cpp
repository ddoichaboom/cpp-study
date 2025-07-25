#include <iostream>

using namespace std;

int main()
{
	// 상수 : 값이 고정된 상태로 변하지 않는 상태의 값, 읽기 전용 데이터
	
	//	- 리터럴 : 일반적인 숫자 상태 (ex) 10, 3.14, 'A'
	//	- 심볼릭 : 프로그래밍 언어, 문법에 의해서 상수로 만들어 놓은 상태 (ex) const

	// 변수 : 코드 진행 또는 흐름에 따라 메모리에 저장된 값을 변경할 수 있는 값

	////////////////////////////////
	//	- 정수 자료형
	//	: short(2), int(4), long(4), long long(8)
	//  : __int16, __int32, __int64;
	//	short sName = 0;						// -32768	~	32767
	//	unsigned short sName = 40000;			// 0	~	65535
	//		- unsigned : 양수만 표현할 때 사용하는 정수 자료형의 키워드
	// int iData;		// 변수 선언
	// int iData(0);	// 변수 선언과 동시에 초기화


	////////////////////////////////////////////
	//	- 실수 자료형
	// : float(4), double(8), long double(8)
	// 
	// float fPi = 3.14f;
	// float fTime = 0.f;
	// 
	// 
	// 
	// //////////////////////////
	//	- 문자 자료형
	//	: char(1) - ASCII 코드 기반 , wchar_t(2) - UNI코드 기반
	// 
	//	char cName = 65;
	// 
	//	cout << cName << endl;
	// 
	//	cName = 'v';
	// 
	//	cout << cName << endl;
	// 
	// 
	// //////////////////////////
	//	- 논리 자료형
	//	: bool(1)
	//	bool	bChoice = 0.1f;		// 값이 들어가 있으므로 
	//	cout << bChoice << endl;	// 1이 출력됨
	//  bChoice = true;
	//	bChoice = false;

	


	cout << sName << endl;

	return 0;
}