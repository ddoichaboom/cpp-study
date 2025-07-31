#include <iostream>

using namespace std;

int main()
{
	const int iNum = 3;

	int iArray[iNum] = { 1, 2, 3 };

	cout << sizeof(iArray) << endl;

	//  for(int i = 0; i < sizeof(iArray) / sizeof(int); ++i)

	for (int i = 0; i < size(iArray) ; ++i)
	{
		cout << iArray[i] << endl;
	}

	for (int i : iArray)
	{
		cout << i << endl;
	}

	cout << iArray[1 + 1] << endl;
	cout << iArray[0] + iArray[1] << endl;

	cout << iArray[0] << endl;
	cout << iArray[1] << endl;
	cout << iArray[2] << endl;

	return 0;
}