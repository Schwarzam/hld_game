//
// Created by gustavo on 02/10/2021.
//

#include <cmath>
#include "Player.h"

Player::Player() : ActionTarget(Configuration::playerInputs)
        ,_is_moving(false)
        ,_rotation(0)
{
    _ship.setTexture(Configuration::textures.get(Configuration::Textures::Player));
    _ship.setOrigin(49.5,37.5);

    bind(Configuration::PlayerInputs::W,[this](const sf::Event&){
        moving_up = true;
    });

    bind(Configuration::PlayerInputs::A,[this](const sf::Event&){
        moving_left = true;
    });

    bind(Configuration::PlayerInputs::S,[this](const sf::Event&){
        moving_down = true;
    });

    bind(Configuration::PlayerInputs::D,[this](const sf::Event&){
        moving_right = true;
    });
}

void Player::processEvents()
{
    _is_moving = false;

    moving_up = false;
    moving_right = false;
    moving_down = false;
    moving_left = false;

    _rotation = 0;
    ActionTarget::processEvents();
}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();

    if(_rotation != 0)
    {
        float angle = _rotation*180*seconds;
        _ship.rotate(angle);
    }

//    if(_is_moving)
//    {
//        float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;
//        _velocity += sf::Vector2f(std::cos(angle),std::sin(angle)) * 60.f * seconds;
//    }
    _velocity =  sf::Vector2f(0, 0);
    if (moving_up){
        _velocity = sf::Vector2f(0,-50);
    }
    if (moving_down){
        _velocity = sf::Vector2f(0,50);
    }
    if (moving_right){
        _velocity = sf::Vector2f(50,0);
    }
    if (moving_left){
        _velocity = sf::Vector2f(-50,0);
    }

    _ship.move(seconds * _velocity * 3.0f);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_ship,states);
}
