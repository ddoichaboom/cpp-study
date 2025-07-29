#pragma region 포인터 변수 선언 방법 / &,*의 의미
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a(10), b(20), c(30);
//	
//	//포인터 변수 p1, p2, p3 선언
//	int*  p1 = &a;
//	int * p2 = &b;
//	int	*p3 = &c;
//
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p1 = " << *p1 << '\t' << "p1 = " << p1 << endl;
//
//	cout << "b = " << b << '\t' << "&b = " << &b << endl;
//	cout << "*p2 = " << *p2 << '\t' << "p2 = " << p2 << endl;
//
//	cout << "c = " << c << '\t' << "&c = " << &c << endl;
//	cout << "*p3 = " << *p3 << '\t' << "p3 = " << p3 << endl;
//
//
//	return 0;
//}
#pragma endregion


#pragma region 직접참조 / 간접 참조
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p = " << *p << '\t' << "p = " << p << endl;
//
//	cout << "-----------직접 참조---------------" << endl;
//
//	a = 30;
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p = " << *p << '\t' << "p = " << p << endl;
//
//	cout << "-----------간접 참조---------------" << endl;
//
//	*p = 20;
//
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p = " << *p << '\t' << "p = " << p << endl;
//
//
//	return 0;
//}

#pragma endregion


#pragma region 값 전달 / 참조 전달 비교

//#include <iostream>
//
//using namespace std;
//
//void CallbyV(int x, int y);
//void CallbyR(int* px, int* py);
//
//int main()
//{
//	int iDst(10), iSrc(20);
//	cout << "iDst = " << iDst << '\t' << "iSrc = " << iSrc << endl;
//
//	CallbyV(iDst, iSrc);
//	cout << "iDst = " << iDst << '\t' << "iSrc = " << iSrc << endl;
//
//	CallbyR(&iDst, &iSrc);
//	cout << "iDst = " << iDst << '\t' << "iSrc = " << iSrc << endl;
//
//	return 0;
//}
//
//void CallbyV(int x, int y)
//{
//	int iTmp(0);
//
//	cout << "Call by Value (값 전달) - 원본 값은 변하지 않음" << endl;
//
//	iTmp = x;
//	x = y;
//	y = iTmp;
//}
//
//void CallbyR(int* px, int* py)
//{
//	int iTmp(0);
//
//	cout << "Call by Reference (참조 전달, 포인터 활용) - 포인터 변수가 갖고 있는 주소를 통해 간접 참조로 원본 값 수정" << endl;
//
//	iTmp = *px;
//	*px = *py;
//	*py = iTmp;
//}

#pragma endregion



