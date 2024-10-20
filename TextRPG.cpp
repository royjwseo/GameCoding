#include "TextRPG.h"
#pragma once
#include <iostream>

using std::cout;
using std::cin;



PlayerType MyPlayerType;
StatInfo MyPlayerStat;

MonsterType monsterType;
StatInfo monsterStat;

void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러주세요\n";
	cout << ">>";
	int input;
	cin >> input;

	system("cls"); //콘솔 화면 클리어 명령어
}

void EnterLobby()
{
	while (1) {
		cout << "---------------------------\n";
		cout << "   Welcome To The Lobby!   \n";
		cout << "---------------------------\n";

		//플레이어 직업 선택
		SelectPlayer();
		
		cout << "---------------------------\n";
		cout << " (1) Enter Field! (!1) Turn off Game \n";
		cout << "---------------------------\n";

		int input{};
		cin >> input;

		if (input == 1) {
			EnterField();
		}
		else {
			return;
		}
	}
}

void EnterBattle()
{
	while (true) {
		int damage = MyPlayerStat.attack - monsterStat.defense;
		if (damage < 0)damage = 0;

		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)monsterStat.hp = 0;

		cout << "Monster's Left HP : " << monsterStat.hp << '\n';

		if (monsterStat.hp == 0) {
			cout << "몬스터를 처치했습니다!\n";
			return;
		}

		// 반격

		damage = monsterStat.attack - MyPlayerStat.defense;
		if (damage < 0)damage = 0;
		MyPlayerStat.hp -= damage;
	
		
		if (MyPlayerStat.hp < 0)MyPlayerStat.hp = 0;

		cout << "Player's Left HP : " << MyPlayerStat.hp << '\n';

		if (MyPlayerStat.hp == 0) {
			cout << "당신은 죽었습니다\nGame Over\n";
			return;
		}

	}
}

void EnterField()
{

	while (1) {
		cout << "---------------------------\n";
		cout << " You Entered The Field! \n";
		cout << "---------------------------\n";

		cout << "[PLAYER] HP : " << MyPlayerStat.hp << " / ATT : " << MyPlayerStat.attack << " / DEF : " << MyPlayerStat.defense << '\n';

		// 몬스터 스폰

		CreateRandomMonster();


		cout << "---------------------------\n";
		cout << " (1) Fight (2) Run\n";
		cout << "---------------------------\n";
		cout << ">>>";
		int input{};
		cin >> input;

		if (input == 1) {
			EnterBattle();
			if (MyPlayerStat.hp == 0)
				return;
		}
		else {
			return;
		}
	}
}

void SelectPlayer()
{
	while (1) {
		cout << "---------------------------\n";
		cout << " Select Your Player's Job! \n";
		cout << " (1) Knight (2) Archer (3) Mage \n";
		cout << "---------------------------\n";
		cout << ">>>";

		int choice;
		cin >> choice;

		switch (choice) {
		case PT_Knight:
			cout << "Knight is preparing...\n";
			MyPlayerStat.hp = 150;
			MyPlayerStat.attack = 10;
			MyPlayerStat.defense = 5;
			MyPlayerType = PT_Knight;
			return; //return 이후 함수 호출 위치로 돌아가기 때문에 break는 실행되지 않음 
		//	break;	
		case PT_Archer:
			cout << "Archer is preparing...\n";
			MyPlayerStat.hp = 100;
			MyPlayerStat.attack = 15;
			MyPlayerStat.defense = 3;
			MyPlayerType = PT_Archer;
			return;
		//	break;
		case PT_Mage:
			cout << "Mage is preparing...\n";
			MyPlayerStat.hp = 80;
			MyPlayerStat.attack = 25;
			MyPlayerStat.defense = 0;
			MyPlayerType = PT_Mage;
			return;
		//	break;
		default:
			break;
		}

	}
}

void CreateRandomMonster()
{
	srand(time(0));
	//1~32527
	int randChoice = 1 + (rand() % 3);

	switch (randChoice) {
	
	case MT_Slime:
		cout << "슬라임 생성중...! (HP:30 / ATT:2 / DEF:0)\n";
		monsterStat.hp = 30;
		monsterStat.defense = 0;
		monsterStat.attack = 2;
			monsterType = MT_Slime;
		break;
	case MT_Orc:
		cout << "오크 생성중...! (HP:40 / ATT:10 / DEF:3)\n";
		monsterStat.hp = 40;
		monsterStat.defense = 3;
		monsterStat.attack = 10;
		monsterType = MT_Orc;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중...! (HP:80 / ATT:15 / DEF:5)\n";
		monsterStat.hp = 80;
		monsterStat.defense = 5;
		monsterStat.attack = 15;
		monsterType = MT_Skeleton;
		break;
	}
}
