#include <iostream>
#include <bitset>

using namespace std;

int main()
{

	int iDia(1), iRub(2), iSap(4);
	int iA(3), iB(7), iC(0), iD(1);

	// A~B�� ����ǰ
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

	cout << "---------���̾� ���� �˻�---------" << endl;
	cout << bitset<8>(iA & iDia) << endl;
	cout << bitset<8>(iB & iDia) << endl;
	cout << bitset<8>(iC & iDia) << endl;
	cout << bitset<8>(iD & iDia) << endl;

	cout << "---------��� ���� �˻�---------" << endl;
	cout << bitset<8>(iA & iRub) << endl;
	cout << bitset<8>(iB & iRub) << endl;
	cout << bitset<8>(iC & iRub) << endl;
	cout << bitset<8>(iD & iRub) << endl;

	cout << "---------�����̾� ���� �˻�---------" << endl;
	cout << bitset<8>(iA & iSap) << endl;
	cout << bitset<8>(iB & iSap) << endl;
	cout << bitset<8>(iC & iSap) << endl;
	cout << bitset<8>(iD & iSap) << endl;

	cout << "---------���̾� ����----------" << endl;
	cout << bitset<8>(iC | iDia) << endl;

	cout << "---------��� ����----------" << endl;
	cout << bitset<8>(iC | iRub) << endl;

	cout << "---------�����̾� ����----------" << endl;
	cout << bitset<8>(iC | iSap) << endl;

	cout << "---------���̾� �Ǹ�----------" << endl;
	cout << bitset<8>(iB ^ iDia) << endl;

	cout << "---------��� �Ǹ�----------" << endl;
	cout << bitset<8>(iB ^ iRub) << endl;

	cout << "---------�����̾� �Ǹ�----------" << endl;
	cout << bitset<8>(iB ^ iSap) << endl;


	return 0;
}