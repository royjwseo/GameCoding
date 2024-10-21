#include "Marine.h"
#include "Map.h"
#include "Player.h"
#include "Helper.h"
#include <iostream>

Marine::Marine()
{
	coord_x = 3;
	coord_y = 3;
	
}





void Marine::MoveMarine(int x, int y) {
	if (x < 0 || x >= Map::MAP_SIZE)
		return;
	if (y < 0 || y >= Map::MAP_SIZE)
		return;
	if (Map::GetInstance()->GetMapCoord(x, y) == ID_WALL)return;
	if (x == Player::GetInstance()->GetCoord_X() && y == Player::GetInstance()->GetCoord_Y())return;
	{
		//Map::GetInstance()->MapCoordFix(coord_x, coord_y, ID_NONE);
	}
	coord_x = x;
	coord_y = y;
	{
		for (int i = 1; i < Map::MAP_SIZE - 1; ++i) {
			if (i != coord_y && i!=Player::GetInstance()->GetCoord_Y())Map::GetInstance()->MapCoordFix(coord_x, i, ID_MARINEBULLET);
		}

		for (int i = 1; i < Map::MAP_SIZE - 1; ++i) {
			if (i != coord_x &&i != Player::GetInstance()->GetCoord_X())	Map::GetInstance()->MapCoordFix(i, coord_y, ID_MARINEBULLET);
		}

		Map::GetInstance()->MapCoordFix(coord_x, coord_y, ID_MARINE);

	}
}

void Marine::HandleMove() {
	
	
	if (dir == MD_NONE && !Player::GetInstance()->GetIfAllowedToMove()) {
		dir = rand() % 4 + 1;
		can_Move = true;
		return;
	}

	// 움직일 수 있는지?
	if (can_Move == false)
		return;

	switch (dir) {
	case MD_LEFT:
		MoveMarine(coord_x - 1, coord_y);
		break;
	case MD_RIGHT:
		MoveMarine(coord_x + 1, coord_y);
		break;
	case MD_UP:
		MoveMarine(coord_x, coord_y - 1);
		break;
	case MD_DOWN:
		MoveMarine(coord_x, coord_y + 1);
		break;
	}

	{
		dir = 0;
		can_Move = false;
	}
	


}
