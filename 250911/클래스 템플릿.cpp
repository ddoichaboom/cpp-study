#include "pch.h"

template <typename T>
class CMyBox
{
public:
	CMyBox(T val)
		: m_data(val) { }
	~CMyBox() { };

	T Get() { return m_data; }

private:
	T m_data;
};

template <>
class CMyBox<char*>
{
public:
	CMyBox(const char* val) : m_data(val) {}

public:
	void Print() { cout << "¹®ÀÚ¿­ : " << m_data << endl; }

private:
	const char*	m_data;
};

int main()
{
	CMyBox<char>	myBox('A');
	cout << myBox.Get() << endl;

	//CMyBox<string>	strBox("Jushin");
	//cout << strBox.Get() << endl;

	CMyBox<char*>	strBox("Jushin");
	strBox.Print();


	return 0;
}