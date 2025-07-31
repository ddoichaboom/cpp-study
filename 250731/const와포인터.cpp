#include <iostream>

using namespace std;

int main()
{
	int iA(10), iB(20);

	int* p = nullptr;    // ������ ���� p�� 'nullptr'�� �ʱ�ȭ

	p = &iA;

	cout << p << endl;
	cout << *p << endl;

	p = &iB;

	cout << p << endl;
	cout << *p << endl;

	int iDst(100), iSrc(200);

	const int* p1 = &iDst;          // �б� ���� ������

	cout << "&iDst : " << &iDst << ", iDst : " << iDst << endl;
	cout << "&iSrc : " << &iSrc << ", iSrc : " << iSrc << endl;

	cout << "p1 : " << p1 << ", *p1 : " << *p1 << endl;

	p1 = &iSrc;                     // ���� ��� ����
	//*p1 = 300;                      // ���� ����� �� ���� ( �Ұ��� )

	cout << "p1 : " << p1 << ", *p1 : " << *p1 << endl;



	int* const p2 = &iSrc;          // ��� ������

	cout << "p2 : " << p2 << ", *p2 : " << *p2 << endl;

	//p2 = &iDst;                     // ���� ��� ���� ( �Ұ��� )
	*p2 = 300;                      // ���� ����� �� ����

	cout << "p2 : " << p2 << ", *p2 : " << *p2 << endl;

	const int* const p3 = &iDst;    // �б� ���� ��� ������

	cout << "p3 : " << p3 << ", *p3 : " << *p3 << endl;

	//p3 = &iSrc;                     // ���� ��� ���� ( �Ұ��� )
	//*p3 = 300;                      // ���� ����� �� ���� ( �Ұ��� )


	return 0;
}