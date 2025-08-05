#include <iostream>

#pragma region 공용체 (Union)

//using namespace std;
//
//struct Struct
//{
//	int iA;
//	float fB;
//	char cC;
//};
//
//union Union
//{
//	int iX;
//	float fY;
//	char cZ;
//};
//
//int main()
//{
//	Struct s = { 10, 3.14f, 'C' };
//	Union u = { 65 };
//
//	cout << &s.iA << endl << &s.fB << endl << &s.cC << endl;
//
//	cout << "---------------------------------" << endl;
//
//	cout << &(u.cZ) << endl;
//	cout << &u.fY << endl;
//	cout << &u.iX << endl;
//
//	cout << "---------------------------------" << endl;
//
//	cout << sizeof(s) << " | " << sizeof(u) << endl;
//
//	return 0;
//}

#pragma endregion

#pragma region 열거형 타입

using namespace std;

enum Status
{
	Default = 0,
	GamePlay,
	LOAD,
	MENU,
	Settings,
	Exit
};


int main()
{
	int iInput(0);
	bool bChoice = true;

	Status GameStatus = Default;


	
	while(bChoice)
	{

		system("cls");

		cout << "----게임 시작----" << endl;

		cin >> iInput;

		switch (iInput)
		{
		case GamePlay:
			GameStatus = GamePlay;
			cout << "게임 시작" << endl;
			break;
		case LOAD:
			GameStatus = LOAD;
			cout << "불러 오기" << endl;
			break;
		case MENU:
			GameStatus = MENU;
			cout << "메뉴" << endl;
			break;
		case Settings:
			GameStatus = Settings;
			cout << "환경 설정" << endl;
			break;
		case Exit:
			GameStatus = Exit;
			cout << "게임 종료" << endl;
			bChoice = false;
			break;
		default:
			cout << "입력 대기 중" << endl;
			continue;
		}

		system("pause");
	}
	return 0;
}

#pragma endregion
