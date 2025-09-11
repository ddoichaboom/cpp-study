#include "pch.h"

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

template <typename T>
T MyMax(T a, T b)
{
	return (a > b) ? a : b;
}

// 함수 템플릿 특수화
template <>
const char* MyMax<const char*>(const char* a, const char* b)
{
	return (strcmp(a, b) > 0 ? a : b);
}

int main()
{
	int		iA(10), iB(30);
	float	fA(1.5f), fB(3.2f);
	char	cA('A'), cB('B');

	//cout << Add(iA, iB) << endl;
	//cout << Add(fA, fB) << endl;

	cout << MyMax(iA, iB) << endl;
	cout << MyMax(fA, fB) << endl;
	cout << MyMax(cA, cB) << endl;
	cout << MyMax("Apple", "Banana") << endl;


	return 0;
}