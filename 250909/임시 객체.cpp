#include "pch.h"

class CTest
{
public:
	CTest(const char* pName)
	{
		strcpy_s(m_cName, sizeof(m_cName), pName);
		cout << m_cName << " 생성자 호출" << endl;
	}

	~CTest()
	{
		cout << m_cName << " 소멸자 호출" << endl;
	}
	
private:
	char	m_cName[32];
};

int main()
{

	CTest	Test("일반 객체");				// 이름 있는 객체

	cout << "------------------------임시 객체 생성-----------------------" << endl;

	CTest("임시 객체");						// 이름 없는 임시 객체

	cout << "-----------------------임시 객체 소멸-----------------------" << endl;

	
	return 0;
}