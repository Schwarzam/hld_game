//
// Created by gusta on 23/10/2021.
//

#include "GameManager.h"
#include "TileMap.h"
#include "Collision.h"

std::vector<std::pair<float, Entity*>> GameManager::entities;

Entity *GameManager::startEntity(const std::string& name) {
    auto *ent = new Entity(name);
    entities.emplace_back(std::pair(0.0, ent));
    return ent;
}

void GameManager::sortRender() {
    std::sort(entities.begin(), entities.end());

    for (auto& i : entities){
        i.first = i.second->getPosY();
    }
}

bool GameManager::validatePos(sf::Sprite _sprite, const sf::Vector2f &movement) {
    sf::Vector2f pos = _sprite.getPosition() + movement;
    if(TileMap::validatePos(sf::Vector2f(pos.x, pos.y))){
        int colliding = false;

        _sprite.move(movement * 10.0f);
        for (std::pair<float, Entity *> entity : entities){
            colliding = !Collision::PixelPerfectTest(entity.second->getSprite(), _sprite) | colliding;
        }
        return colliding;
    }else{
        return false;
    };
}


