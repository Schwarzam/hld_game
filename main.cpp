#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

int main(int argc,char* argv[])
{



    Game game;
    bool x = game.startMap();

    game.startEntity("media/fantasma.png");

    std::cout << x << std::endl;
    game.runWithMinimumTimeSteps();

    return 0;
}