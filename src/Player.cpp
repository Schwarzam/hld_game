//
// Created by gusta on 15/10/2021.
//


#include <iostream>
#include <valarray>
#include "Player.h"

Player::Player() {
    if (!texture.loadFromFile("media/chapcahpacete.png"))
    {
        //Error
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(-200.f, -100.f));
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Player::processEvents(const sf::Event& event) {
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

    sprite.move(movement * deltaTime);
}

