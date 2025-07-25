#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	//int iData(10), iSrc(13);

	//cout << bitset<8>(iData) << endl;
	//cout << bitset<8>(iSrc) << endl;

	//cout << "---------------&---------------" << endl;
	//cout << bitset<8>(iData & iSrc) << endl;
	//cout << (iData & iSrc) << endl;

	//cout << "---------------|---------------" << endl;
	//cout << bitset<8>(iData | iSrc) << endl;
	//cout << (iData | iSrc) << endl;

	//cout << "---------------^---------------" << endl;
	//cout << bitset<8>(iData ^ iSrc) << endl;
	//cout << (iData ^ iSrc) << endl;

	int iDst(10), iSrc(-10);

	cout << bitset<8>(iDst) << endl;
	cout << bitset<8>(iDst << 2) << endl;
	cout << (iDst << 2) << endl;

	cout << bitset<8>(iDst) << endl;
	cout << bitset<8>(iDst >> 3) << endl;
	cout << (iDst >> 3) << endl;

	cout << bitset<8>(iSrc) << endl;
	cout << bitset<8>(iSrc << 2) << endl;
	cout << (iSrc << 2) << endl;

	cout << bitset<8>(iSrc) << endl;
	cout << bitset<8>(iSrc >> 3) << endl;
	cout << (iSrc >> 3) << endl;



	return 0;
}