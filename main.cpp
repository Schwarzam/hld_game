#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>
#include "src/Configuration.h"
#include "src/Game.h"

int main(int argc,char* argv[])
{
    Configuration::initialize();

    Game game;
    game.runWithMinimumTimeSteps();

    return 0;
}