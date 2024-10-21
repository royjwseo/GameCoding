#pragma once


class Marine
{
public:
	Marine();

	Marine(const Marine&) = delete;
	Marine& operator=(const Marine&) = delete;

	void MoveMarine(int x, int y);
	void HandleMove();

	static Marine* GetInstance() {
		static Marine marine;
		return &marine;
	}
	int GetCoord_X() { return coord_x; }
	int GetCoord_Y() { return coord_y; }

private:
	int coord_x, coord_y;
	bool can_Move = false;
	int dir = 0;
	
};

