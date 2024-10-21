#include "Player.h"
#include "Map.h"
#include "Helper.h"
#include "Marine.h"

//bool canMove = true;
//int GPlayerX = 2;
//int GPlayerY = 2;

Player::Player() {
	hp = 150;
	damage = 10;
	coord_x = 1;
	coord_y = 1;
	can_Move = false;
}

void Player::MovePlayer(int x, int y) {
	if (x < 0 || x >= Map::MAP_SIZE)
		return;
	if (y < 0 || y >= Map::MAP_SIZE)
		return;
	if (Map::GetInstance()->GetMapCoord(x, y) == ID_WALL)return;
	if (x == Marine::GetInstance()->GetCoord_X() && y == Marine::GetInstance()->GetCoord_Y())return;
	{
		//Map::GetInstance()->MapCoordFix(coord_x, coord_y, ID_NONE);
	}
	coord_x = x;
	coord_y = y;
	{
		for (int i = 1; i < Map::MAP_SIZE - 1; ++i) {
			if(i!=coord_y&& i != Marine::GetInstance()->GetCoord_Y())Map::GetInstance()->MapCoordFix(coord_x, i, ID_BULLET);
		}
			
		for (int i = 1; i < Map::MAP_SIZE - 1; ++i) {
			if(i!=coord_x&& i != Marine::GetInstance()->GetCoord_X())	Map::GetInstance()->MapCoordFix(i, coord_y, ID_BULLET);
		}
		
		Map::GetInstance()->MapCoordFix(coord_x, coord_y, ID_PLAYER);

	}
}

void Player::HandleMove() {
	// 키보드를 떼고 눌러야만 움직일수있음
	if (GMoveDir == MD_NONE) {
		can_Move = true;
		return;
	}

	// 움직일 수 있는지?
	if (can_Move == false)
		return;

	can_Move = false;

	switch (GMoveDir) {
	case MD_LEFT:
		MovePlayer(coord_x - 1, coord_y);
		break;
	case MD_RIGHT:
		MovePlayer(coord_x + 1, coord_y);
		break;
	case MD_UP:
		MovePlayer(coord_x, coord_y - 1);
		break;
	case MD_DOWN:
		MovePlayer(coord_x, coord_y + 1);
		break;
	}
}



//void MovePlayer(int x, int y) {
//
//	//범위 체크
//	if (x < 0 || x >= Map::MAP_SIZE)
//		return;
//	if (y < 0 || y >= Map::MAP_SIZE)
//		return;
//	//벽 체크
//	int index = y * Map::MAP_SIZE + x;
//	if (Map::GetInstance()->GetMapCoord(x,y)== 1)return;
//
//	// 기존 위치 정리
//	{
//		int prevIndex = GPlayerY * Map::MAP_SIZE + GPlayerX;
//		Map::GetInstance()->MapCoordFix(GPlayerX, GPlayerY, 0);
//		
//	}
//
//
//	// 새 위치 이동
//	GPlayerX = x;
//	GPlayerY = y;
//	{
//		int curIndex = GPlayerY * Map::MAP_SIZE + GPlayerX;
//		Map::GetInstance()->MapCoordFix(GPlayerX, GPlayerY, 2);
//
//	}
//
//}

//void HandleMove() {
//	// 키보드를 떼고 눌러야만 움직일수있음
//	if (GMoveDir == MD_NONE) {
//		canMove = true;
//		return;
//	}
//
//	// 움직일 수 있는지?
//	if (canMove == false)
//		return;
//
//	canMove = false;
//
//	switch (GMoveDir) {
//	case MD_LEFT:
//		MovePlayer(GPlayerX - 1, GPlayerY);
//		break;
//	case MD_RIGHT:
//		MovePlayer(GPlayerX + 1, GPlayerY);
//		break;
//	case MD_UP:
//		MovePlayer(GPlayerX, GPlayerY - 1);
//		break;
//	case MD_DOWN:
//		MovePlayer(GPlayerX, GPlayerY + 1);
//		break;
//	}
//}
