//
// Created by gusta on 15/10/2021.
//


#include <iostream>
#include <valarray>
#include "Player.h"
#include "GameManager.h"

Player::Player() {
    _ptexture = Assets::Acquire("chapacete_sheet");
    entityName = "chapacete_sheet";
    entityType = "player";

    _sprite.setTexture(*_ptexture);
    //_sprite.setOrigin(sf::Vector2f(_ptexture->getSize().x/2, _ptexture->getSize().y));
    _feetSprite.setTexture(*_ptexture);

    animation();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_feetSprite, states);
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

    float deltaTime = MovementClock.restart().asSeconds();

    sf::Vector2f pos = get_position() + movement * deltaTime;
    if (GameManager::validatePos(this, _feetSprite, movement * deltaTime)){
        move(movement * deltaTime);
    };
}

void Player::updateAnimation() {
    std::string action = actionsMap.at(direction);
    currentImage.y = animation_json[action]["LINHA"]; //ROW

    animationTime = animation_clock.restart().asSeconds();
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

sf::Vector2f Player::get_position() {
    return _sprite.getPosition();
}


