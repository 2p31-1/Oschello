#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <iomanip>

#include "Board.hpp"



class UI {
public:
	const static void doPlayerTurn(Board &board, int team) {

	}

	const static int init() {
		cout << "Oschello, the AI Othello game.\n";
		cout << "Put your game mode";
		return getInt();
	}

	const static void printBoard(Board &board) {
		array<int, SIZE*SIZE>*p = &board.getBoard(); //need "-fpermissive" compiler option
		cout << "  ";
		for (int x = 0; x < SIZE; x++) {
			cout << setw(2) << x + 1;
		}
		cout << "\n";
		for (int y = 0; y < SIZE; y++) {
			cout << " " << char('A' + y);
			for (int x = 0; x < SIZE; x++) {
				cout << ((*p)[y*SIZE + x] == 0 ? "  " : ((*p)[y*SIZE + x] == BLACK) ? "¡Û" : "¡Ü");
			}
			cout << "\n";
		}
	}

	/*
	Gets new position from real USER and return following numbers

	   1  2  3  4  5  6  7  8
	A  0  1  2  3  4  5  6  7
	B  8  9 10 11 12 13 14 15
	C 16 17 18 19 20 21 22 23
	D 24 25 26 27 28 29 30 31
	E 32 33 34 35 36 37 38 39
	F 40 41 42 43 44 45 46 47
	G 48 49 50 51 52 53 54 55
	H 56 57 58 59 60 61 62 63
	*/
	const static int getNewPosition() {
		string pos;
		int y=-1, x=0;
		cout << "\nNew Position : ";
		pos = getInput();
		if (pos[0] >= 'A'&&pos[0] <= 'Z') {
			y = pos[0] - 'A';
		}
		else if (pos[0] >= 'a'&&pos[0] <= 'z') {
			y = pos[0] - 'a';
		}
		else {
			error(0);
			return getNewPosition();
		}
		for (int i = 1; i < pos.length(); i++) {
			if (pos[i]<'0' || pos[i]>'9') {
				error(1);
				return getNewPosition();
			}
			x *= 10;
			x += pos[i] - '0';
		}
		x -= 1;
		if (x < 0) {
			error(1);
			return getNewPosition();
		}
		return y * SIZE + x;
	}
	const static string getInput() {
		string i;
		cin >> i;
		return i;
	}
	const static int getInt() {
		int i;
		cin >> i;
		return i;
	}
	const static void error(int e) {
		string errormsg[] = {
			"Unavailable Y-axis letter." //error 0
			, "Unavailable X-axis number." //error 1
		};
		cout << "\n" << errormsg[e];
	}
};


class AI {

};

class Game {
	/*
	gameMode
	bit	black	white
	0	00	player	player
	1	01	player	AI
	2	10	AI		Player
	3	11	AI		AI
	*/
	int gameMode;
	Board *playboard;
public:
	Game() {playboard = new Board();}
	Game(int gameMode) { this->gameMode = gameMode; playboard = new Board();}
	void play() {
		UI::printBoard(*playboard);
		UI::getInt();
	}

	void init() {
		gameMode = UI::init()%4;
	}
};
