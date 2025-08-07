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
	MENU = 0,				// 1. 게임 시작		2. 종료
	DIFFICULTSELECT,				// 1. 쉬움	2. 보통	3. 어려움	4. 최고로 어려움
	BATTLE,					// 1. 공격			2. 도망
	REWARD,					// 확인
	LEVELUP,
	DEAD
};

enum PlayerChoice
{
	OKAY = 0,
	GAMESTART = 1,				// 선택지	:	게임 시작 (1)
	BACK = 8,					// 선택지	:	뒤로 돌아가기 (8)
	EXIT = 9					// 종료		:	게임 종료 (9)
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
	
	
	Player p1 = { "", "", 100, 100, 10, 1, 1, 10, 0, 1 };		// 기본 세팅
	Monster m1 = { "", 50, 50, 5, 1, 1, 5, 1};

	
	// 클래스 선택
	while (true)
	{
		system("cls");

		cout << "------------------------------------TXT-RPG------------------------------------\n" << endl;
		cout << "\t\t\t\t < 상세 설명 >\n" << endl;
		cout << "\t\t <1>  전사 \t- (체력 : 200 / 공격력 : 15 / 행운 : 3)" << endl;
		cout << "\t\t <2>  마법사 \t- (체력 : 80 / 공격력 : 20 / 행운 : 5)" << endl;
		cout << "\t\t <3>  도적 \t- (체력 : 120 / 공격력 : 15 / 행운 : 7)\n\n" << endl;


		cout << "\t직업을 선택하세요 ( 1. 전사 2. 마법사 3. 도적 )\n" << endl;

		cout << "클래스 선택 >> ";
		cin >> iInput;

		if (cin.fail())
		{
			cout << "숫자만 입력하세요!" << endl;
			Reset();
			system("pause");

			continue;
		}
		else if ((iInput < 1) || (iInput > 3))
		{
			cout << "1 ~ 3 중에서 선택하세요!" << endl;
			Reset();
			system("pause");

			continue;
		}

		cin.ignore();

		cout << "\n이름을 입력하세요" << endl;
		cout << "이름 입력 >> ";

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
			cout << "1. 게임 시작 \t 2. 종료 (9 입력)" << endl;
			cout << "입력 >> ";
			cin >> iInput;

			if (cin.fail())
			{
				cout << "숫자만 입력하세요!" << endl;
				Reset();
				continue;
			}

			switch (iInput)
			{
			case GAMESTART:
				iPhase++;
				break;
			case EXIT:
				cout << "게임을 종료합니다." << endl;
				bChoice = false;
				break;
			default:
				cout << "잘못된 입력값입니다." << endl;
				system("pause");
				break;
			}
		}
		else if (iPhase == DIFFICULTSELECT)
		{
			cout << "사냥터를 선택 하세요. (몬스터 난이도)" << endl;
			cout << "1. 쉬움   2. 보통   3. 어려움   4. 최고 어려움  5. 뒤로 가기 (8 입력)" << endl;
			cout << "입력 >> ";
			cin >> iInput;

			if (cin.fail())
			{
				cout << "숫자만 입력하세요!" << endl;
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
				cout << "잘못된 입력입니다." << endl;
				Reset();
				system("pause");
				continue;
			}
		}
		else if (iPhase == BATTLE)
		{
			MonsterStatus(&m1);

			cout << "적 " << m1.cName << "을 마주쳤습니다." << endl;
			cout << "행동을 선택하세요" << endl;
			cout << "1. 전투 시작 \t 2. 도망" << endl;
			cout << "입력 >> ";
			cin >> iInput;

			if (cin.fail())
			{
				cout << "숫자만 입력하세요!" << endl;
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
				cout << "잘못된 입력입니다." << endl;
				Reset();
				system("pause");
				continue;
			}

		}
		else if (iPhase == REWARD)
		{
			system("cls");
			
			cout << "-----------------------------------< 전 투 결 과 >-----------------------------------\n\n" << endl;
			cout << "입은 피해 \t: " << p1.iMaxHp - p1.iHp << "\t\t\t\t획득한 경험치 \t: " << m1.iDrpEx << endl;			

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
			cout << "-------------------------------------< 레벨업 >-------------------------------------\n\n" << endl;
			cout << "레벨 \t: " << p1.iLv << " \t\t\t\t>>>>>\t\t " << "\t레벨 \t: " << p1.iLv + iNum << endl;

			
			p1.iLv += iNum;
			p1.iCurEx = (p1.iCurEx + m1.iDrpEx) % p1.iMaxEx;
			iPhase = DIFFICULTSELECT;

			if (!strcmp(p1.cClass, "전사"))
			{
				p1.iMaxHp += 150;
				p1.iHp = p1.iMaxHp;
				p1.iAtk += 10;
				p1.iSpeed += 2;
				p1.iMaxEx = 10 + (p1.iLv * 5) + (p1.iLv * p1.iLv);
			}
			else if (!strcmp(p1.cClass, "마법사"))
			{
				p1.iMaxHp += 75;
				p1.iHp = p1.iMaxHp;
				p1.iAtk += 7;
				p1.iSpeed += 3;
				p1.iMaxEx = 10 + (p1.iLv * 5) + (p1.iLv * p1.iLv);
			}
			else if (!strcmp(p1.cClass, "도적"))
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

			cout << "-------------------------------------< 사 망 >-------------------------------------\n\n" << endl;
			cout << "사망 페널티로 인해 갖고 있던 경험치가 초기화 됩니다." << endl;
			cout << "현재 경험치 \t: " << p1.iCurEx << "\t\t\t\t\t" << "초기화 후 경험치 \t: " << 0 << endl;
			

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
		strcpy_s(p1->cClass, sizeof(p1->cClass), "전사");
		p1->iMaxHp	= 200;
		p1->iHp		= 200;
		p1->iAtk	= 10;
		p1->iLck	= 3;
		p1->iSpeed	= 5;
		break;

	case MAGE:
		strcpy_s(p1->cClass, sizeof(p1->cClass), "마법사");
		p1->iMaxHp	= 80;
		p1->iHp		= 80;
		p1->iAtk	= 20;
		p1->iLck	= 5;
		p1->iSpeed	= 7;
		break;

	case THIEF:
		strcpy_s(p1->cClass, sizeof(p1->cClass), "도적");
		p1->iMaxHp	= 120;
		p1->iHp		= 120;
		p1->iAtk	= 15;
		p1->iLck	= 7;
		p1->iSpeed	= 10;
		break;
	default:
		cout << "시스템 오류" << endl;
		throw runtime_error("클래스 선택 오류");
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
	cout << "이름 \t: " << p1->cName << "\t\t\t\t\t" << "클래스 \t: " << p1->cClass << endl;
	cout << "체력 \t:" << p1->iHp << " / " << p1->iMaxHp << " | ";

	for (int i = 0; i < iFHp; ++i)
	{
		cout << "# ";
	}
	for (int i = iFHp; i < barLen; ++i)
	{
		cout << "- ";
	}
	cout << endl << "공격력 \t: " << p1->iAtk << "\t\t\t\t\t" << "속도 \t: " << p1->iSpeed << endl;
	cout << "레벨 \t: " << p1->iLv << "\t\t\t\t\t" << "경험치 \t: ";
	
	
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

	
	cout << "이름 \t: " << m1->cName << "\t\t\t\t레벨 \t: " << m1->iLv << endl;
	cout << "체력 \t: " << m1->iHp <<  " / " << m1->iMaxHp << " | ";

	for (int i = 0; i < filled; ++i)
	{
		cout << "# ";
	}
	for (int i = filled; i < barLen; ++i)
	{
		cout << "- ";
	}
	cout << "\t\t속도 \t: " << m1->iSpeed << endl;
	cout << endl << "공격력 \t: " << m1->iAtk << "\t\t\t\t\t\t행운 \t: " << m1->iLck << endl;

	cout << "-------------------------------------------------------------------------------" << endl;

	
}

void SetMonsterStatus(Monster* m1, int* pInput)
{
	int iRNum = rand();

	if (*pInput == EASY)
	{
		strcpy_s(m1->cName, sizeof(m1->cName), "말랑말랑 슬라임");

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
		strcpy_s(m1->cName, sizeof(m1->cName), "소외된 고블린");

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
		strcpy_s(m1->cName, sizeof(m1->cName), "강인한 오크");

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
		strcpy_s(m1->cName, sizeof(m1->cName), "고대의 흑염룡");

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


		cout << "행동을 선택하세요" << endl;
		cout << "1. 공격 \t 2. 도망" << endl;
		cout << "입력 >> ";
		cin >> iInput;

		Reset();

		if (cin.fail())
		{
			cout << "숫자만 입력하세요!" << endl;
			Reset();
			system("pause");
			continue;
		}

		if (iInput == ATTACK)
		{
			if ((p1->iSpeed) == (m1->iSpeed))
			{

				cout << "플레이어-몬스터 동시 공격!" << endl;

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "플레이어 " << p1->cName << " 는 " << iMonsterDeal << " 피해를 입었습니다." << endl;

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "몬스터 " << m1->cName << " 는 " << iPlayerDeal << " 피해를 입었습니다." << endl;

				if ((p1->iHp <= iMonsterDeal) || !bLP)
				{
					cout << "-------------------------------------------------------------------------------" << endl;
					cout << "사망하셨습니다." << endl;
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

					cout << "몬스터를 처치하였습니다." << endl;
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
				cout << "플레이어 선제 공격!" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "몬스터 " << m1->cName << " 는 " << iPlayerDeal << " 피해를 입었습니다." << endl;

				if ((m1->iHp <= iPlayerDeal) || !bLM)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "몬스터를 처치하였습니다." << endl;
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

				cout << "플레이어 " << p1->cName << " 는 " << iMonsterDeal << " 피해를 입었습니다." << endl;

				if ((p1->iHp <= iMonsterDeal) || !bLP)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "사망하셨습니다." << endl;
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
				cout << "몬스터 선제 공격!" << endl;

				cout << "-------------------------------------------------------------------------------" << endl;

				cout << "플레이어 " << p1->cName << " 는 " << iMonsterDeal << " 피해를 입었습니다." << endl;

				if ((p1->iHp <= iMonsterDeal) || !bLP)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "사망하셨습니다." << endl;
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

				cout << "몬스터 " << m1->cName << " 는 " << iPlayerDeal << " 피해를 입었습니다." << endl;


				if ((m1->iHp <= iPlayerDeal) || !bLM)
				{
					cout << "-------------------------------------------------------------------------------" << endl;

					cout << "몬스터를 처치하였습니다." << endl;
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
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}
	}
}
