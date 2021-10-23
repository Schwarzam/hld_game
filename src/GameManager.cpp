//
// Created by gusta on 23/10/2021.
//

#include "GameManager.h"

void GameManager::startEntity(const std::string& name) {
    entities.emplace_back(std::pair(0.0, new Entity(name)));
}

void GameManager::sortRender() {
    std::sort(entities.begin(), entities.end());

    for (auto& i : entities){
        i.first = i.second->getPosY();
    }
}