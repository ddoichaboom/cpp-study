#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int iMoney(0), iChange(0), iInput(0);
	bool iChoice(true);

	cout << "----------���Ǳ����----------" << endl;
	cout << "�������� �Է��ϼ��� : ";
	cin >> iMoney;

	iChange = iMoney;

	if (iMoney >= 100)
	{
		while (iChoice)
		{
			system("cls");

			if (iChange >= 100)
			{

				cout << "-------���Ǳ� ���� ���-------" << endl;
				cout << " �ݶ�" << "\t" << "���̴�" << "\t" << "ȯŸ" << endl;
				cout << " 100��" << "\t" << "200��" << "\t" << "300��" << endl;

				cout << "���ϴ� ��ǰ�� ��ȣ�� ��������. " << endl;
				cout << " 1�� - �ݶ� " << " 2�� - ���̴� " << " 3�� - ȯŸ " << " 4�� - �Ž����� ��ȯ " << endl;

				cout << "���� �ܾ� : " << iChange << " ��" << endl;

				cout << "��ȣ �Է� : ";
				cin >> iInput;

				
					switch (iInput)
					{
					case 1:
						cout << "���� ��ǰ - �ݶ�" << endl;
						if (iChange >= 100)
						{
							iChange = iChange - 100;
							cout << "�ݶ� ���� �Ϸ�" << endl;
							cout << "���� �� �ܾ� : " << iChange << " �� �Դϴ�." << endl;
						}
						else
						{
							cout << "�ܾ��� �����Ͽ� ������ �� �����ϴ�." << endl;
						}
						system("pause");
						break;

					case 2:
						cout << "���� ��ǰ - ���̴�" << endl;
						if (iChange >= 200)
						{
							iChange = iChange - 200;
							cout << "���̴� ���� �Ϸ�" << endl;
							cout << "���� �� �ܾ� : " << iChange << "�� �Դϴ�." << endl;
						}
						else
						{
							cout << "�ܾ��� �����Ͽ� ������ �� �����ϴ�." << endl;
						}
						system("pause");
						break;

					case 3:
						cout << "����  ��ǰ - ȯŸ" << endl;
						if (iChange >= 300)
						{
							iChange = iChange - 300;
							cout << "ȯŸ ���� �Ϸ�" << endl;
							cout << "���� �� �ܾ� : " << iChange << " �� �Դϴ�." << endl;
						}
						else
						{
							cout << "�ܾ��� �����Ͽ� ������ �� �����ϴ�." << endl;
						}
						system("pause");
						break;

					case 4:
						cout << "�Ž������� " << iChange << " �Դϴ�." << endl;
						iChoice = false;
						break;

					default:
						cout << "�߸��� �Է��Դϴ�." << endl;
						system("pause");
						break;
					}

					cin.clear();
					cin.ignore(1000, '\n');
				
			}
			else
			{
				cout << "�ܾ��� �����Ͽ� ���Ǳ⸦ �̿��� �� �����ϴ�." << endl;
				iChoice = false;
				system("pause");
				break;
			}

		}
	}
	else if ((iMoney >= 0) && (iMoney < 100))
	{
		cout << "�������� �����Ͽ� ���Ǳ⸦ �̿��� �� �����ϴ�." << endl;
	}
	else
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
	}




	return 0;
}