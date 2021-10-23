//
// Created by gusta on 23/10/2021.
//

#ifndef GAME_GAMEMANAGER_H
#define GAME_GAMEMANAGER_H


#include <vector>
#include "Entity.h"

class GameManager {
public:
    GameManager() = default;

    static Entity *startEntity(const std::string& name);
    static void sortRender();

    static bool validatePos(sf::Sprite _sprite, const sf::Vector2f &movement);

private:


protected:
    static std::vector<std::pair<float, Entity*>> entities;
};


#endif //GAME_GAMEMANAGER_H
