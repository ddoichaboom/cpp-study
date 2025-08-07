#include <iostream>

using namespace std;

struct Player
{
	char cName[20];
	char cClass[10];
	int iMaxHp;
	int iHp;
	int iAtk;
	int iLv;
	int iLck;
	int iMaxEx;
	int iCurEx;
	int iSpeed;
};

struct Monster
{
	char cName[20];
	int iMaxHp;
	int iHp;
	int iAtk;
	int iLv;
	int iLck;
	int iDrpEx;
	int iSpeed;
};

enum GamePhase
{
	MENU = 0,				// 1. ���� ����		2. ����
	DIFFICULTSELECT,				// 1. ����	2. ����	3. �����	4. �ְ�� �����
	BATTLE,					// 1. ����			2. ����
	REWARD,					// Ȯ��
	LEVELUP,
	DEAD
};

enum PlayerChoice
{
	OKAY = 0,
	GAMESTART = 1,				// ������	:	���� ���� (1)
	BACK = 8,					// ������	:	�ڷ� ���ư��� (8)
	EXIT = 9					// ����		:	���� ���� (9)
};

enum EnemyLevel
{
	EASY = 1,
	NORMAL,
	HARD,
	EXTREME,
};

enum BattlePhase
{
	ATTACK = 1,
	RUN
};

enum ClassSelect
{
	WARRIOR = 1,
	MAGE,
	THIEF
};

void Reset();
void InitPlayerSettings(Player* p1, int iInput, char* pInput);
void PlayerStatus(Player* p1);
void MonsterStatus(Monster* p1);
void SetMonsterStatus(Monster* m1, int* pInput);
void Battle(Player* p1, Monster* m1, int* pPhase);


