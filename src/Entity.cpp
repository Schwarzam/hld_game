//
// Created by gusta on 19/10/2021.
//

#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>

Entity::Entity(const std::string& name){
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

Entity::Entity(const std::string &name, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;

    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = _ptexture->getSize().x / float(imageCount.x);
    uvRect.height = _ptexture->getSize().y / float(imageCount.y);
}

