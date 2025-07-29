#include <iostream>

using namespace std;

void GetMoney(int* pMoney);
void Dispenser(int _iCoke, int _iCider, int _iFanta, int _iMoney);
void Reset();
void GetChoice(int* pNum);
void GetProduct(int _iCoke, int _iCider, int _iFanta, int _iNum, int* pMoney, bool* pChoice);

int main()
{
	int iCoke(100), iCider(200), iFanta(300), iMoney(0), iNum(0), iChange(0);
	bool bChoice(true);

	GetMoney(&iMoney);

	while (bChoice && (iMoney >= 100))
	{
		system("cls");

		Dispenser(iCoke, iCider, iFanta, iMoney);
		GetChoice(&iNum);
		GetProduct(iCoke, iCider, iFanta, iNum, &iMoney, &bChoice);

		system("pause");
	}

	if (bChoice && (iMoney < 100))
	{
		cout << "소지금이 부족하여 자판기를 이용하실 수 없습니다." << endl;
	}
	

	return 0;
}

void GetMoney(int* pMoney)
{
	cout << "소지금을 입력하세요 : ";
	cin >> *pMoney;

	Reset();
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void Dispenser(int _iCoke, int _iCider, int _iFanta, int _iMoney)
{
	cout << "-------자판기 음료 목록-------" << endl;
	cout << " 콜라" << "\t" << "사이다" << "\t" << "환타" << endl;
	cout << " " << _iCoke << "원\t " << _iCider << "원\t " << _iFanta << "원" << endl;
	cout << " 1번 - 콜라 " << " 2번 - 사이다 " << " 3번 - 환타 " << " 4번 - 거스름돈 반환 " << endl;

	cout << "현재 잔액은 " << _iMoney << " 원 입니다." << endl;
}

void GetChoice(int* pNum)
{
	cout << "원하는 상품의 번호를 누르세요 :";
	cin >> *pNum;

	Reset();

	switch (*pNum)
	{

	case 1:
	case 2:
	case 3:
	case 4:
		break;

	default:
		cout << "잘못된 번호입니다." << endl;

		Reset();

		GetChoice(&*pNum);

		break;
	}

	
}

void GetProduct(int _iCoke, int _iCider, int _iFanta, int _iNum, int* pMoney, bool* pChoice)
{
	switch (_iNum)
	{
	case 1:
	{

		cout << "선택 상품 : 콜라 - " << _iCoke << "원" << endl;
		*pMoney -= _iCoke;
		cout << "구매 성공 - 구매 후 잔액 : " << *pMoney << "원" << endl;

		break;
	}
	case 2:
	{
		cout << "선택 상품 : 사이다 - " << _iCider << "원" << endl;

		if (*pMoney < 200)
		{
			cout << "구매 실패 - 잔액 부족" << endl;
		}
		else
		{
			*pMoney -= _iCider;
			cout << "구매 성공 - 구매 후 잔액 : " << *pMoney << "원" << endl;
		}

		break;
	}

	case 3:
	{
		cout << "선택 상품 : 환타 - " << _iFanta << "원" << endl;

		if (*pMoney < 300)
		{
			cout << "구매 실패 - 잔액 부족" << endl;
		}
		else
		{
			*pMoney -= _iFanta;
			cout << "구매 성공 - 구매 후 잔액 : " << *pMoney << "원" << endl;
		}

		break;
	}

	case 4:
	{
		cout << "선택 - 거스름돈 반환" << endl;
		*pChoice = false;
		cout << "거스름 돈 : " << *pMoney << "원" << endl;
		cout << "자판기 게임을 종료합니다." << endl;


		break;
	}

	default:
		break;

	}
}