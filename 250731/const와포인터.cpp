#include <iostream>

using namespace std;

int main()
{
	int iA(10), iB(20);

	int* p = nullptr;    // 포인터 변수 p를 'nullptr'로 초기화

	p = &iA;

	cout << p << endl;
	cout << *p << endl;

	p = &iB;

	cout << p << endl;
	cout << *p << endl;

	int iDst(100), iSrc(200);

	const int* p1 = &iDst;          // 읽기 전용 포인터

	cout << "&iDst : " << &iDst << ", iDst : " << iDst << endl;
	cout << "&iSrc : " << &iSrc << ", iSrc : " << iSrc << endl;

	cout << "p1 : " << p1 << ", *p1 : " << *p1 << endl;

	p1 = &iSrc;                     // 참조 대상 변경
	//*p1 = 300;                      // 참조 대상의 값 변경 ( 불가능 )

	cout << "p1 : " << p1 << ", *p1 : " << *p1 << endl;



	int* const p2 = &iSrc;          // 상수 포인터

	cout << "p2 : " << p2 << ", *p2 : " << *p2 << endl;

	//p2 = &iDst;                     // 참조 대상 변경 ( 불가능 )
	*p2 = 300;                      // 참조 대상의 값 변경

	cout << "p2 : " << p2 << ", *p2 : " << *p2 << endl;

	const int* const p3 = &iDst;    // 읽기 전용 상수 포인터

	cout << "p3 : " << p3 << ", *p3 : " << *p3 << endl;

	//p3 = &iSrc;                     // 참조 대상 변경 ( 불가능 )
	//*p3 = 300;                      // 참조 대상의 값 변경 ( 불가능 )


	return 0;
}