//
// Created by gusta on 01/10/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "TileMap.h"
#include "Player.h"
#include "Entity.h"
#include "Assets.h"

class Game
{
public:
    //non copyable class
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    Game(); //< constructor

    void runWithFixedTimeSteps(int frame_per_seconds=60);
    void runWithVariableTimeSteps();
    void runWithMinimumTimeSteps(int minimum_frame_per_seconds=30);

    void updatePairRender();
    void sortRender();

    void startEntity(const std::string& name);
    bool startMap();
    TileMap map;

private:
    void processEvents();//< Process events
    void update(sf::Time deltaTime); //< do some updates
    void render();//< draw all the stuff
    Assets _assets;

    sf::RenderWindow _window; //< the window use to display the game
    Player _player;
    sf::View view;
    std::vector<std::pair<float, Entity*>> entities;
};

#endif //GAME_GAME_H
