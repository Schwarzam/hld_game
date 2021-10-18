#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>
#include <nlohmann/json.hpp>

int main(int argc,char* argv[])
{
    Game game;
    bool x = game.startMap();
    std::cout << x << std::endl;
    game.runWithMinimumTimeSteps();

    return 0;
}