//
// Created by gusta on 19/10/2021.
//

#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <fstream>
#include "GameManager.h"
#include <random>

Entity::Entity(const std::string& name) {
    this->entityName = name;
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

    chooseBehavior();
    updateAnimation();
}



