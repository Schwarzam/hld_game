//
// Created by gustavo on 02/10/2021.
//
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Action.hpp"
#include "ActionTarget.h"
#include "ActionMap.h"

#include "Configuration.h"
class Player : public sf::Drawable , public ActionTarget<int>
{
public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player();

    template<typename ... Args>
    void setPosition(Args&& ... args);

    void processEvents();

    void update(sf::Time deltaTime);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Sprite          _ship;
    sf::Vector2f        _velocity;

    bool _is_moving;
    int _rotation;

    bool moving_up = false;
    bool moving_down = false;
    bool moving_left = false;
    bool moving_right = false;
};

#include "Player.tpp"
#endif //GAME_PLAYER_H
