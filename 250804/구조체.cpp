#include <iostream>

using namespace std;

struct School
{
	char cName[10];
	char cSex[8];
	int iAge;
};

int main()
{
	School s1 = { "호준", "남자", 27 };
	School s2 = { "지수", "여자", 28 };

	School* p1 = &s1;
	School* p2 = &s2;

	School* pStudent[2] = { &s1, &s2 };

	cout << &s1 << endl;
	cout << p1 << endl;
	cout << s1.cName << endl;
	cout << (*p1).cName << endl;
	cout << p1->cName << endl;
	cout << pStudent[0]->cName;

	return 0;
}