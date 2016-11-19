#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
class KeyEvent {
private :
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downkey;
public:
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getkey() {
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.Event.KeyEvent.bKeyDown) {
			downkey = InRec.Event.KeyEvent.wVirtualKeyCode;
			return downkey;
		}
		else {
			return -1;
		}
		return -1;
	}

};