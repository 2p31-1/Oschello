#pragma once
#include "Game.hpp"
#define SIZE 8

using namespace std;

class Game {
	/*
	gameMode
	bit	black	white
	00	player	player
	01	player	AI
	10	AI		Player
	11	AI		AI
	*/
	int gameMode;
	Board playboard();
public:
	Game() {}
	Game(int gameMode) { this->gameMode = gameMode; }
	void play() {

	}

	void init() {
		cout << "Oschello, the AI Othello game.\n";
		cout << "Put your game mode";
		gameMode = UI::getInt() % 4;
	}
};

void main() {
	Game othello{};
	othello.init();
	othello.play();
}
