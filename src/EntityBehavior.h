//
// Created by gusta on 26/10/2021.
//

#ifndef GAME_ENTITYBEHAVIOR_H
#define GAME_ENTITYBEHAVIOR_H


#include <SFML/Graphics/Rect.hpp>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <SFML/System/Clock.hpp>

class EntityBehavior {
public:
    void animation();
    void updateAnimation();

    void chooseBehavior();

private:
    sf::Vector2u currentImage;
    sf::Clock clock;

    float totalTime;
    float switchTime;
    float animationTime;

protected:
    std::string entityName;

    nlohmann::json animation_json;

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


#endif //GAME_ENTITYBEHAVIOR_H
