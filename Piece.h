#pragma once
#include <iostream>
#include <cmath>
#include <memory>
#include <map>
using namespace std;

// Base Piece class. Contains position, team, captured status, and move function.
class Piece {
private:
	map<string, int> typeToInt {
		{"king", 0},
		{"queen", 1},
		{"bishop", 2},
		{"knight", 3},
		{"rook", 4},
		{"pawn", 5},
	};
	
	int x, y; // Piece coordinates on game board

	string team; // Which player the piece belongs to

	string type; // What type of piece *this is

	int typeAsInt; // An int representation of the piece type


public:

	Piece(int xStart, int yStart, string t, string unit) {
		x = xStart;
		y = yStart;
		team = t;
		type = unit;
		typeAsInt = typeToInt[type];
	}

	bool move(int dx, int dy) {

		switch (typeAsInt) {
		case(0):
			if (abs(dx) + abs(dy) > 2 || abs(dx) + abs(dy) < 1) {
				return false;
			}
		case(1):
			if (dx == 0 && dy == 0) {
				return false;
			}
			if (abs(dx) != abs(dy)) {
				if (!(dx == 0) && !(dy == 0)) {
					return false;
				}
			}
		case(2):
			if ((dx == 0 && dy == 0) || (abs(dx) != abs(dy))) {
				return false;
			}
		case(3):
			if (!(abs(dx) == 2 && abs(dy) == 1) &&
				!(abs(dx) == 1 && abs(dy) == 2)) {
				return false;
			}
		case(4):
			if (dx == 0 && dy == 0 || (!(dx == 0) && !(dy == 0))) {
				return false;
			}
		case(5):
			if (dy > 0 || dx != 1) {
				return false;
			}
		}

		return true;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	string getTeam() {
		return team;
	}

	string getType() {
		return type;
	}

	void setX(int xNew) {
		x = xNew;
	}

	void setY(int yNew) {
		y = yNew;
	}

};