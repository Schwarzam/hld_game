//
// Created by gustavo on 02/10/2021.
//

#include <cmath>
#include "Player.h"


Player::Player() : ActionTarget(Configuration::playerInputs),
    _shape(sf::Vector2f(32,32)),
    _isMoving(false),
    _rotation(0){

    _shape.setFillColor(sf::Color::Blue);
    _shape.setOrigin(16,16); //Ancora da imagem

    bind(Configuration::PlayerInputs::W,[this](const sf::Event&){
        _isMoving = true;
    });

    bind(Configuration::PlayerInputs::A,[this](const sf::Event&){
        _rotation-= 1;
    });

    bind(Configuration::PlayerInputs::D,[this](const sf::Event&){
        _rotation+= 1;
    });
}

void Player::update(sf::Time deltaTime) {
    float seconds = deltaTime.asSeconds();
    if (_rotation != 0){
        float angle = _rotation*180*seconds;
        _shape.rotate(angle);
    }

    if(_isMoving){
        float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
        _velocity += sf::Vector2f (std::cos(angle), std::sin(angle)) * 60.f * seconds;
    }
    _shape.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_shape, states);
}

void Player::processEvents(){
    _isMoving = false;
    _rotation = 0;

    ActionTarget::processEvents();
}
