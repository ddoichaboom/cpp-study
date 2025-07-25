#include <iostream>

using namespace std;

int main() {
	
	cout << sizeof(char) << endl;        // 1 
	cout << sizeof(bool) << endl;        // 1
	cout << sizeof(int) << endl;         // 4
	cout << sizeof(float) << endl;       // 4
	cout << sizeof(long long) << endl;   // 8
	cout << sizeof(double) << endl;      // 8

	char cTmp = 'A';
	char cSrc = 'B';

	cout << sizeof(cTmp + cSrc) << endl;

	return 0;
}