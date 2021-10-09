//
// Created by gustavo on 02/10/2021.
//
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Action.h"
#include "ActionTarget.h"
#include "ActionMap.h"

class Player : public sf::Drawable, public ActionTarget<int> {
    public:
        Player(const Player&) = delete;
        Player& operator = (const Player&) = delete;
        Player();

        template<typename ... Args>
        void setPosition(Args&& ... args) {
            _shape.setPosition(std::forward<Args>(args) ...);
        };
        void processEvents();

        void update(sf::Time deltaTime);

        enum PlayerInputs {Up, Left, Right};

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::RectangleShape _shape;
        sf::Vector2f _velocity;

        bool _isMoving;
        int _rotation;

        static ActionMap<int> _playerInputs;
};


#endif //GAME_PLAYER_H
