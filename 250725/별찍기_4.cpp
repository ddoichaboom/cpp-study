#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i < 6; ++i)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			cout << " ";
		}
		for (int k = 0; k < 6 - i; ++k)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}