#include "pch.h"

class CAnimal
{
public:
	virtual		void	Speak() { cout << "동물은 소리를 낸다." << endl; }
};

class CDog : public CAnimal
{
public:
	void Speak() override { cout << "강아지는 멍멍" << endl; }
};

class CCat : public CAnimal
{
	void Speak() override { cout << "고양이는 야옹" << endl; }
};

int main()
{
	CAnimal* pDog = new CDog;
	CAnimal* pCat = new CCat;

	pDog->Speak();
	pCat->Speak();

	return 0;
}