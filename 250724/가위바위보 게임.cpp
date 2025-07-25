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

		cout << "-------------" << i << " 라운드------------" << endl;
		cout << "-----------가위바위보 게임-----------" << endl;
		cout << "| 1번 - 가위 | 2번 - 바위 | 3번 - 보 | 4번 - 종료 |" << endl;
		cout << "선택하세요 (숫자 입력) : ";
		cin >> iInput;


		switch (iInput)
		{
		case 1:
			if (iNum == 0)
			{
				cout << "컴퓨터는 가위를 냈습니다." << endl;
				cout << "무승부 입니다." << endl;
				iDraw++;
			}
			else if (iNum == 1)
			{
				cout << "컴퓨터는 바위를 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				iLose++;
			}
			else
			{
				cout << "컴퓨터는 보를 냈습니다." << endl;
				cout << "승리하셨습니다." << endl;
				iWin++;
			}
			system("pause");
			break;

		case 2:
			if (iNum == 0)
			{
				cout << "컴퓨터는 가위를 냈습니다." << endl;
				cout << "승리하셨습니다." << endl;
				iWin++;
			}
			else if (iNum == 1)
			{
				cout << "컴퓨터는 바위를 냈습니다." << endl;
				cout << "무승부입니다." << endl;
				iDraw++;
			}
			else
			{
				cout << "컴퓨터는 보를 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 3:
			if (iNum == 0)
			{
				cout << "컴퓨터는 가위를 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				iLose++;
			}
			else if (iNum == 1)
			{
				cout << "컴퓨터는 바위를 냈습니다." << endl;
				cout << "승리하셨습니다." << endl;
				iWin++;
			}
			else
			{
				cout << "컴퓨터는 보를 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 4:
			cout << "프로그램을 종료합니다." << endl;
			system("pause");
			bChoice = false;
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
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
			cout << "게임이 종료되었습니다." << endl;
			cout << "-------------게임 결과--------------" << endl;
			cout << iWin << "승 " << iDraw << "무 " << iLose << "패" << endl;
			system("pause");
			bChoice = false;
		}



	}

	return 0;
}