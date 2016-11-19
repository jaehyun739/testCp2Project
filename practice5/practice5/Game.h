#include <Windows.h>
#include <iostream>
using namespace std;
class Game {
private :
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public :
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	
	}
	void setDirection(int i) {
		direction = i;
	}
	void move() {
		if (direction == 37) {
			if (x > 0)
				x--;
			else
				x = 0;
		}
		else if (direction == 38)
		{
			if (y > 0)
				y--;
			else
				y = 0;
		}
		else if (direction == 39)
		{
			if (x < 30)
				x++;
			else
				x = 30;
		}
		else if (direction == 40)
		{
			if (y < 20)
				y++;
			else
				y = 20;
		}
		system("cls");
		this->gotoXY(x, y);
		cout << x << " " << y;
		cout << "бс";
	}

};