#include "Map.h"
#include "Helper.h"
#include <iostream>

using namespace std;


//int GMap1D[MAP_SIZE * MAP_SIZE] =
//{
//	1,1,1,1,1,
//	1,0,0,0,1,
//	1,0,2,0,1,
//	1,0,0,0,1,
//	1,1,1,1,1
//};

Map::Map()
{

	
	for (int i = 0; i < MAP_SIZE; ++i) {

		MapField[i] = ID_WALL;
		MapField[MAP_SIZE*i] = ID_WALL;
		MapField[(MAP_SIZE-1)*MAP_SIZE+i] = ID_WALL;
		MapField[MAP_SIZE*i+MAP_SIZE-1] = ID_WALL;
	}
	//MapField[144] = 2;
}

int Map::GetMapCoord(int x, int y) {
	return MapField[MAP_SIZE * x + y];
}

void Map::MapCoordFix(int x, int y,int value) {
	MapField[MAP_SIZE * y + x] = value;
}
void Map::PrintMap() {
	SetCursorPosition(0, 0);

	int playerscore{}, marinescore{};
	for (int i = 0; i < MAP_SIZE * MAP_SIZE; ++i) {
		if (MapField[i] == ID_BULLET)playerscore++;
		else if (MapField[i] == ID_MARINEBULLET)marinescore++;
	}

	for (int i = 0; i < MAP_SIZE * MAP_SIZE; ++i) {
		switch (MapField[i]) {
		case ID_NONE:
			cout << "□ ";
			break;
		case ID_WALL:
			cout << "■ ";
			break;
		case ID_PLAYER:
			cout << "♥ "; 
			break;
		case ID_MARINE:
			cout << "♠ ";
			break;
		case ID_BULLET:
			cout << "● "; 
			break;
		case ID_MARINEBULLET:
			cout << "⊙ ";
			break;
		}

		
		
		if ((i + 1) % MAP_SIZE == 0) {
			cout << '\n';
		}
		
	}
	cout << "============= 마린보다 100점 앞서시오=============\n";
	cout << " 플레이어 점수 : " << playerscore << "   마린 점수 : " << marinescore << '\n';
	
	if (playerscore > marinescore+100) {
		isGameOver = true;
	}
}


//void PrintMap1D() {
//	SetCursorPosition(0, 0);
//	
//	for (int i = 0; i < MAP_SIZE * MAP_SIZE; ++i) {
//		switch (GMap1D[i]) {
//		case 0:
//			cout << "□";
//			break;
//		case 1:
//			cout << "■";
//			break;
//		case 2:
//			cout << "●";
//			break;
//		}
//
//		if ((i + 1) % MAP_SIZE == 0) {
//			cout << '\n';
//		}
//	}
//}