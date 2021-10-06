//
// Created by gusta on 01/10/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Player.h"

class Game{
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow _window;
    Player  _player;

    void run(int frame_per_seconds);
};




#endif //GAME_GAME_H
