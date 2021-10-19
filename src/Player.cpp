//
// Created by gusta on 15/10/2021.
//


#include <iostream>
#include <valarray>
#include "Player.h"

Player::Player(TileMap* map) : map(map) {
    if (!_texture.loadFromFile("media/chapcahpacete.png"))
    {
        //Error
    }
    _sprite.setTexture(_texture);
    _sprite.setOrigin(sf::Vector2f(-200.f, -100.f));
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

    float deltaTime = clock.restart().asSeconds();

    if (movement.x != 0 && movement.y != 0){
        movement.x = movement.x / sqrt(2);
        movement.y = movement.y / sqrt(2);
    }

    if(map->validatePos(sf::Vector2f(movement.x, movement.y))){
        _sprite.move(movement * deltaTime);
    };
}

sf::Vector2f Player::get_position() {
    return _sprite.getPosition();
}

Player::Player() = default;



