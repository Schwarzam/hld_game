//
// Created by gusta on 15/10/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

#include "TileMap.h"
#include "Entity.h"

class Player : public Entity {
public:
    Player();
    void processEvents() override;
    void updateAnimation() override;
    sf::Vector2f get_position();


private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    float velocity = 120;
    sf::Vector2f movement = sf::Vector2f(0, 0);


    std::shared_ptr<sf::Texture> pTex;

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


#endif //GAME_PLAYER_H
