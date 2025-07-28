#pragma region 자판기 - 함수 이용

#include <iostream>

using namespace std;

int GetMoney();
void Dispenser(int _iCoke, int _iCider, int _iFanta, int _iMoney);
int GetChoice();
int GetProduct(int iChoice, int _iMoney);
int GetChange(int _iMoney, int _Price);
void Reset();



int iMoney(0), iCoke(100), iCider(200), iFanta(300), iChange(0);
bool bChoice(true);

int main()
{
	
	iMoney += GetMoney();

	while (bChoice && (iMoney >= 100))
	{
		system("cls");

		Dispenser(iCoke, iCider, iFanta, iMoney);

		system("pause");
	}


	if (bChoice && (iMoney < 100))
	{
		cout << "소지금이 부족하여 자판기를 이용하실 수 없습니다." << endl;
	}
	else if (!bChoice)
	{
		cout << "거스름돈을 반환합니다." << endl;
		cout << "거스름돈은 " << iMoney << "원 입니다." << endl;
	}

	return 0;
}

int GetMoney()
{
	int iInput(0);
	cout << "소지금을 입력하세요 :";
	cin >> iInput;

	Reset(); 

	return iInput;
}

void Dispenser(int _iCoke, int _iCider, int _iFanta, int _iMoney)
{
	cout << "-------자판기 음료 목록-------" << endl;
	cout << " 콜라" << "\t" << "사이다" << "\t" << "환타" << endl;
	cout << " " << iCoke << "원\t " << iCider << "원\t " << iFanta <<"원" << endl;
	cout << " 1번 - 콜라 " << " 2번 - 사이다 " << " 3번 - 환타 " << " 4번 - 거스름돈 반환 " << endl;

	cout << "현재 잔액은 " << _iMoney << " 원 입니다." << endl;

	iMoney = GetProduct(GetChoice(), _iMoney);



}

int GetChoice()
{
	int iInput(0);

	cout << "원하는 상품의 번호를 누르세요 :";
	cin >> iInput;

	Reset();

	return iInput;
}



int GetProduct(int iChoice, int _iMoney)
{
	int _iPrice(_iMoney);

	switch (iChoice)
	{
	case 1:
	{
		cout << "선택 상품 : 콜라 - 100원" << endl;
		_iPrice = GetChange(_iMoney, iCoke);
		cout << "구매 성공 - 구매 후 잔액 : " << _iPrice << "원" << endl;
		
		break;
	}

	case 2:
	{
		if (_iMoney < 200)
		{
			cout << "선택 상품 : 사이다 - 200원" << endl;
			cout << "구매 실패 - 잔액 부족" << endl;
		}
		else
		{
			cout << "선택 상품 : 사이다 - 200원" << endl;
			_iPrice = GetChange(_iMoney, iCider);
			cout << "구매 성공 - 구매 후 잔액 : " << _iPrice << "원" << endl;
		}

		break;
	}
		

	case 3:
	{
		if (_iMoney < 300)
		{
			cout << "선택 상품 : 환타 - 300원" << endl;
			cout << "구매 실패 - 잔액 부족" << endl;
		}
		else
		{
			cout << "선택 상품 : 환타 - 300원" << endl;
			_iPrice = GetChange(_iMoney, iFanta);
			cout << "구매 성공 - 구매 후 잔액 : " << _iPrice << "원" << endl;
		}

		break;
	}

	case 4:
		bChoice = false;
		break;

	default:
		cout << "잘못된 입력입니다." << endl;
		Reset();
		break;
	}

	return _iPrice;
}

int GetChange(int _iMoney, int _Price)
{
	return _iMoney - _Price;
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

#pragma endregion