int main()
{
	bool bChoice = true;
	int iInput(0), iPhase(0);
	char cInput[20] = "";

	srand(unsigned(time(NULL)));
	
	
	Player p1 = { "", "", 100, 100, 10, 1, 1, 10, 0, 1 };		// �⺻ ����
	Monster m1 = { "", 50, 50, 5, 1, 1, 5, 1};

	
	// Ŭ���� ����
	while (true)
	{
		system("cls");

		cout << "------------------------------------TXT-RPG------------------------------------\n" << endl;
		cout << "\t\t\t\t < �� ���� >\n" << endl;
		cout << "\t\t <1>  ���� \t- (ü�� : 200 / ���ݷ� : 15 / ��� : 3)" << endl;
		cout << "\t\t <2>  ������ \t- (ü�� : 80 / ���ݷ� : 20 / ��� : 5)" << endl;
		cout << "\t\t <3>  ���� \t- (ü�� : 120 / ���ݷ� : 15 / ��� : 7)\n\n" << endl;


		cout << "\t������ �����ϼ��� ( 1. ���� 2. ������ 3. ���� )\n" << endl;

		cout << "Ŭ���� ���� >> ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "���ڸ� �Է��ϼ���!" << endl;
			Reset();
			system("pause");

			continue;
		}
		else if ((iInput < 1) || (iInput > 3))
		{
			cout << "1 ~ 3 �߿��� �����ϼ���!" << endl;
			Reset();
			system("pause");

			continue;
		}

		cin.ignore();

		cout << "\n�̸��� �Է��ϼ���" << endl;
		cout << "�̸� �Է� >> ";

		cin.getline(cInput, sizeof(cInput));


		break;

	}

	InitPlayerSettings(&p1, iInput, cInput);
	


	while (bChoice)
	{
		system("cls");

		PlayerStatus(&p1);

		cout << "-------------------------------------------------------------------------------" << endl;

		if (iPhase == MENU)
		{
			cout << "1. ���� ���� \t 2. ���� (9 �Է�)" << endl;
			cout << "�Է� >> ";
			cin >> iInput;

			if (cin.fail())
			{
				cout << "���ڸ� �Է��ϼ���!" << endl;
				Reset();
				continue;
			}

			switch (iInput)
			{
			case GAMESTART:
				iPhase++;
				break;
			case EXIT:
				cout << "������ �����մϴ�." << endl;
				bChoice = false;
				break;
			default:
				cout << "�߸��� �Է°��Դϴ�." << endl;
				system("pause");
				break;
			}
		}
		else if (iPhase == DIFFICULTSELECT)
		{
			cout << "����͸� ���� �ϼ���. (���� ���̵�)" << endl;
			cout << "1. ����   2. ����   3. �����   4. �ְ� �����  5. �ڷ� ���� (8 �Է�)" << endl;
			cout << "�Է� >> ";
			cin >> iInput;

			if (cin.fail())
			{
				cout << "���ڸ� �Է��ϼ���!" << endl;
				Reset();
				continue;
			}

			switch (iInput)
			{
			case EASY:
				SetMonsterStatus(&m1, &iInput);
				iPhase = BATTLE;
				break;

			case NORMAL:
				SetMonsterStatus(&m1, &iInput);
				iPhase = BATTLE;
				break;

			case HARD:
				SetMonsterStatus(&m1, &iInput);
				iPhase = BATTLE;
				break;

			case EXTREME:
				SetMonsterStatus(&m1, &iInput);
				iPhase = BATTLE;
				break;

			case BACK:
				iPhase = MENU;
				break;
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				Reset();
				system("pause");
				continue;
			}
		}
		else if (iPhase == BATTLE)
		{
			MonsterStatus(&m1);

			cout << "�� " << m1.cName << "�� �����ƽ��ϴ�." << endl;
			cout << "�ൿ�� �����ϼ���" << endl;
			cout << "1. ���� ���� \t 2. ����" << endl;
			cout << "�Է� >> ";
			cin >> iInput;

			if (cin.fail())
			{
				cout << "���ڸ� �Է��ϼ���!" << endl;
				Reset();
				continue;
			}

			switch (iInput)
			{
			case ATTACK:
				Battle(&p1, &m1, &iPhase);
				break;
			case RUN:
				iPhase = DIFFICULTSELECT;
				break;
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				Reset();
				system("pause");
				continue;
			}

		}
		else if (iPhase == REWARD)
		{
			system("cls");
			
			cout << "-----------------------------------< �� �� �� �� >-----------------------------------\n\n" << endl;
			cout << "���� ���� \t: " << p1.iMaxHp - p1.iHp << "\t\t\t\tȹ���� ����ġ \t: " << m1.iDrpEx << endl;			

			if ((p1.iCurEx + m1.iDrpEx) >= p1.iMaxEx)
			{
				iPhase = LEVELUP;
			}
			else if ((p1.iCurEx + m1.iDrpEx) < p1.iMaxEx)
			{
				p1.iCurEx += m1.iDrpEx;
				iPhase = DIFFICULTSELECT;
			}
			
			system("pause");
			
		}
		else if (iPhase == LEVELUP)
		{
			system("cls");

			int iNum = (p1.iCurEx + m1.iDrpEx) / p1.iMaxEx;
			cout << "-------------------------------------< ������ >-------------------------------------\n\n" << endl;
			cout << "���� \t: " << p1.iLv << " \t\t\t\t>>>>>\t\t " << "\t���� \t: " << p1.iLv + iNum << endl;

			
			p1.iLv += iNum;
			p1.iCurEx = (p1.iCurEx + m1.iDrpEx) % p1.iMaxEx;
			iPhase = DIFFICULTSELECT;

			if (!strcmp(p1.cClass, "����"))
			{
				p1.iMaxHp += 150;
				p1.iHp = p1.iMaxHp;
				p1.iAtk += 10;
				p1.iSpeed += 2;
				p1.iMaxEx = 10 + (p1.iLv * 5) + (p1.iLv * p1.iLv);
			}
			else if (!strcmp(p1.cClass, "������"))
			{
				p1.iMaxHp += 75;
				p1.iHp = p1.iMaxHp;
				p1.iAtk += 7;
				p1.iSpeed += 3;
				p1.iMaxEx = 10 + (p1.iLv * 5) + (p1.iLv * p1.iLv);
			}
			else if (!strcmp(p1.cClass, "����"))
			{
				p1.iMaxHp += 100;
				p1.iHp = p1.iMaxHp;
				p1.iAtk += 5;
				p1.iSpeed += 4;
				p1.iMaxEx = 10 + (p1.iLv * 5) + (p1.iLv * p1.iLv);
			}
			
			system("pause");
			
		}
		else if (iPhase == DEAD)
		{
			system("cls");

			cout << "-------------------------------------< �� �� >-------------------------------------\n\n" << endl;
			cout << "��� ���Ƽ�� ���� ���� �ִ� ����ġ�� �ʱ�ȭ �˴ϴ�." << endl;
			cout << "���� ����ġ \t: " << p1.iCurEx << "\t\t\t\t\t" << "�ʱ�ȭ �� ����ġ \t: " << 0 << endl;
			

			p1.iCurEx = 0;
			p1.iHp = p1.iMaxHp;
			iPhase = MENU;

			system("pause");
			
			
		}
	}

	return 0;
}

