#include <iostream>

#pragma region ����ü (Union)

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

#pragma region ������ Ÿ��

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

		cout << "----���� ����----" << endl;

		cin >> iInput;

		switch (iInput)
		{
		case GamePlay:
			GameStatus = GamePlay;
			cout << "���� ����" << endl;
			break;
		case LOAD:
			GameStatus = LOAD;
			cout << "�ҷ� ����" << endl;
			break;
		case MENU:
			GameStatus = MENU;
			cout << "�޴�" << endl;
			break;
		case Settings:
			GameStatus = Settings;
			cout << "ȯ�� ����" << endl;
			break;
		case Exit:
			GameStatus = Exit;
			cout << "���� ����" << endl;
			bChoice = false;
			break;
		default:
			cout << "�Է� ��� ��" << endl;
			continue;
		}

		system("pause");
	}
	return 0;
}

#pragma endregion
