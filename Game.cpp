#pragma once
#include "Game.hpp"
#define SIZE 8

using namespace std;

void main() {
	Game othello{};
	othello.init();
	othello.play();
}
