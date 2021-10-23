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

    void startEntity(const std::string& name);
    void updatePairRender();
    void sortRender();
private:


protected:
    std::vector<std::pair<float, Entity*>> entities;

};


#endif //GAME_GAMEMANAGER_H
