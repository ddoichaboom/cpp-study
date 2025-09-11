#include "pch.h"

template <typename T>
T Func(T Number)
{
	// 템플릿 안에 선언된 static 변수는 같은 자료형 타입의 템플릿 함수들끼리 메모리 공간을 공유한다.
	static T Sum = 0;

	Sum += Number;

	return Sum;
}

template <typename T>
class Box
{
public:
	static int Count;			// 선언
	Box() { Count++; }
};

template <typename T>
int Box<T>::Count = 0;			// 정의

int main()
{
	Func<int>(10);
	Func<float>(1.5f);

	cout << Func<int>(90) << endl;
	cout << Func<float>(1.64f) << endl;

	Box<int> b1, b2;
	Box<double> d1;

	cout << Box<int>::Count << endl;			// int 형끼리 Count 공유
	cout << Box<double>::Count << endl;			// double 형끼리 Count 공유 

	return 0;
}