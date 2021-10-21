//
// Created by gusta on 19/10/2021.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include "Assets.h"

class Entity : public sf::Drawable, public sf::Transform {
public:
    Entity() = default;
    explicit Entity(const std::string& name);
    explicit Entity(const std::string& name, sf::Vector2u imageCount, float switchTime);

    void animation(sf::Vector2u imageCount, float switchTime);
    void updateAnimation(const int& row, const bool& stopped = false);

    float getPosY();
    void setPosition();
    void update();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::Clock clock;

    float totalTime;
    float switchTime;
    float animationTime;

protected:
    std::shared_ptr<sf::Texture> _ptexture;
    sf::Sprite _sprite;
};


#endif //GAME_ENTITY_H
