#pragma region ������ ���� ���� ��� / &,*�� �ǹ�
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a(10), b(20), c(30);
//	
//	//������ ���� p1, p2, p3 ����
//	int*  p1 = &a;
//	int * p2 = &b;
//	int	*p3 = &c;
//
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p1 = " << *p1 << '\t' << "p1 = " << p1 << endl;
//
//	cout << "b = " << b << '\t' << "&b = " << &b << endl;
//	cout << "*p2 = " << *p2 << '\t' << "p2 = " << p2 << endl;
//
//	cout << "c = " << c << '\t' << "&c = " << &c << endl;
//	cout << "*p3 = " << *p3 << '\t' << "p3 = " << p3 << endl;
//
//
//	return 0;
//}
#pragma endregion


#pragma region �������� / ���� ����
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p = " << *p << '\t' << "p = " << p << endl;
//
//	cout << "-----------���� ����---------------" << endl;
//
//	a = 30;
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p = " << *p << '\t' << "p = " << p << endl;
//
//	cout << "-----------���� ����---------------" << endl;
//
//	*p = 20;
//
//	cout << "a = " << a << '\t' << "&a = " << &a << endl;
//	cout << "*p = " << *p << '\t' << "p = " << p << endl;
//
//
//	return 0;
//}

#pragma endregion


#pragma region �� ���� / ���� ���� ��

//#include <iostream>
//
//using namespace std;
//
//void CallbyV(int x, int y);
//void CallbyR(int* px, int* py);
//
//int main()
//{
//	int iDst(10), iSrc(20);
//	cout << "iDst = " << iDst << '\t' << "iSrc = " << iSrc << endl;
//
//	CallbyV(iDst, iSrc);
//	cout << "iDst = " << iDst << '\t' << "iSrc = " << iSrc << endl;
//
//	CallbyR(&iDst, &iSrc);
//	cout << "iDst = " << iDst << '\t' << "iSrc = " << iSrc << endl;
//
//	return 0;
//}
//
//void CallbyV(int x, int y)
//{
//	int iTmp(0);
//
//	cout << "Call by Value (�� ����) - ���� ���� ������ ����" << endl;
//
//	iTmp = x;
//	x = y;
//	y = iTmp;
//}
//
//void CallbyR(int* px, int* py)
//{
//	int iTmp(0);
//
//	cout << "Call by Reference (���� ����, ������ Ȱ��) - ������ ������ ���� �ִ� �ּҸ� ���� ���� ������ ���� �� ����" << endl;
//
//	iTmp = *px;
//	*px = *py;
//	*py = iTmp;
//}

#pragma endregion



