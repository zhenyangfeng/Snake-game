
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <time.h>


#define MAXSNAKESIZE 100
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

class Taskas {
private:
	int x;
	int y;
public: 
	Taskas() {
		x = y = 10;
	}
	Taskas(int x, int y) {
		this -> x = x;
		this -> y = y;
	}
	void Taskai(int x, int y) {
		this -> x = x;
		this -> y = y;
	}
	int gautX() {
		return x;
	}
	int gautY() {
		return y;
	}
	void JudetVirsun() {
		y--;
	}
	void JudetApacia() {
		y++;
	}
	void JudetDesine() {
		x--;
	}
	void JudetKaire() {
		x++;
	}
	void Piest(){
		gotoxy(x, y);
		cout << "*";
	}
	void Istrint() {
		gotoxy(x, y);
		cout << " ";
	}
	void CopyPos(Taskas * p) {
		p->x = x;
		p->y = y;
	}
	
};

class Snake {
private:
	Taskas * cell[MAXSNAKESIZE];
	int dydis;
	char dir;
	Taskas vaisius;
public:
	Snake() {
		dydis = 1;
		cell[0] = new Taskas(20, 20);
		for (int i = 1; i < MAXSNAKESIZE; i++) {
			cell[i] = NULL;
		}
		vaisius.Taskai(rand() % 50, rand() % 25);
	}
	void AddCell(int x, int y) {
		cell[dydis++] = new Taskas(x, y);
	}
	void SuktVirsu() {
		dir = 'w';
	}
	void SuktDesine() {
		dir = 'd';
	}
	void SuktKaire() {
		dir = 'a';
	}
	void SuktApacia() {
		dir = 's';
	}
	void Move(){
		system("cls");

		for (int i = dydis-1; i>0; i--){
			cell[i-1]->CopyPos(cell[i]);
		}


		switch (dir) {
		case 'w':
			cell[0]->JudetVirsun();
			break;
		case 'd':
			cell[0]->JudetDesine();
			break;
		case 's':
			cell[0]->JudetApacia();
			break;
		case 'a':
			cell[0]->JudetKaire();
			break;
		}

		if (vaisius.gautX() == cell[0]->gautX() && vaisius.gautY() == cell[0]->gautY()){
			AddCell(0,0);
			vaisius.Taskai(rand()%50, rand()%25);
		}
	



		for (int i = 0; i < dydis; i++)
			cell[i]->Piest();
		vaisius.Piest();

		

		Sleep(100);
	}

};
int main()
{
	srand((unsigned)time(NULL)); 




	Snake snake;
	char op = '1';
	do {
		if (_kbhit()) {
			op = _getch();
		}
		switch(op) {
			case'w':
			case'W':
			snake.SuktVirsu();
			break;

			case's':
			case'S':
				snake.SuktApacia();
				break;

			case'a':
			case'A':
				snake.SuktDesine();
				break;

			case'd':
			case'D':
				snake.SuktKaire();
				break;
		}snake.Move();
	} while (op != 'e');
	return 0;
	

   
}

