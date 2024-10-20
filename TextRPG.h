#pragma once

enum PlayerType {
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType {
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo {
	int hp;
	int attack;
	int defense;
};


void WaitForNextKey();
void EnterLobby();
void EnterBattle();
void EnterField();
void SelectPlayer();
void CreateRandomMonster();

