#include <iostream>

using namespace std;

int main()
{
	int iData(10);
	int* p = &iData;          // 변수 iData의 대표 주소값을 포인터 p에 저장

	cout << (p) << endl;      // iData의 대표 주소값 출력 
	cout << (&p) << endl;     // 포인터 p의 대표 주소값 출력 

	int** pp = &p;            // 포인터 p의 대표 주소를 이중 포인터 pp에 저장

	cout << pp << endl;       // 포인터 p의 대표 주소값
	cout << *pp << endl;      // iData의 대표 주소값
	cout << **pp << endl;     // iData에 저장되어 있는 값

	return 0;
}