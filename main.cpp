#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>
#include "src/Game.h"

int main(int argc,char* argv[])
{
    Game game;
    game.runWithMinimumTimeSteps();

    return 0;
}