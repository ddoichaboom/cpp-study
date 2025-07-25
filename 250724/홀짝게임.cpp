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

		cout << "정답 : " << iNum << endl;
		cout << i << " 회 남았습니다." << endl;
		cout << "-----------홀/짝 중 선택하세요-----------" << endl;
		cout << "| 1번 - 홀 | 2번 - 짝 | 3번 - 게임 종료 |" << endl;
		cout << "번호 입력 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (iRem == 1)
			{
				cout << "정답입니다." << endl;
				iWin++;
			}
			else
			{
				cout << "오답입니다." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 2:
			if (iRem == 0)
			{
				cout << "정답입니다." << endl;
				iWin++;
			}
			else
			{
				cout << "오답입니다." << endl;
				iLose++;
			}
			system("pause");
			break;

		case 3:
			cout << "게임을 종료합니다." << endl;
			bChoice = false;
			break;

		default :
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
			system("cls");
			cout << "---------------게임 결과---------------" << endl;
			cout << iWin << "승 " << iLose << "패" << endl;
			system("pause");
			bChoice = false;
		}

		
	}

	

	return 0;
}