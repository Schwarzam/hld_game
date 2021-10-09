//
// Created by gustavo on 02/10/2021.
//

#include <cmath>
#include "Player.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

Player::Player() : _shape(sf::Vector2f(32,32)){
    _shape.setFillColor(sf::Color::Blue);
    _shape.setOrigin(16,16); //Ancora da imagem
}

void Player::update(sf::Time deltaTime) {
    float seconds = deltaTime.asSeconds();
    if (rotation != 0){
        float angle = rotation*180*seconds;
        _shape.rotate(angle);
    }

    if(isMoving){
        float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
        _velocity += sf::Vector2f (std::cos(angle), std::sin(angle)) * 60.f * seconds;
    }
    _shape.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_shape, states);
}

void Player::processEvents(){
    rotation = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        isMoving = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        isMoving = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        isMoving = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        isMoving = true;
    }
}
