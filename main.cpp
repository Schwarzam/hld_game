#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

int main(int argc,char* argv[])
{
    Game game;
    game.startMap();
    game.startSpawns();

    game.runWithMinimumTimeSteps();

    return 0;
}