#include "pch.h"

bool	More(int iNumber)
{
	return	iNumber > 30;
}

int main()
{
	list<int>		intlist;

	intlist.push_back(10);
	intlist.push_back(10);
	intlist.push_back(10);
	intlist.push_back(20);
	intlist.push_back(30);
	intlist.push_back(40);
	intlist.push_back(50);

	// remove(value)
	// 매개 변수에 해당하는 노드를 모두 삭제한다.
	// intlist.remove(10);

	// remove_if( 조건 )
	// 조건이 참인 원소를 제거한다.
	// intlist.remove_if(More);

	// unique()
	// 연속적으로 링크된 노드들 중 같은 값을 가진 노드를 제거한다.
	// 맨 앞에 노드 값 하나만 남겨둔다.
	// intlist.unique();

	list<int>			templist;

	templist.push_back(555);
	templist.push_back(333);
	templist.push_back(222);
	templist.push_back(111);
	templist.push_back(444);

	templist.sort();

	// merge(list)
	// 리스트 뒤에 이어 병합한다.
	intlist.merge(templist);


	list<int>::iterator		iter = intlist.begin();

	++iter;
	++iter;

	// splice(반복자, 리스트);
	// 잘라낸 리스트를 원하는 위치로 삽입한다.
	// intlist.splice(iter, templist);

	for (iter = intlist.begin();
		iter != intlist.end();
		++iter)
	{
		cout << (*iter) << endl;
	}

	cout << "----------------------------" << endl;

	// merge로 인해 templist는 비워짐
	for (list<int>::iterator  iter = templist.begin();
		iter != templist.end();
		++iter)
	{
		cout << (*iter) << endl;
	}

	return 0;
}


