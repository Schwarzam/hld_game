#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>

int main(){
    Game game;
    game.run();

    std::cin.get();

    return 0;
}