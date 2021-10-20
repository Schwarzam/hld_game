//
// Created by gusta on 15/10/2021.
//


#include <iostream>
#include <valarray>
#include "Player.h"

Player::Player(){
//    if (!_texture.loadFromFile("media/chapcahpacete.png"))
//    {
//        //Error
//    }

    _ptexture = Assets::Acquire("personagem");

    _sprite.setTexture(*_ptexture);
    _sprite.setOrigin(sf::Vector2f(_ptexture->getSize().x/2, _ptexture->getSize().y));
    _sprite.setPosition(216, 174);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

void Player::processEvents() {
    movement = sf::Vector2f(0, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movement.y -= velocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movement.y += velocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x -= velocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += velocity;
    }

    if (movement.x != 0 && movement.y != 0){
        movement.x = movement.x / sqrt(2);
        movement.y = movement.y / sqrt(2);
    }

    float deltaTime = clock.restart().asSeconds();

    sf::Vector2f pos = get_position() + movement * deltaTime;
    if(TileMap::validatePos(sf::Vector2f(pos.x, pos.y))){
        _sprite.move(movement * deltaTime);
    };
}

sf::Vector2f Player::get_position() {
    return _sprite.getPosition();
}


