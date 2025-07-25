#include <iostream>
#include <bitset>

using namespace std;

int main()
{

	int iDia(1), iRub(2), iSap(4);
	int iA(3), iB(7), iC(0), iD(1);

	// A~B의 소지품
	// A (Diamond + Ruby)
	// B (Diamond + Ruby + Sapphire)
	// C (empty)
	// D (Diamond)

	cout << bitset<8>(iDia) << endl;
	cout << bitset<8>(iRub) << endl;
	cout << bitset<8>(iSap) << endl;
	cout << bitset<8>(iA) << endl;
	cout << bitset<8>(iB) << endl;
	cout << bitset<8>(iC) << endl;
	cout << bitset<8>(iD) << endl;

	cout << "---------다이아 소유 검사---------" << endl;
	cout << bitset<8>(iA & iDia) << endl;
	cout << bitset<8>(iB & iDia) << endl;
	cout << bitset<8>(iC & iDia) << endl;
	cout << bitset<8>(iD & iDia) << endl;

	cout << "---------루비 소유 검사---------" << endl;
	cout << bitset<8>(iA & iRub) << endl;
	cout << bitset<8>(iB & iRub) << endl;
	cout << bitset<8>(iC & iRub) << endl;
	cout << bitset<8>(iD & iRub) << endl;

	cout << "---------사파이어 소유 검사---------" << endl;
	cout << bitset<8>(iA & iSap) << endl;
	cout << bitset<8>(iB & iSap) << endl;
	cout << bitset<8>(iC & iSap) << endl;
	cout << bitset<8>(iD & iSap) << endl;

	cout << "---------다이아 구매----------" << endl;
	cout << bitset<8>(iC | iDia) << endl;

	cout << "---------루비 구매----------" << endl;
	cout << bitset<8>(iC | iRub) << endl;

	cout << "---------사파이어 구매----------" << endl;
	cout << bitset<8>(iC | iSap) << endl;

	cout << "---------다이아 판매----------" << endl;
	cout << bitset<8>(iB ^ iDia) << endl;

	cout << "---------루비 판매----------" << endl;
	cout << bitset<8>(iB ^ iRub) << endl;

	cout << "---------사파이어 판매----------" << endl;
	cout << bitset<8>(iB ^ iSap) << endl;


	return 0;
}