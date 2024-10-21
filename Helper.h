#pragma once

//<������Ͽ� �����ϸ� �ٸ� ��� �߰� X>
//-> �ٸ� cpp���� �ش� ��� �߰��� ��� cpp�� ������� ���� ����� �߰��ϹǷ�
enum MoveDir {
	MD_NONE,
	MD_LEFT,
	MD_RIGHT,
	MD_UP,
	MD_DOWN,
};

enum ID {
	ID_NONE,
	ID_PLAYER,
	ID_MARINE,
	ID_BULLET,
	ID_MARINEBULLET,
	ID_WALL,
};

extern MoveDir GMoveDir;


void HandleKeyInput();
void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);