#include <iostream>

using namespace std;

int main()
{

	//int iTest(100);

	//++iTest;
	//iTest++;

	//++(++iTest);

	//(iTest++)++;		// X,  iTest++�� R-value�̹Ƿ� ������ ����

	//cout << iTest << endl;

	int iDst(0), iSrc(10), iTmp(13), iResult(0);

	iResult = (iDst < iSrc) ? iSrc : iTmp;

	cout << iResult << endl;
	

	return 0;
}