void InitPlayerSettings(Player* p1, int iInput, char* pInput)
{
	strcpy_s(p1->cName, sizeof(p1->cName), pInput);

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(p1->cClass, sizeof(p1->cClass), "����");
		p1->iMaxHp	= 200;
		p1->iHp		= 200;
		p1->iAtk	= 10;
		p1->iLck	= 3;
		p1->iSpeed	= 5;
		break;

	case MAGE:
		strcpy_s(p1->cClass, sizeof(p1->cClass), "������");
		p1->iMaxHp	= 80;
		p1->iHp		= 80;
		p1->iAtk	= 20;
		p1->iLck	= 5;
		p1->iSpeed	= 7;
		break;

	case THIEF:
		strcpy_s(p1->cClass, sizeof(p1->cClass), "����");
		p1->iMaxHp	= 120;
		p1->iHp		= 120;
		p1->iAtk	= 15;
		p1->iLck	= 7;
		p1->iSpeed	= 10;
		break;
	default:
		cout << "�ý��� ����" << endl;
		throw runtime_error("Ŭ���� ���� ����");
	}
}

void Reset()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void PlayerStatus(Player* p1)
{
	int barLen = 10;
	int iFEx = (p1->iCurEx * barLen) / p1->iMaxEx;
	int iFHp = (p1->iHp * barLen) / p1->iMaxHp;

	cout << "------------------------------------TXT-RPG------------------------------------\n" << endl;
	cout << "�̸� \t: " << p1->cName << "\t\t\t\t\t" << "Ŭ���� \t: " << p1->cClass << endl;
	cout << "ü�� \t:" << p1->iHp << " / " << p1->iMaxHp << " | ";

	for (int i = 0; i < iFHp; ++i)
	{
		cout << "# ";
	}
	for (int i = iFHp; i < barLen; ++i)
	{
		cout << "- ";
	}
	cout << endl << "���ݷ� \t: " << p1->iAtk << "\t\t\t\t\t" << "�ӵ� \t: " << p1->iSpeed << endl;
	cout << "���� \t: " << p1->iLv << "\t\t\t\t\t" << "����ġ \t: ";
	
	
	for (int i = 0; i < iFEx; ++i)
	{
		cout << "# ";
	}
	for (int i = iFEx; i < barLen; ++i)
	{
		cout << "- ";
	}
	
	cout << endl;
	
}

