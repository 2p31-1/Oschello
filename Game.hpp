#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

#define SIZE 8
#define BLACK 1
#define WHITE -1

using namespace std;



class Board {
	Board() {
		//init
		moves = 4;
		board[(SIZE / 2 - 1)*SIZE + SIZE / 2 - 1] = BLACK;
		board[(SIZE / 2 - 1)*SIZE + SIZE / 2] = WHITE;
		board[SIZE / 2 * SIZE + SIZE / 2 - 1] = WHITE;
		board[SIZE / 2 * SIZE + SIZE / 2] = BLACK;
	}
	Board(Board &b) { 
		this->board = b.board;
		this->moves = b.moves;
	}
	/*
		Every allocation means :

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
	array<int, SIZE*SIZE> board{ 0 };
	int moves;

	pair<int, int>toXY(int const &pos) {
		return make_pair(pos / SIZE, pos%SIZE);
	}
	int toINT(pair<int, int> const &pos) {
		return pos.first*SIZE + pos.second;
	}
	//directions
	const int dy[8]{
		-1, -1, -1, 0, 0, 1, 1, 1
	};
	const int dx[8]{
		-1, 0, 1, -1, 1, -1, 0, 1
	};
	int recursive_put(int const dir, pair<int,int> const &pos, int const team) {
		const int pos_int = toINT(pos);
		if (pos_int < 0 || pos_int >= SIZE*SIZE || board[pos_int]==0)return 0;
		if (board[pos_int] == team)return 1;
		const pair<int, int> next = make_pair(pos.first + dy[dir], pos.second + dx[dir]);
		if (next.first < 0 || next.first >= SIZE || next.second < 0 || next.second >= SIZE) {
			return 0;
		}
		if (recursive_put(dir, next, team)) {
			board[pos_int] = team;
			return 1;
		}
	}
	void put(int team, int pos) {
		moves++;
		board[pos] = team;
		//othello works

		for (int i = 0; i < 8; i++) {
			//note : workplace
		}
	}

	/*
	get allowed positions
	*/
	vector<int> getAllowedPositions(int team) {

	}

	/*
	Calculate the score of nowplaying board
	AI checks if she can put better move.
	*/
	int getScore(Board &board) {

	}

};

class UI {
	void info() {

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
	int getNewPosition() {
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
	string getInput() {
		string i;
		cin >> i;
		return i;
	}
	int getInt() {
		int i;
		cin >> i;
		return i;
	}
	void error(int e) {
		string errormsg[] = {
			"Unavailable Y-axis letter." //error 0
			, "Unavailable X-axis number." //error 1
		};
		cout << "\n" << errormsg[e];
	}
};

class AI {
};
