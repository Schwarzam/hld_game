//
// Created by gusta on 19/10/2021.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <map>
#include "Assets.h"
#include "EntityBehavior.h"
#include <nlohmann/json.hpp>

class Entity : public sf::Drawable, public sf::Transform, public EntityBehavior {
public:
    Entity() = default;
    explicit Entity(const std::string& name);

    float getPosY();
    sf::Vector2f getPosition();
    sf::Vector2f getFeetPosition();

    void move(sf::Vector2f correction);

    const sf::Sprite& getSprite();
    const sf::Sprite& getHitBoxSprite();

    void setPosition(const sf::Vector2f& pos);
    virtual void processEvents();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

protected:
    sf::Clock MovementClock;
};


#endif //GAME_ENTITY_H
