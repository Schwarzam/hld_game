//
// Created by gusta on 01/10/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Thread.hpp>

#include "TileMap.h"
#include "Player.h"
#include "Entity.h"
#include "Assets.h"
#include "helper/Fps.h"
#include "GameManager.h"

class Game : public GameManager
{
public:
    //non copyable class
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    Game(); //< constructor

    void viewCalculator();

    void runWithMinimumTimeSteps(int minimum_frame_per_seconds=30);
    bool startMap();
    void startSpawns();
    TileMap map;


private:
    void setZoom(float z);
    void processEvents();//< Process events
    void update(); //< do some updates
    void render();//< draw all the stuff
    Assets _assets;

    float zoom = 1;
    sf::RenderWindow _window; //< the window use to display the game
    Player _player;
    sf::View view;

    FPS fps;
};

#endif //GAME_GAME_H
