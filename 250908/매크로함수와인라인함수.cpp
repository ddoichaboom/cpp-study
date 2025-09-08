#include "pch.h"

// 매크로 함수
// 전처리기 지시자 : #define
#define		SQUARE(x) (x * x)

// 인라인 함수
// 일반 함수에 비해 동작 속도 빠른 편
inline int iSQUARE(int x)
{
	return x * x;
}

int main()
{
	int iNum = 4;
	cout << SQUARE(iNum) << endl;

	cout << iSQUARE(iNum) << endl;



	return 0;
}