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
		cout << "�������� �����Ͽ� ���Ǳ⸦ �̿��Ͻ� �� �����ϴ�." << endl;
	}
	

	return 0;
}

void GetMoney(int* pMoney)
{
	cout << "�������� �Է��ϼ��� : ";
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
	cout << "-------���Ǳ� ���� ���-------" << endl;
	cout << " �ݶ�" << "\t" << "���̴�" << "\t" << "ȯŸ" << endl;
	cout << " " << _iCoke << "��\t " << _iCider << "��\t " << _iFanta << "��" << endl;
	cout << " 1�� - �ݶ� " << " 2�� - ���̴� " << " 3�� - ȯŸ " << " 4�� - �Ž����� ��ȯ " << endl;

	cout << "���� �ܾ��� " << _iMoney << " �� �Դϴ�." << endl;
}

void GetChoice(int* pNum)
{
	cout << "���ϴ� ��ǰ�� ��ȣ�� �������� :";
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
		cout << "�߸��� ��ȣ�Դϴ�." << endl;

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

		cout << "���� ��ǰ : �ݶ� - " << _iCoke << "��" << endl;
		*pMoney -= _iCoke;
		cout << "���� ���� - ���� �� �ܾ� : " << *pMoney << "��" << endl;

		break;
	}
	case 2:
	{
		cout << "���� ��ǰ : ���̴� - " << _iCider << "��" << endl;

		if (*pMoney < 200)
		{
			cout << "���� ���� - �ܾ� ����" << endl;
		}
		else
		{
			*pMoney -= _iCider;
			cout << "���� ���� - ���� �� �ܾ� : " << *pMoney << "��" << endl;
		}

		break;
	}

	case 3:
	{
		cout << "���� ��ǰ : ȯŸ - " << _iFanta << "��" << endl;

		if (*pMoney < 300)
		{
			cout << "���� ���� - �ܾ� ����" << endl;
		}
		else
		{
			*pMoney -= _iFanta;
			cout << "���� ���� - ���� �� �ܾ� : " << *pMoney << "��" << endl;
		}

		break;
	}

	case 4:
	{
		cout << "���� - �Ž����� ��ȯ" << endl;
		*pChoice = false;
		cout << "�Ž��� �� : " << *pMoney << "��" << endl;
		cout << "���Ǳ� ������ �����մϴ�." << endl;


		break;
	}

	default:
		break;

	}
}