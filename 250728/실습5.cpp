#pragma region ���Ǳ� - �Լ� �̿�

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
		cout << "�������� �����Ͽ� ���Ǳ⸦ �̿��Ͻ� �� �����ϴ�." << endl;
	}
	else if (!bChoice)
	{
		cout << "�Ž������� ��ȯ�մϴ�." << endl;
		cout << "�Ž������� " << iMoney << "�� �Դϴ�." << endl;
	}

	return 0;
}

int GetMoney()
{
	int iInput(0);
	cout << "�������� �Է��ϼ��� :";
	cin >> iInput;

	Reset(); 

	return iInput;
}

void Dispenser(int _iCoke, int _iCider, int _iFanta, int _iMoney)
{
	cout << "-------���Ǳ� ���� ���-------" << endl;
	cout << " �ݶ�" << "\t" << "���̴�" << "\t" << "ȯŸ" << endl;
	cout << " " << iCoke << "��\t " << iCider << "��\t " << iFanta <<"��" << endl;
	cout << " 1�� - �ݶ� " << " 2�� - ���̴� " << " 3�� - ȯŸ " << " 4�� - �Ž����� ��ȯ " << endl;

	cout << "���� �ܾ��� " << _iMoney << " �� �Դϴ�." << endl;

	iMoney = GetProduct(GetChoice(), _iMoney);



}

int GetChoice()
{
	int iInput(0);

	cout << "���ϴ� ��ǰ�� ��ȣ�� �������� :";
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
		cout << "���� ��ǰ : �ݶ� - 100��" << endl;
		_iPrice = GetChange(_iMoney, iCoke);
		cout << "���� ���� - ���� �� �ܾ� : " << _iPrice << "��" << endl;
		
		break;
	}

	case 2:
	{
		if (_iMoney < 200)
		{
			cout << "���� ��ǰ : ���̴� - 200��" << endl;
			cout << "���� ���� - �ܾ� ����" << endl;
		}
		else
		{
			cout << "���� ��ǰ : ���̴� - 200��" << endl;
			_iPrice = GetChange(_iMoney, iCider);
			cout << "���� ���� - ���� �� �ܾ� : " << _iPrice << "��" << endl;
		}

		break;
	}
		

	case 3:
	{
		if (_iMoney < 300)
		{
			cout << "���� ��ǰ : ȯŸ - 300��" << endl;
			cout << "���� ���� - �ܾ� ����" << endl;
		}
		else
		{
			cout << "���� ��ǰ : ȯŸ - 300��" << endl;
			_iPrice = GetChange(_iMoney, iFanta);
			cout << "���� ���� - ���� �� �ܾ� : " << _iPrice << "��" << endl;
		}

		break;
	}

	case 4:
		bChoice = false;
		break;

	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
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