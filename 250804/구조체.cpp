#include <iostream>

using namespace std;

struct School
{
	char cName[10];
	int iAge;
	char cSex[8];
};

int main()
{
	School s1 = { "호준", 27, "남자" };
	School s2 = { "지수", 28, "여자" };

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