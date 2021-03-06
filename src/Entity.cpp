//
// Created by gusta on 19/10/2021.
//

#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <fstream>
#include "GameManager.h"
#include <random>

Entity::Entity(const std::string& name){
    this->entityName = name;
    _ptexture = Assets::Acquire(name);
    _sprite.setTexture(*_ptexture);
    _sprite.setOrigin(_ptexture->getSize().x/2, _ptexture->getSize().y);

    _feetSprite.setTexture(*_ptexture);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

float Entity::getPosY() {
    return _sprite.getPosition().y;
}

const sf::Sprite &Entity::getHitBoxSprite() {
    return _feetSprite;
}

const sf::Sprite &Entity::getSprite() {
    return _sprite;
}

void Entity::setPosition(const sf::Vector2f& pos) {
    if (GameManager::validatePos(this, _sprite, pos)){
        _sprite.setPosition(pos);
        _feetSprite.setPosition(_sprite.getPosition());
    }
}

sf::Vector2f Entity::getPosition() {
    return _sprite.getPosition();
}

void Entity::processEvents() {
    if(actualMove.empty()){
        chooseBehavior();
    }

    float deltaTime = MovementClock.restart().asSeconds();

    sf::Vector2f movement = sf::Vector2f(10 * actualMove["moveX"].get<float>(), 10 * actualMove["moveY"].get<float>());
    if (GameManager::validatePos(this, _feetSprite, movement * deltaTime)){
        _sprite.move(movement * deltaTime);
        _feetSprite.setPosition(_sprite.getPosition());
    };

    updateAnimation();
}

sf::Vector2f Entity::getFeetPosition() {
    return _feetSprite.getPosition();
}

void Entity::move(sf::Vector2f movement) {
    _sprite.move(movement);
    _feetSprite.setPosition(_sprite.getPosition());
}





