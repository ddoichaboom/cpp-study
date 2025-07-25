#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int i(5), iInput(0), iWin(0), iDraw(0), iLose(0), iNum(0);
	bool bChoice(true);

	while (bChoice)
	{
		time_t		Src = time(0);
		srand(unsigned(time(0)));
		
		iNum = rand() % 3;
		
		system("cls");

		cout << "-------------" << i << " ����------------" << endl;
		cout << "-----------���������� ����-----------" << endl;
		cout << "| 1�� - ���� | 2�� - ���� | 3�� - �� | 4�� - ���� |" << endl;
		cout << "�����ϼ��� (���� �Է�) : ";
		cin >> iInput;


		switch (iInput)
		{
		case 1:
			if (iNum == 0)
			{
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "���º� �Դϴ�." << endl;
				iDraw++;
			}
			else if (iNum == 1)
			{
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				iLose++;
			}
			else
			{
				cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
				cout << "�¸��ϼ̽��ϴ�." << endl;
				iWin++;
			}
			system("pause");
			break;

		case 2:
			if (iNum == 0)
			{
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "�¸��ϼ̽��ϴ�." << endl;
				iWin++;
			}
			else if (iNum == 1)
			{
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "���º��Դϴ�." << endl;
				iDraw++;
			}
			else
			{
				cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 3:
			if (iNum == 0)
			{
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				iLose++;
			}
			else if (iNum == 1)
			{
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "�¸��ϼ̽��ϴ�." << endl;
				iWin++;
			}
			else
			{
				cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 4:
			cout << "���α׷��� �����մϴ�." << endl;
			system("pause");
			bChoice = false;
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		cin.clear();
		cin.ignore(1000, '\n');

		i--;

		if (i == 0)
		{
			cout << "������ ����Ǿ����ϴ�." << endl;
			cout << "-------------���� ���--------------" << endl;
			cout << iWin << "�� " << iDraw << "�� " << iLose << "��" << endl;
			system("pause");
			bChoice = false;
		}



	}

	return 0;
}