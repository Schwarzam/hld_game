//
// Created by gusta on 15/10/2021.
//


#include <iostream>
#include <valarray>
#include "Player.h"
#include "GameManager.h"

Player::Player(){
//    if (!_texture.loadFromFile("media/chapcahpacete.png"))
//    {
//        //Error
//    }

    _ptexture = Assets::Acquire("chapacete_sheet");
    entityName = "chapacete_sheet";

    _sprite.setTexture(*_ptexture);
    //_sprite.setOrigin(sf::Vector2f(_ptexture->getSize().x/2, _ptexture->getSize().y));
    _sprite.setPosition(216, 174);

    animation();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

void Player::processEvents() {
    movement = sf::Vector2f(0, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movement.y -= velocity;
        direction = UP;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movement.y += velocity;
        direction = DOWN;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x -= velocity;
        direction = LEFT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += velocity;
        direction = RIGHT;
    }

    if (lastDirection == UP && movement.y < 0 && movement.x != 0){
        direction = UP;
    }else if (lastDirection == DOWN && movement.y > 0 && movement.x != 0){
        direction = DOWN;
    }

    if (movement.x != 0 && movement.y != 0){
        movement.x = movement.x / sqrt(2);
        movement.y = movement.y / sqrt(2);
    }else if(movement.x == 0 && movement.y == 0){
        if (direction % 2 == 0){
            direction += STOP;
        }
    }

    lastDirection = direction;
    updateAnimation();

    float deltaTime = clock.restart().asSeconds();

    sf::Vector2f pos = get_position() + movement * deltaTime;
    if (GameManager::validatePos(_sprite, movement * deltaTime)){
        _sprite.move(movement * deltaTime);
    };
}

sf::Vector2f Player::get_position() {
    return _sprite.getPosition();
}


