#pragma region 5! = ? - Àç±ÍÇÔ¼ö ±¸Çö

#include <iostream>

using namespace std;

int Factorial(int n);

int main()
{
	cout << "----------ÆÑÅä¸®¾ó-----------" << endl;

	cout << "5! = " << Factorial(5) << endl;

	return 0;
}

int Factorial(int n)
{
	if (n == 0)
		return 1;

	return n * Factorial(n - 1);
}

#pragma endregion
