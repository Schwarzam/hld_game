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
    virtual void updateAnimation();

    void chooseBehavior();
    std::string entityType;
private:


protected:
    sf::Vector2u currentImage;
    sf::Clock animation_clock;

    float totalTime;
    float switchTime;
    float animationTime;
    float moveDuration = 0;

    std::string entityName;

    nlohmann::json animation_json;

    std::shared_ptr<sf::Texture> _ptexture;

    sf::IntRect uvRect;
    sf::Sprite _sprite;

    sf::IntRect uvRectFeet;
    sf::Sprite _feetSprite;

    nlohmann::json actualMove;
    int frameNum = 0;
    int moveProbabilites = 0;
};


#endif //GAME_ENTITYBEHAVIOR_H
