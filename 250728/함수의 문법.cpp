#pragma region 함수 오버로딩

//#include <iostream>
//
//using namespace std;
//
//void Print();                                 //  1번
//
//int Print(int iData);                         //  2번 
//
//void Print(float fData);                      // 3번
//
//void Print(int iDst, int iSrc);               // 4번
//
//int Print(int iDst, int iSrc, int iTmp);      // 5번
//
//int main()
//{
//
//	Print();                                   // 1번
//	cout << Print(100) << endl;                // 2번
//	Print(3.14f);                              // 3번
//	Print(100, 200);                           // 4번
//	cout << Print(100, 200, 300) << endl;;     // 5번
//
//	return 0;
//}
//
//void Print()
//{
//	cout << "------Print METHOD------" << endl;
//}
//
//int Print(int iData)
//{
//	return iData;
//}
//
//void Print(float fData)
//{
//	cout << "Print " << fData << endl;
//}
//
//void Print(int iDst, int iSrc)
//{
//	cout << "Print " << iDst + iSrc << endl;
//}
//
//int Print(int iDst, int iSrc, int iTmp)
//{
//	return iDst + iSrc + iTmp;
//}
#pragma endregion 

#pragma region default 매개변수

//#include <iostream>
//
//using namespace std;
//
////// 초기화 문법 (함수 선언식) ////
//void Print(int _iData = 100);
//
//void Output(int iDst, int iSrc, int iTmp = 300);
//
//int main()
//{
//	cout << "-------default 매개변수-------" << endl;
//
//	Print();
//	Print();
//	Print(200);
//	Print();
//
//	Output(100, 200);
//	Output(100, 200, 400);
//
//	return 0;
//}
//
//void Print(int _iData)
//{
//	cout << _iData << endl;
//}
//
//void Output(int iDst, int iSrc, int iTmp)
//{
//	cout << iDst << " " << iSrc << " " << iTmp << endl;
//}


#pragma endregion

#pragma region 재귀함수
#include <iostream>

using namespace std;

void Recursive(int iCount);

int main()
{
	Recursive(3);

	return 0;
}

void Recursive(int iCount)
{
	// 탈출 조건 //
	if (0 == iCount)
	{
		return;
	}

	cout << "재귀함수" << endl;

	Recursive(--iCount);

}
#pragma endregion