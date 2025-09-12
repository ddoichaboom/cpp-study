#include "pch.h"

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}


int main()
{
	vector<int>		vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);



	// Vector 반복자 (iterator) - 임의 접근 반복자 
	// +=, -= 허용
	vector<int>::iterator		iter = vecInt.begin();

	//cout << (*iter) << endl;

	// 임의 접근 반복자만 사용 가능한 초기화식
	//vector<int>::iterator		iter = vecInt.begin() + 2;
	
	// 임의 접근 반복자만 사용 가능한 연산식
	//iter += 2;

	//vector<CObj*>::iterator		iter = vecInt.begin();
	// (*iter)->Render();

	// (1) insert(pos, value);
	// - 중간 삽입 함수
	// - pos 위치의 원소 앞에 value를 삽입한다.
	// 삽입한 원소를 가리키게끔 반환값을 저장해야 한다.
	// (예시)
	//iter = vecInt.insert(iter, 999);
	//cout << (*iter) << endl;


	// (+@) erase(first, last);
	// - 구간 [first, last)의 원소들을 모두 삭제
	// 
	// (2) erase(iter);
	// - iter가 가리키는 원소 하나를 삭제한다.
	// - 삭제된 위치 다음 원소를 가리키는 반복자를 반환한다.
	// (예시)
	//iter = vecInt.erase(iter);

	//cout << (*iter) << endl;

	// (3) front() 
	// - 맨 앞의 원소를 가리키는 함수
	// (예시)
	// vecInt.front();
	// vecInt.front() = 100;

	// (4) back()
	// - 맨 뒤의 원소를 가리키는 함수
	// (예시)
	// vecInt.back();
	// vecInt.back()= 500;




	return 0;
}