//
// Created by gusta on 19/10/2021.
//

#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <fstream>
#include "GameManager.h"
#include <random>

Entity::Entity(const std::string& name) : entityName(name){
    _ptexture = Assets::Acquire(name);
    _sprite.setTexture(*_ptexture);
    _sprite.setOrigin(_ptexture->getSize().x/2, _ptexture->getSize().y);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

float Entity::getPosY() {
    return _sprite.getPosition().y;
}

void Entity::animation() {
    std::string o = "media/" + entityName + ".json";
    std::ifstream file("media/" + entityName + ".json");
    file >> animation_json;

    this->switchTime = 1.0f/animation_json["FPS"].get<float>();

    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = _ptexture->getSize().x / float(animation_json["GRID"]["x"].get<int>());
    uvRect.height = _ptexture->getSize().y / float(animation_json["GRID"]["y"].get<int>());

    _sprite.setTextureRect(uvRect);
    _sprite.setOrigin(uvRect.width/2, uvRect.height);

    //Feet only area to do collisions
    uvRectFeet.width = _ptexture->getSize().x / float(animation_json["GRID"]["x"].get<int>());
    uvRectFeet.height = animation_json["FEET_AREA"].get<int>();

    _feetSprite.setTextureRect(uvRectFeet);
    _feetSprite.setOrigin(uvRectFeet.width/2, uvRectFeet.height);
}

void Entity::updateAnimation() {
    std::string action = actionsMap.at(direction);
    currentImage.y = animation_json[action]["LINHA"]; //ROW

    animationTime = clock.restart().asSeconds();
    if (animationTime > 1){
        animationTime = 1;
    }

    totalTime += animationTime;

    if (totalTime >= switchTime){
        totalTime -= switchTime;

        currentImage.x ++;
        if (currentImage.x >= animation_json[action]["FRAMES"]){
            currentImage.x = animation_json[action]["COLUNA_INICIAL"];
        }

        uvRect.left = currentImage.x * uvRect.width;
        uvRect.top = currentImage.y * uvRect.height;
        _sprite.setTextureRect(uvRect);


        uvRectFeet.left = currentImage.x * uvRect.width;
        uvRectFeet.top = (currentImage.y + 1) * uvRect.height - uvRectFeet.height;

        _feetSprite.setTextureRect(uvRectFeet);
    }
}

const sf::Sprite &Entity::getSprite() {
    return _sprite;
}

void Entity::setPosition(const sf::Vector2f& pos) {
    if (GameManager::validatePos(this, _sprite, pos)){
        _sprite.setPosition(pos);
    };
}

sf::Vector2f Entity::getPosition() {
    return _sprite.getPosition();
}

void Entity::processEvents() {
    int k = rand() % 100 + 1;

    if (k < 10){
        if (GameManager::validatePos(this, _sprite, sf::Vector2f(0, .1))){
            _sprite.move(sf::Vector2f(0, 0.1));
        }
        direction = DOWN;
    }

    updateAnimation();
}



