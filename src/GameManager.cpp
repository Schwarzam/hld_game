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
    Entity *entityCollided;
    if(TileMap::validatePos(sf::Vector2f(pos.x, pos.y))){
        spriteCopy.move(movement);
        float _ang;
        bool colliding;

        for (std::pair<float, Entity *> entity : entities) {
            Entity *e = entity.second;
            if (entity.second != ent) {
                colliding = !Collision::PixelPerfectTest(entity.second->getHitBoxSprite(), spriteCopy);
                colliding = Collision::CircleTest(entity.second->getHitBoxSprite(), spriteCopy);
                colliding = Collision::BoundingBoxTest(entity.second->getHitBoxSprite(), spriteCopy);

                if (colliding){
                    _ang = std::atan2(
                            entity.second->getFeetPosition().y - ent->getFeetPosition().y,
                            entity.second->getFeetPosition().x - ent->getFeetPosition().x) *
                                    (180 / 3.1428f);
                    entityCollided = entity.second;

                    float distanceI = sqrt(pow(ent->getFeetPosition().x - entity.second->getFeetPosition().x, 2) +
                            pow(ent->getFeetPosition().y - entity.second->getFeetPosition().y, 2) * 1.0);

                    float distanceF = sqrt(pow(spriteCopy.getPosition().x - entity.second->getFeetPosition().x, 2) +
                            pow(spriteCopy.getPosition().y - entity.second->getFeetPosition().y, 2) * 1.0);

                    if (distanceF > distanceI){

                    }
                    return false;
                }
            }
        }
        if (!colliding){
            return true;
        }else{
            //Se o entity esta se afastando do centro do outro, deixar mover livremente.


//            sf::Vector2f correction = sf::Vector2f(std::sin(_ang) * 0.1f, std::cos(_ang) * 0.1f);
//            sf::Vector2f p = _sprite.getPosition() + correction;
//            if (TileMap::validatePos(p))
//                ent->move(correction);
//            else{
//                correction = sf::Vector2f(std::cos(_ang) * 0.1f, std::sin(_ang) * 0.1f);
//                ent->move(correction);
//            }

            return false;
        }
        return colliding;
    }else{
        return false;
    };
}

void GameManager::gameEvents() {
    for (auto& entity : entities){
        sf::Vector2f position = entity.second->getPosition();

        for (auto& entity : entities){
            sf::Vector2f position = entity.second->getPosition();

        }
    }
}


