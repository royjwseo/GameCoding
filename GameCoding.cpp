// GameCoding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 2024-10-20 파일 분리 

#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include "Marine.h"
using namespace std;

#include <array>




int main()
{
	srand(time(NULL));
	SetCursorOnOff(false);
	
	Player::GetInstance()->MovePlayer(5, 5);
	while (true) {

		//입력
		HandleKeyInput();
		//로직
		Marine::GetInstance()->HandleMove();
		Player::GetInstance()->HandleMove();
	
	
		//출력
		Map::GetInstance()->PrintMap();
		if (Map::GetInstance()->GetIfGameOver()) {
			cout << "=========게임 종료===========\n";
			break;
		}
	}
	while (1) {
		cout << "아무거나 입력하시오";
		int a;
		cin >> a;
		break;
	}
	
}

