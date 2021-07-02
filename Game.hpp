#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

#define SIZE 8

using namespace std;

class Board {
	array<int, SIZE*SIZE> board;

	/*
	returns 1 when has no error
	*/
	int put(int team, int pos);

	/*
	get allowed positions
	*/
	vector<int> getAllowedPositions();

};

class UI {
	void info() {

	}

	/*
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
		cout << "\nNew Position : ";
		pos = getInput();

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
};

class AI {

};