void MonsterStatus(Monster* m1)
{
	int barLen = 10;
	int filled = (m1->iHp * barLen) / m1->iMaxHp;

	
	cout << "�̸� \t: " << m1->cName << "\t\t\t\t���� \t: " << m1->iLv << endl;
	cout << "ü�� \t: " << m1->iHp <<  " / " << m1->iMaxHp << " | ";

	for (int i = 0; i < filled; ++i)
	{
		cout << "# ";
	}
	for (int i = filled; i < barLen; ++i)
	{
		cout << "- ";
	}
	cout << "\t\t�ӵ� \t: " << m1->iSpeed << endl;
	cout << endl << "���ݷ� \t: " << m1->iAtk << "\t\t\t\t\t\t��� \t: " << m1->iLck << endl;

	cout << "-------------------------------------------------------------------------------" << endl;

	
}

void SetMonsterStatus(Monster* m1, int* pInput)
{
	int iRNum = rand();

	if (*pInput == EASY)
	{
		strcpy_s(m1->cName, sizeof(m1->cName), "�������� ������");

		m1->iLv		= 1 + (iRNum % 5 );
		m1->iMaxHp	= 50 + (m1->iLv * 5);
		m1->iHp		= 50 + (m1->iLv * 5);
		m1->iAtk	= 5 + (m1->iLv * 2);
		m1->iLck	= 1 + (iRNum % 2);
		m1->iDrpEx	= 5 + (m1->iLv * 1);
		m1->iSpeed = 1 + (m1->iLv * 1);
	}
	else if (*pInput == NORMAL)
	{
		strcpy_s(m1->cName, sizeof(m1->cName), "�ҿܵ� ���");

		m1->iLv = 5 + (iRNum % 10);
		m1->iMaxHp = 100 + (m1->iLv * 5);
		m1->iHp = 100 + (m1->iLv * 5);
		m1->iAtk = 5 + (m1->iLv * 2);
		m1->iLck = 1 + (iRNum % 3);
		m1->iDrpEx = 5 + (m1->iLv * 2);
		m1->iSpeed = 1 + (m1->iLv * 1);
	}
	else if (*pInput == HARD)
	{
		strcpy_s(m1->cName, sizeof(m1->cName), "������ ��ũ");

		m1->iLv = 10 + (iRNum % 50);
		m1->iMaxHp = 200 + (m1->iLv * 5);
		m1->iHp = 200 + (m1->iLv * 5);
		m1->iAtk = 5 + (m1->iLv * 2);
		m1->iLck = 1 + (iRNum % 4);
		m1->iDrpEx = 5 + (m1->iLv * 3);
		m1->iSpeed = 1 + (m1->iLv * 1);
	}
	else if (*pInput == EXTREME)
	{
		strcpy_s(m1->cName, sizeof(m1->cName), "����� �濰��");

		m1->iLv = 30 + (iRNum % 100);
		m1->iMaxHp = 500 + (m1->iLv * 5);
		m1->iHp = 500 + (m1->iLv * 5);
		m1->iAtk = 5 + (m1->iLv * 2);
		m1->iLck = 1 + (iRNum % 5);
		m1->iDrpEx = 5 + (m1->iLv * 4);
		m1->iSpeed = 1 + (m1->iLv * 1);
	}

	
}

