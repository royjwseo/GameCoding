#pragma once

extern int GPlayerX ;
extern int GPlayerY;

//void MovePlayer(int x, int y);
//void HandleMove();

class Player {

public:
	Player();
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;


	void MovePlayer(int x, int y);
	void HandleMove();
	
	static Player* GetInstance() {
		static Player pl;

		return &pl;
	}
	int GetCoord_X() { return coord_x; }
	int GetCoord_Y() { return coord_y; }
	bool GetIfAllowedToMove() { return can_Move; }
private:
	int hp;
	int damage;
	int coord_x;
	int coord_y;
	bool can_Move = false;
};