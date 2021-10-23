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
        float _ang;

        for (std::pair<float, Entity *> entity : entities) {
            Entity *e = entity.second;
            if (entity.second != ent) {
                colliding = Collision::PixelPerfectTest(entity.second->getSprite(), spriteCopy) | colliding;
                if (colliding){
                    _ang = std::atan2(
                            entity.second->getPosition().y - ent->getPosition().y,
                            entity.second->getPosition().x - ent->getPosition().x) *
                                    (180 / 3.1428f);
                }
            }
        }
        if (!colliding){
            return true;
        }else{
            sf::Vector2f correction = sf::Vector2f(0.1f * std::sin(_ang), 0.1f * std::cos(_ang));
            sf::Vector2f p = _sprite.getPosition() + correction;
            if (TileMap::validatePos(p))
                _sprite.move(correction);
        }

        return colliding;
    }else{
        return false;
    };
}


