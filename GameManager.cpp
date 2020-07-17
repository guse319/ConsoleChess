#include "BoardManager.cpp"
#include <map>
#include <string>
using namespace std;

class GameManager {
private:
	
	string playerOne; // white pieces

	string playerTwo; // black pieces

	int turn; // 1 or 2, representing which player's turn it is

	BoardManager Board;

	bool gameOver = false;

	map<char, int> xCast {
		{'a', 0},
		{'b', 1},
		{'c', 2},
		{'d', 3},
		{'e', 4},
		{'f', 5},
		{'g', 6},
		{'h', 7},
	};

public:

	void resetGame() {
		Board.clearBoard();
		Board.setBoard();
		Board.printBoard();
		gameOver = false;
		turn = 1;
	}

	void startGame() {
		while (!gameOver) {
			processTurn();
		}
	}

	void processTurn() {
		int xStart;
		int yStart;
		int xDest;
		int yDest;
		string startPoint;
		string endPoint;

		cout << "Input turn: ";
		cin >> startPoint >> endPoint;

		castPoint(startPoint, yStart, xStart);
		castPoint(endPoint, yDest, xDest);

		if (!Board.makeMove(xStart, yStart, xDest, yDest)) {
			cout << "Invalid move. Input turn: ";
		}

		Board.printBoard();
	}

	void castPoint(string point, int& x, int& y) {
		x = xCast[point[0]];
		string y1 = point.substr(1, 1);
		y = stoi(y1) - 1;
	}

};