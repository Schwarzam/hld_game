//
// Created by gusta on 19/10/2021.
//

#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <fstream>

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


Entity::Entity(const std::string &name, sf::Vector2u imageCount, float switchTime) : entityName(name) {
    _ptexture = Assets::Acquire(name);

    this->imageCount = imageCount;
    this->switchTime = switchTime;

    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = _ptexture->getSize().x / float(imageCount.x);
    uvRect.height = _ptexture->getSize().y / float(imageCount.y);
}

void Entity::animation() {
    std::ifstream file(entityName);
    file >> animation_json;

    this->imageCount = sf::Vector2u(animation_json["GRID"]["x"].get<int>(), animation_json["GRID"]["y"].get<int>());
    this->switchTime = 1.0f/animation_json["FPS"].get<float>();

    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = _ptexture->getSize().x / float(imageCount.x);
    uvRect.height = _ptexture->getSize().y / float(imageCount.y);

    _sprite.setTextureRect(uvRect);
    _sprite.setOrigin(uvRect.width/2, uvRect.height);
}

void Entity::updateAnimation(const int& row, const bool& stopped) {
    currentImage.y = row;

    animationTime = clock.restart().asSeconds();
    if (animationTime > 1){
        animationTime = 1;
    }

    totalTime += animationTime;

    if (totalTime >= switchTime){
        totalTime -= switchTime;
        if (!stopped){
            currentImage.x ++;
        }

        if (currentImage.x >= imageCount.x){
            currentImage.x = 0;
        }
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.top = currentImage.y * uvRect.height;

        _sprite.setTextureRect(uvRect);
    }
}

