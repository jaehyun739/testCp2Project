#include <process.h>
#include <iostream>
#include "KeyEvent.h"
#include "Game.h"
using namespace std;
/*Thread Exam*/
/*
unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1) {
		cout << GetCurrentThreadId() << ": " << i++ << endl;
		Sleep(500);
	}
	return 0;
}
unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getkey();
		switch (i)
		{
			case 37: cout << "Left key is presed" << endl; break;
			case 38: cout << "UP key is presed" << endl; break;
			case 39: cout << "RIGHT key is presed" << endl; break;
			case 40: cout << "DOWN key is presed" << endl; break;
		}
	}
	return 0;
}
*/
/*Mini Game Exam*/
Game* game = new Game();
unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1) {
		game->move();
		Sleep(500);
	}
	return 0;
}
unsigned int __stdcall keyEvent(void*)
{
	KeyEvent k;
	int i;
	while (1) {
		i = k.getkey();
		if (i != -1) game->setDirection(i);
	}
	return 0;
}
int main() {
	//ground 0<x<30 0<y<20
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}