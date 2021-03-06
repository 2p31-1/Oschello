#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <iomanip>

#define SIZE 8
#define BLACK 1
#define WHITE -1

using namespace std;

/*

*/
class Board {
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

public:
	//Constructors
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

	//getter / setter
	array<int, SIZE*SIZE>getBoard() { return board; }
	int getNumberOfMoves() { return moves; }

	/*
		Coordinate Functions
	*/
	const static pair<int, int>toXY(int const &pos) {
		return make_pair(pos / SIZE, pos%SIZE);
	}
	const static int toINT(pair<int, int> const &pos) {
		return pos.first*SIZE + pos.second;
	}
	const static bool isAccessible(pair<int, int> coord) {
		return (coord.first >= 0 && coord.first < SIZE && coord.second >= 0 && coord.second < SIZE);
	}
	const static bool isAccessible(int y, int x) {
		return (y >= 0 && y < SIZE && x >= 0 && x < SIZE);
	}

	//directions
	const int dy[8]{
		-1, -1, -1, 0, 0, 1, 1, 1
	};
	const int dx[8]{
		-1, 0, 1, -1, 1, -1, 0, 1
	};

	//do moves
	const int recursive_put(int const dir, pair<int,int> const &pos, int const team) {
		const pair<int, int> next = make_pair(pos.first + dy[dir], pos.second + dx[dir]);
		const int pos_int = toINT(next);
		if (board[pos_int] == team)return 1;
		if (next.first < 0 || next.first >= SIZE || next.second < 0 || next.second >= SIZE) {
			return 0;
		}
		if (recursive_put(dir, next, team)) {
			board[pos_int] = team;
			return 1;
		}
	}

	//put moves, and do moves by calling recursive_put()
	//Presume that the new moves are already checked by getAllowedPositions().
	//So there're nothings to do whether is it legal move or not.
	void put(int team, int pos) {
		moves++;
		board[pos] = team;
		//othello works

		for (int i = 0; i < 8; i++) {
			recursive_put(i, toXY(pos), team);
		}
	}

	/*
	get allowed positions
	*/
	bool recursive_getAllowedMoves(int const dir, pair<int, int> &pos, int const team) {
		pos.first += dy[dir];
		pos.second += dx[dir];
		if (isAccessible(pos)) {
			switch (board[toINT(pos)]*team) {
			case 1: //if same team
				return true;
				break;
			case -1: //if another team
				return recursive_getAllowedMoves(dir, pos, team);
				break;
			default: //no any stones on this position
				return false;
			}
		}
		else {
			return false;
		}
	}
	vector<int> getAllowedMoves(int team) {
		vector<int> positions;
		for (int y = 0; y < SIZE; y++) {
			for (int x = 0; x < SIZE; x++) {
				if (board[toINT(make_pair(y, x))] == 0) {
					for (int i = 0; i < 8; i++) {
						pair<int, int> next = make_pair(y + dy[i], x + dx[i]);
						if (isAccessible(next)) {
							if (board[toINT(next)] == -team) {
								if (recursive_getAllowedMoves(i, next, team)) {
									positions.push_back(toINT(make_pair(y, x)));
								}
							}
						}
					}
				}
			}
		}
		return positions;
	}

	/*
	Calculate the score of nowplaying board
	AI checks if she can put better move.
	*/
	static int getScore(Board &board, int team) {
		int counter{ 0 };
		for (int x : board.board) {
			if (x == team)counter++;
		}
		if (counter == board.moves) return 2147483647;
		if (board.board[0] == team)counter += 20;
		if (board.board[SIZE-1] == team)counter += 20;
		if (board.board[SIZE*(SIZE-1)] == team)counter += 20;
		if (board.board[SIZE*SIZE-1] == team)counter += 20;
		return counter;
	}

	/*
	Returns whether this done.
	*/
	bool isEnd(){
		if(moves==SIZE*SIZE)return true;

	}

	/*
	Returns that who won.
	*/
	int getWinner(){
		int counter{0};
		for (int x : board){

        }
	}
};
