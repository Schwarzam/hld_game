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
#include <nlohmann/json.hpp>

class Entity : public sf::Drawable, public sf::Transform {
public:
    Entity() = default;
    explicit Entity(const std::string& name);

    void animation();
    void updateAnimation();

    float getPosY();
    sf::Vector2f getPosition();
    const sf::Sprite& getSprite();

    void setPosition(const sf::Vector2f& pos);
    virtual void processEvents();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Vector2u currentImage;
    sf::Clock clock;

    float totalTime;
    float switchTime;
    float animationTime;

    nlohmann::json animation_json;

protected:
    std::string entityName;

    std::shared_ptr<sf::Texture> _ptexture;

    sf::IntRect uvRect;
    sf::Sprite _sprite;

    sf::IntRect uvRectFeet;
    sf::Sprite _feetSprite;

    int direction = UP;
    int lastDirection = UP;

    enum actions : int {
        STOP = 1,
        UP = 2,
        DOWN = 4,
        RIGHT = 6,
        LEFT = 8,
    };

    std::unordered_map<int, std::string> actionsMap{
        {UP, "UP"},
        {DOWN, "DOWN"},
        {RIGHT, "RIGHT"},
        {LEFT, "LEFT"},
        {STOP, "STILL"},
        {STOP + UP, "STOP_UP"},
        {STOP + DOWN, "STOP_DOWN"},
        {STOP + LEFT, "STOP_LEFT"},
        {STOP + RIGHT, "STOP_RIGHT"},
    };
};


#endif //GAME_ENTITY_H
