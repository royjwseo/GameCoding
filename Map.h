#pragma once
#include <array>

//const int MAP_SIZE = 5;
//
//extern int GMap1D[MAP_SIZE * MAP_SIZE];
//
//void PrintMap1D();


class Map {

public:
	Map();
	Map(const Map& other) = delete;
	Map& operator=(const Map& other) = delete;

	static Map* GetInstance() {
		static Map map;
		return &map;
	}

	int GetMapCoord(int x, int y);
	void MapCoordFix(int x, int y, int value);
	void PrintMap();
	void PrintScore();
	bool GetIfGameOver() { return isGameOver; }
public:
	const static int MAP_SIZE = 25;
private:
	std::array<int, MAP_SIZE*MAP_SIZE>MapField;
	bool isGameOver = false;
};
