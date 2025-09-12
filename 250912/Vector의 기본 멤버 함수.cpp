#include "pch.h"

int main()
{ 
	// vector 객체 생성
	vector<int>		vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	// (1) push_back(v)
	// - 시퀀스 컨테이너들만 소유하고 있다.
	// - 맨 뒤에 원소(v)를 추가한다.
	// (예시)
	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);
	//vecInt.push_back(40);
	//vecInt.push_back(50);

	// (2) size()
	// - 컨테이너 객체 안의 원소의 개수를 반환한다.
	// - 반환 타입이 size_t이다.
	// (예시)
	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}

	// (3) pop_back()
	// - 시퀀스 컨테이너들만 소유한다.
	// - 맨 뒤의 원소를 제거한다.
	// (예시)
	//vecInt.pop_back();

	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}

	// (4) capacity()
	// - 현재 재할당 없이 담을 수 없는 "배열 슬롯 총량"
	// - size() == capacity()가 되면 다음 삽입 시 더 큰 버퍼로 재할당이 발생한다.
	// - size()(원소의 개수)를 n 이라고 했을 때, capacity()(배열의 개수)는 n + n/2와 같다.
	// (예시)
	//cout << vecInt.capacity() << endl;
	//for (int i = 0; i < 20; ++i)
	//{
	//	vecInt.push_back(i);
	//	cout << "사이즈 (원소의 개수) : " << vecInt.size() << "\t카파시티 (배열의 개수) : " << vecInt.capacity() << endl;
	//}

	// (5) clear()
	// - 컨테이너 내의 원소를 모두 제거한다.
	// - Array외 모든 컨테이너가 소유하고 있는 멤버함수이다.
	// (예시)
	//vecInt.clear();
	//cout << "사이즈 (원소의 개수) : " << vecInt.size() << "\t카파시티 (배열의 개수) : " << vecInt.capacity() << endl;

	// (6) swap(other)
	// - 같은 형식의 컨테이끼리 값, 메모리 모두 완전히 교환하는 함수
	// (예시)
	//vector<int>	vecTmp;
	//for (int i = 0; i < 5; ++i)
	//{
	//	vecTmp.push_back((i + 1) * 100);
	//}
	//cout << "사이즈 (원소의 개수) : " << vecTmp.size() << "\t카파시티 (배열의 개수) : " << vecTmp.capacity() << endl;
	//vecTmp.clear();
	//cout << "----------------------- clear -------------------" << endl;
	//vector<int>().swap(vecTmp);			// 임시객체를 이용한 카파시티 해제 방법
	//cout << "사이즈 (원소의 개수) : " << vecTmp.size() << "\t카파시티 (배열의 개수) : " << vecTmp.capacity() << endl;

	// (7) shrink_to_fit()
	// - 원소가 없는 배열을 제거한다.
	// - clear 이후 남는 capacity를 해제
	// (예시)
	//cout << "사이즈 (원소의 개수) : " << vecInt.size() << "\t카파시티 (배열의 개수) : " << vecInt.capacity() << endl;
	//vecInt.clear();
	//cout << "----------------------- clear -------------------" << endl;
	//cout << "사이즈 (원소의 개수) : " << vecInt.size() << "\t카파시티 (배열의 개수) : " << vecInt.capacity() << endl;
	//cout << "----------------------- shrink_to_fit -------------------" << endl;
	//vecInt.shrink_to_fit();
	//cout << "사이즈 (원소의 개수) : " << vecInt.size() << "\t카파시티 (배열의 개수) : " << vecInt.capacity() << endl;





	return 0;
}