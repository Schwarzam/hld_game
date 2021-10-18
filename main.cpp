#include <SFML/Graphics.hpp>
#include "src/Game.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

int main(int argc,char* argv[])
{
    std::ifstream i("maps/init.json");
    nlohmann::json j;
    i >> j;

    auto z = j["map"]["tiles"][0]["width"].get<int>();

    Game game;
    bool x = game.startMap();
    std::cout << x << std::endl;
    game.runWithMinimumTimeSteps();

    return 0;
}