#pragma region �Լ� �����ε�

//#include <iostream>
//
//using namespace std;
//
//void Print();                                 //  1��
//
//int Print(int iData);                         //  2�� 
//
//void Print(float fData);                      // 3��
//
//void Print(int iDst, int iSrc);               // 4��
//
//int Print(int iDst, int iSrc, int iTmp);      // 5��
//
//int main()
//{
//
//	Print();                                   // 1��
//	cout << Print(100) << endl;                // 2��
//	Print(3.14f);                              // 3��
//	Print(100, 200);                           // 4��
//	cout << Print(100, 200, 300) << endl;;     // 5��
//
//	return 0;
//}
//
//void Print()
//{
//	cout << "------Print METHOD------" << endl;
//}
//
//int Print(int iData)
//{
//	return iData;
//}
//
//void Print(float fData)
//{
//	cout << "Print " << fData << endl;
//}
//
//void Print(int iDst, int iSrc)
//{
//	cout << "Print " << iDst + iSrc << endl;
//}
//
//int Print(int iDst, int iSrc, int iTmp)
//{
//	return iDst + iSrc + iTmp;
//}
#pragma endregion 

#pragma region default �Ű�����

//#include <iostream>
//
//using namespace std;
//
////// �ʱ�ȭ ���� (�Լ� �����) ////
//void Print(int _iData = 100);
//
//void Output(int iDst, int iSrc, int iTmp = 300);
//
//int main()
//{
//	cout << "-------default �Ű�����-------" << endl;
//
//	Print();
//	Print();
//	Print(200);
//	Print();
//
//	Output(100, 200);
//	Output(100, 200, 400);
//
//	return 0;
//}
//
//void Print(int _iData)
//{
//	cout << _iData << endl;
//}
//
//void Output(int iDst, int iSrc, int iTmp)
//{
//	cout << iDst << " " << iSrc << " " << iTmp << endl;
//}


#pragma endregion

#pragma region ����Լ�
#include <iostream>

using namespace std;

void Recursive(int iCount);

int main()
{
	Recursive(3);

	return 0;
}

void Recursive(int iCount)
{
	// Ż�� ���� //
	if (0 == iCount)
	{
		return;
	}

	cout << "����Լ�" << endl;

	Recursive(--iCount);

}
#pragma endregion