#include "pch.h"

class CShape
{
public:
	virtual void Draw() = 0;		
};

class CCircle : public CShape
{
public:
	void Draw() override { cout << "원을 그린다." << endl; }
};

int main()
{
	CShape* pCircle = new CCircle;

	pCircle->Draw();

	return 0;
}