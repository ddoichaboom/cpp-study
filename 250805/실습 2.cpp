#include <iostream>

using namespace std;

void GetLength(char* pArr, int iSize, int* pLen);

int main()
{
	int iLen(0);
	char cArr[100] = "";
	
	cout << "���ڿ��� �Է��ϼ���" << endl;
	cout << "�Է� >> ";
	cin.getline(cArr, size(cArr));

	GetLength(cArr, size(cArr), &iLen);

	cout << cArr << "�� ���� : " << iLen << endl;

	return 0;
}

void GetLength(char* pArr, int iSize, int* pLen)
{
	*pLen = 0;

	while ((*pLen < iSize) && (pArr[*pLen] != '\0'))
	{
		(*pLen)++;
	}
	
}