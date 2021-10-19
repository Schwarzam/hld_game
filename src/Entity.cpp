//
// Created by gusta on 19/10/2021.
//

#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>

Entity::Entity(std::string name){
    _texture.loadFromFile(name);
    _sprite.setTexture(_texture);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

float Entity::getPosY() {
    return _sprite.getPosition().y;
}

