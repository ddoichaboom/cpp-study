#include <iostream>

using namespace std;

int main()
{
	int iData(10);
	int* p = &iData;          // ���� iData�� ��ǥ �ּҰ��� ������ p�� ����

	cout << (p) << endl;      // iData�� ��ǥ �ּҰ� ��� 
	cout << (&p) << endl;     // ������ p�� ��ǥ �ּҰ� ��� 

	int** pp = &p;            // ������ p�� ��ǥ �ּҸ� ���� ������ pp�� ����

	cout << pp << endl;       // ������ p�� ��ǥ �ּҰ�
	cout << *pp << endl;      // iData�� ��ǥ �ּҰ�
	cout << **pp << endl;     // iData�� ����Ǿ� �ִ� ��

	return 0;
}