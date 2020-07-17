//Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameManager.cpp"

int main()
{

    GameManager Game;

    Game.resetGame();
    Game.startGame();

    return 0;
}

