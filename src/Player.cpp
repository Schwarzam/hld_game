//
// Created by gusta on 15/10/2021.
//


#include <iostream>
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
