#include "pch.h"

class CTest
{
public:
	CTest(const char* pName)
	{
		strcpy_s(m_cName, sizeof(m_cName), pName);
		cout << m_cName << " »ý¼ºÀÚ È£Ãâ" << endl;
	}

	~CTest()
	{
		cout << m_cName << " ¼Ò¸êÀÚ È£Ãâ" << endl;
	}
	
private:
	char	m_cName[32];
};

int main()
{

	CTest	Test("ÀÏ¹Ý °´Ã¼");

	cout << "------------------------ÀÓ½Ã °´Ã¼ »ý¼º-----------------------" << endl;

	CTest("ÀÓ½Ã °´Ã¼");

	cout << "-----------------------ÀÓ½Ã °´Ã¼ ¼Ò¸ê-----------------------" << endl;

	
	return 0;
}