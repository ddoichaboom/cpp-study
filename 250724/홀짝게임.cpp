#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int i(5), iInput(0), iNum(0), iRem(0), iWin(0), iLose(0);
	bool bChoice(true);

	while (bChoice)
	{
		time_t		Src = time(0);
		srand(unsigned(Src));

		iNum = (rand() % 10) + 1;
		iRem = iNum % 2;

		system("cls");

		cout << "���� : " << iNum << endl;
		cout << i << " ȸ ���ҽ��ϴ�." << endl;
		cout << "-----------Ȧ/¦ �� �����ϼ���-----------" << endl;
		cout << "| 1�� - Ȧ | 2�� - ¦ | 3�� - ���� ���� |" << endl;
		cout << "��ȣ �Է� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (iRem == 1)
			{
				cout << "�����Դϴ�." << endl;
				iWin++;
			}
			else
			{
				cout << "�����Դϴ�." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 2:
			if (iRem == 0)
			{
				cout << "�����Դϴ�." << endl;
				iWin++;
			}
			else
			{
				cout << "�����Դϴ�." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 3:
			cout << "������ �����մϴ�." << endl;
			bChoice = false;
			break;

		default :
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
			system("cls");
			cout << "---------------���� ���---------------" << endl;
			cout << iWin << "�� " << iLose << "��" << endl;
			system("pause");
			bChoice = false;
		}

		
	}

	

	return 0;
}