void Battle(Player* p1, Monster* m1, int* pPhase)
{
	int iPlayerDeal(0), iMonsterDeal(0);
	bool bLP(true), bLM(true);

	
	while (*pPhase == BATTLE)
	{
		int iRandom = rand(), iInput(0);
		bool bCrit_p = (rand() % 100 < p1->iLck * 10);
		bool bCrit_m = (rand() % 100 < m1->iLck * 10);
		bLP				= (p1->iHp > 0);
		bLM				= (m1->iHp > 0);
		iPlayerDeal		= bCrit_p ? p1->iAtk * 2 : p1->iAtk;
		iMonsterDeal	= bCrit_m ? m1->iAtk * 2 : m1->iAtk;

		system("cls");

		PlayerStatus(p1);

		cout << "-------------------------------------------------------------------------------" << endl;

		MonsterStatus(m1);


		cout << "�ൿ�� �����ϼ���" << endl;
		cout << "1. ���� \t 2. ����" << endl;
		cout << "�Է� >> ";
		cin >> iInput;

		Reset();

		if (cin.fail())
		{
			cout << "���ڸ� �Է��ϼ���!" << endl;
			Reset();
			system("pause");
			continue;
		}

		if (iInput == ATTACK)
		{
			if ((p1->iSpeed) == (m1->iSpeed))
			{

				cout << "�÷��̾�-���� ���� ����!" << endl;

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "�÷��̾� " << p1->cName << " �� " << iMonsterDeal << " ���ظ� �Ծ����ϴ�." << endl;

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "���� " << m1->cName << " �� " << iPlayerDeal << " ���ظ� �Ծ����ϴ�." << endl;

				if ((p1->iHp <= iMonsterDeal) || !bLP)
				{
					cout << "-------------------------------------------------------------------------------" << endl;
					cout << "����ϼ̽��ϴ�." << endl;
					p1->iHp = 0;
					*pPhase = DEAD;
					system("pause");
					return;
				}
				else if (p1->iHp > iMonsterDeal)
				{
					p1->iHp -= iMonsterDeal;
				}

				if ((m1->iHp <= iPlayerDeal) || !bLM)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "���͸� óġ�Ͽ����ϴ�." << endl;
					m1->iHp = 0;
					*pPhase = REWARD;
					system("pause");
					return;
				}
				else if (m1->iHp > iPlayerDeal)
				{
					m1->iHp -= iPlayerDeal;
				}

				system("pause");

			}
			else if (p1->iSpeed > m1->iSpeed)
			{
				cout << "�÷��̾� ���� ����!" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "���� " << m1->cName << " �� " << iPlayerDeal << " ���ظ� �Ծ����ϴ�." << endl;

				if ((m1->iHp <= iPlayerDeal) || !bLM)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "���͸� óġ�Ͽ����ϴ�." << endl;
					m1->iHp = 0;
					*pPhase = REWARD;
					system("pause");
					return;
				}
				else if (m1->iHp > iPlayerDeal)
				{
					m1->iHp -= iPlayerDeal;
				}

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "�÷��̾� " << p1->cName << " �� " << iMonsterDeal << " ���ظ� �Ծ����ϴ�." << endl;

				if ((p1->iHp <= iMonsterDeal) || !bLP)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "����ϼ̽��ϴ�." << endl;
					p1->iHp = 0;
					*pPhase = DEAD;
					system("pause");
					return;
				}
				else if (p1->iHp > iMonsterDeal)
				{
					p1->iHp -= iMonsterDeal;
				}

				system("pause");

			}
			else if (p1->iSpeed < m1->iSpeed)
			{
				cout << "���� ���� ����!" << endl;

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "�÷��̾� " << p1->cName << " �� " << iMonsterDeal << " ���ظ� �Ծ����ϴ�." << endl;

				if ((p1->iHp <= iMonsterDeal) || !bLP)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "����ϼ̽��ϴ�." << endl;
					p1->iHp = 0;
					*pPhase = DEAD;
					system("pause");
					return;
				}
				else if (p1->iHp > iMonsterDeal)
				{
					p1->iHp -= iMonsterDeal;
				}

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "���� " << m1->cName << " �� " << iPlayerDeal << " ���ظ� �Ծ����ϴ�." << endl;


				if ((m1->iHp <= iPlayerDeal) || !bLM)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "���͸� óġ�Ͽ����ϴ�." << endl;
					m1->iHp = 0;
					*pPhase = REWARD;
					system("pause");
					return;
				}
				else if (m1->iHp > iPlayerDeal)
				{
					m1->iHp -= iPlayerDeal;
				}
				system("pause");
			}
		}
		else if (iInput == RUN)
		{
			*pPhase = DIFFICULTSELECT;
			return;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}
	}
}
