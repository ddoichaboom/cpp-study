#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int iMoney(0), iChange(0), iInput(0);
	bool iChoice(true);

	cout << "----------자판기게임----------" << endl;
	cout << "소지금을 입력하세요 : ";
	cin >> iMoney;

	iChange = iMoney;

	if (iMoney >= 100)
	{
		while (iChoice)
		{
			system("cls");

			if (iChange >= 100)
			{

				cout << "-------자판기 음료 목록-------" << endl;
				cout << " 콜라" << "\t" << "사이다" << "\t" << "환타" << endl;
				cout << " 100원" << "\t" << "200원" << "\t" << "300원" << endl;

				cout << "원하는 상품의 번호를 누르세요. " << endl;
				cout << " 1번 - 콜라 " << " 2번 - 사이다 " << " 3번 - 환타 " << " 4번 - 거스름돈 반환 " << endl;

				cout << "현재 잔액 : " << iChange << " 원" << endl;

				cout << "번호 입력 : ";
				cin >> iInput;

				
					switch (iInput)
					{
					case 1:
						cout << "선택 상품 - 콜라" << endl;
						if (iChange >= 100)
						{
							iChange = iChange - 100;
							cout << "콜라 구매 완료" << endl;
							cout << "구매 후 잔액 : " << iChange << " 원 입니다." << endl;
						}
						else
						{
							cout << "잔액이 부족하여 구매할 수 없습니다." << endl;
						}
						system("pause");
						break;

					case 2:
						cout << "선택 상품 - 사이다" << endl;
						if (iChange >= 200)
						{
							iChange = iChange - 200;
							cout << "사이다 구매 완료" << endl;
							cout << "구매 후 잔액 : " << iChange << "원 입니다." << endl;
						}
						else
						{
							cout << "잔액이 부족하여 구매할 수 없습니다." << endl;
						}
						system("pause");
						break;

					case 3:
						cout << "선택  상품 - 환타" << endl;
						if (iChange >= 300)
						{
							iChange = iChange - 300;
							cout << "환타 구매 완료" << endl;
							cout << "구매 후 잔액 : " << iChange << " 원 입니다." << endl;
						}
						else
						{
							cout << "잔액이 부족하여 구매할 수 없습니다." << endl;
						}
						system("pause");
						break;

					case 4:
						cout << "거스름돈은 " << iChange << " 입니다." << endl;
						iChoice = false;
						break;

					default:
						cout << "잘못된 입력입니다." << endl;
						system("pause");
						break;
					}

					cin.clear();
					cin.ignore(1000, '\n');
				
			}
			else
			{
				cout << "잔액이 부족하여 자판기를 이용할 수 없습니다." << endl;
				iChoice = false;
				system("pause");
				break;
			}

		}
	}
	else if ((iMoney >= 0) && (iMoney < 100))
	{
		cout << "소지금이 부족하여 자판기를 이용할 수 없습니다." << endl;
	}
	else
	{
		cout << "잘못된 입력입니다." << endl;
	}




	return 0;
}