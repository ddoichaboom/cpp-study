#include "pch.h"

struct tagFinder
{
	tagFinder(const char* pTag) : m_pTag(pTag) {}

	template<typename T>
	bool operator() (T& MyPair)
	{
		return !strcmp(m_pTag, MyPair.first);
	}

	const char* m_pTag;
};

int main()
{
	// default Compare -> less<int> : 오름차순 
	// greater<int> : 내림차순
	map<int, int, greater<int>>		mapInt;


	// 1. pair 객체를 이용한 원소 추가 방법
	pair<int, int>		MyPair;
	MyPair.first	= 1;
	MyPair.second	= 100;

	mapInt.insert(MyPair);

	// 2. pair 임시 객체를 이용한 원소 추가 방법
	mapInt.insert(pair<int, int>(2, 200));

	// 3. make_pair 함수를 이용한 원소 추가 방법
	mapInt.insert(make_pair(3, 300));

	// 4. value_type을 이용한 원소 추가 방법
	map<int, int, greater<int>>::value_type		MyValue(4, 400);

	// first가 const 붙어있는 상태
	// 값 변경 불가능
	//MyValue.first = 5;
	MyValue.second = 444;

	mapInt.insert(MyValue);

	// 5. value_type 임시 객체를 이용한 원소 추가 방법
	mapInt.insert(map<int, int, greater<int>>::value_type(5, 500));

	mapInt.insert(map<int, int, greater<int>>::value_type(5, 555));

	// 6. [ ] 연산자를 이용한 원소 추가 방법
	mapInt[6] = 600;

	if (mapInt[6] != NULL)
		mapInt[6] = 666;

	// 7. 유니폼 초기화를 이용한 원소 추가 방법
	mapInt.insert({ 7, 700 });

	// 8. emplace를 이용한 원소 추가 방법
	mapInt.emplace(8, 800);

	// 현재 mapInt는 <int, int, greater<int>>로 정의되어 있는데,
	// map<int, int>::iterator			iter = mapInt.begin();
	// 위와 같이 선언해서 iter를 사용할 경우 컴파일 오류

	 for (map<int, int>::iterator iter = mapInt.begin();
		 iter != mapInt.end();
		 ++iter)
	 {
		 cout << iter->first << "\t" << iter->second << endl;
	 }

	 //default Compare -> 
	 map<const char*, int>		mapTemp;

	 mapTemp.insert({ "AAA", 10 });
	 mapTemp.insert({ "BBB", 20 });
	 mapTemp.insert({ "CCC", 30 });

	 //map<const char*, int>::iterator		iter = mapTemp.find("AAA");
	 map<const char*, int>::iterator		iter = find_if(mapTemp.begin(), mapTemp.end(), tagFinder("AAA"));
	 
	 if (iter == mapTemp.end())
		 cout << "찾을 수 없음" << endl;

	 else
		 cout << iter->second << endl;

	 // 키 값이 문자 형식일 때,
	 // 알파벳 자동 정렬을 어떻게 수행할까?
	 // 1. 키 값이 단일 문자일 때 : O (아스키 코드 값 기준 정렬)
	 // 2. char*, const char* : x ( 주소값 기준 정렬 )
	 // 3. string일 때 : O ( 알파벳을 기준으로 대소 비교 조건자가 구현되어 삽입 )

	return 0;
}