#include <iostream>

using namespace std;

void StringSwap(char* pInput, int iSize);

int main()
{
	char cInput[100] = "";
	
	cout << "���ڿ��� �Է��ϼ��� (�ִ� 99��)" << endl;
	cout << "�Է� >> ";

	cin.getline(cInput, sizeof(cInput));

	StringSwap(cInput, size(cInput));
	
	cout << cInput << endl;
	cout << &cInput[0] << endl;

	return 0;
}

void StringSwap(char* pInput, int iSize)
{
	int iLen = 0;

	while ((iLen < iSize) && (pInput[iLen] != '\0'))
	{
		(iLen)++;
	}

	for (int i = 0; i < iLen / 2; ++i)
	{
		swap(pInput[i], pInput[iLen - 1 - i]);
	}
}