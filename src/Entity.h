//
// Created by gusta on 19/10/2021.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Assets.h"

class Entity : public sf::Drawable, public sf::Transform {
public:
    Entity() = default;
    explicit Entity(const std::string& name);

    float getPosY();
    void setPosition();
    void update();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

protected:
    Assets* assets;

    std::shared_ptr<sf::Texture> _ptexture;
    sf::Sprite _sprite;
};


#endif //GAME_ENTITY_H
