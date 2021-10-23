//
// Created by gusta on 23/10/2021.
//

#include "GameManager.h"

#include <cmath>
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

bool GameManager::validatePos(Entity *ent, sf::Sprite& _sprite, const sf::Vector2f &movement) {
    sf::Vector2f pos = _sprite.getPosition() + movement;

    sf::Sprite spriteCopy = _sprite;
    if(TileMap::validatePos(sf::Vector2f(pos.x, pos.y))){
        int colliding = false;

        spriteCopy.move(movement);

        while(!colliding){
            for (std::pair<float, Entity *> entity : entities) {
                Entity *e = entity.second;
                if (entity.second != ent) {
                    colliding = Collision::PixelPerfectTest(entity.second->getSprite(), spriteCopy) | colliding;
                    if (colliding){
                        float _ang = std::atan2(
                                entity.second->getCenterPos().y - ent->getCenterPos().y,
                                entity.second->getCenterPos().x - ent->getCenterPos().x) *
                                        (180 / 3.1428f);

                        _sprite.move(sf::Vector2f(0.1f * std::sin(_ang), 0.1f * std::cos(_ang)));
                    }
                }
            }
            if (!colliding){
                return true;
            }else{

            }
        }

        return colliding;
    }else{
        return false;
    };
}


