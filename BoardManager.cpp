#pragma once
#include "Piece.h"
#include <map>
#include <ctype.h>
using namespace std;

class BoardManager {
private:
	struct Space {
		Piece* piece;
	};

	Space Board[8][8];

	map<string, char> typeToChar {
		{"rook", 'R'},
		{"knight", 'N'},
		{"bishop", 'B'},
		{"queen", 'Q'},
		{"king", 'K'},
		{"pawn", 'P'}
	};

public:
	BoardManager() {
		for (int i = 0; i < 8; i++) {
			//Place and assign all pawns
			Board[1][i].piece = new Piece(1, i, "black", "pawn");
			Board[6][i].piece = new Piece(6, i, "white", "pawn");

			//Place and assign all other pieces
			Board[0][0].piece = new Piece(0, 0, "black", "rook");
			Board[0][1].piece = new Piece(0, 1, "black", "knight");
			Board[0][2].piece = new Piece(0, 2, "black", "bishop");
			Board[0][3].piece = new Piece(0, 3, "black", "queen");
			Board[0][4].piece = new Piece(0, 4, "black", "king");
			Board[0][5].piece = new Piece(0, 5, "black", "bishop");
			Board[0][6].piece = new Piece(0, 6, "black", "knight");
			Board[0][7].piece = new Piece(0, 7, "black", "rook");

			Board[7][0].piece = new Piece(7, 0, "white", "rook");
			Board[7][1].piece = new Piece(7, 1, "white", "knight");
			Board[7][2].piece = new Piece(7, 2, "white", "bishop");
			Board[7][3].piece = new Piece(7, 3, "white", "queen");
			Board[7][4].piece = new Piece(7, 4, "white", "king");
			Board[7][5].piece = new Piece(7, 5, "white", "bishop");
			Board[7][6].piece = new Piece(7, 6, "white", "knight");
			Board[7][7].piece = new Piece(7, 7, "white", "rook");
		}
	}

	Piece* PieceAt(int x, int y) {
		return Board[x][y].piece;
	}

	void setBoard() {
		for (int i = 0; i < 8; i++) {
			//Place and assign all pawns
			Board[1][i].piece = new Piece(1, i, "black", "pawn");
			Board[6][i].piece = new Piece(6, i, "white", "pawn");

			//Place and assign all other pieces
			Board[0][0].piece = new Piece(0, 0, "black", "rook");
			Board[0][1].piece = new Piece(0, 1, "black", "knight");
			Board[0][2].piece = new Piece(0, 2, "black", "bishop");
			Board[0][3].piece = new Piece(0, 3, "black", "queen");
			Board[0][4].piece = new Piece(0, 4, "black", "king");
			Board[0][5].piece = new Piece(0, 5, "black", "bishop");
			Board[0][6].piece = new Piece(0, 6, "black", "knight");
			Board[0][7].piece = new Piece(0, 7, "black", "rook");

			Board[7][0].piece = new Piece(7, 0, "white", "rook");
			Board[7][1].piece = new Piece(7, 1, "white", "knight");
			Board[7][2].piece = new Piece(7, 2, "white", "bishop");
			Board[7][3].piece = new Piece(7, 3, "white", "queen");
			Board[7][4].piece = new Piece(7, 4, "white", "king");
			Board[7][5].piece = new Piece(7, 5, "white", "bishop");
			Board[7][6].piece = new Piece(7, 6, "white", "knight");
			Board[7][7].piece = new Piece(7, 7, "white", "rook");
		}
	}

	void clearBoard() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				delete Board[i][j].piece;
			}
		}
	}

	bool makeMove(int xStart, int yStart, int xEnd, int yEnd) {
		// Pointer to piece being moved
		Piece* movingPiece = Board[xStart][yStart].piece;

		// Check if piece is capable of move
		if (!movingPiece->move(xStart - xEnd, yStart - yEnd)) {
			return false;
		}

		// Check if move path is obstructed
		int xDir;
		int yDir;
		if (movingPiece->getType() != "knight") {
			if (xEnd != xStart) {
				xDir = (xEnd - xStart) / abs(xEnd - xStart);
			}
			else {
				xDir = 0;
			}
			if (yEnd != yStart) {
				yDir = (yEnd - yStart) / abs(yEnd - yStart);
			}
			else {
				yDir = 0;
			}
			
			int x = xStart;
			int y = yStart;

			while (x != xEnd && y != yEnd) {
				x += xDir;
				y += yDir;
				if (Board[x][y].piece && (x != xEnd && y != yEnd)) {
					return false;
				}
			}
		}

		// Check if destination is held by another piece
		if (Board[xEnd][yEnd].piece) {
			if (movingPiece->getTeam() == Board[xEnd][yEnd].piece->getTeam()) {
				return false;
			}
			else {
				delete Board[xEnd][yEnd].piece;
			}
		}

		Board[xEnd][yEnd].piece = movingPiece;
		Board[xStart][yStart].piece = nullptr;
	}

	//Prints the board to console line-by-line
	void printBoard() {
		cout << "  a b c d e f g h\n";
		for (int i = 0; i < 8; i++) {
			cout << i + 1 << " ";
			for (int j = 0; j < 8; j++) {
				if (Board[i][j].piece) {
					if (Board[i][j].piece->getTeam() == "black") {
						cout << char(tolower(typeToChar[Board[i][j].piece->getType()])) << " ";
					}
					else {
						cout << typeToChar[Board[i][j].piece->getType()] << " ";
					}
				}
				else {
					cout << "  ";
				}
			}
			cout << "\n";
		}
	}
};