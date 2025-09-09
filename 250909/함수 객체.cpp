#include "pch.h"

class Add
{
public:
	Add(int b) : base(b) {}

public:
	int operator()(int x) const 
	{
		return base + x;
	}
private:
	int base;
};

int main()
{
	Add	addNum(10);

	// addNum(20) 은 객체의 의미임과 동시에 함수 호출 addNum.operator()(20) 호출
	cout << addNum(20) << endl;			

	cout << addNum(30) << endl;				// addNum.operator()(30);

	return 0;
}