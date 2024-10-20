#pragma once

//<헤더파일에 웬만하면 다른 헤더 추가 X>
//-> 다른 cpp에서 해당 헤더 추가시 모든 cpp에 헤더파일 내부 헤더를 추가하므로
enum MoveDir {
	MD_NONE,
	MD_LEFT,
	MD_RIGHT,
	MD_UP,
	MD_DOWN,
};

extern MoveDir GMoveDir;

void HandleKeyInput();
void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);