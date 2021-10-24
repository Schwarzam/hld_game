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
    sf::Vector2f get_position();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    float velocity = 120;
    sf::Vector2f movement = sf::Vector2f(0, 0);
    sf::Clock clock;

    std::shared_ptr<sf::Texture> pTex;
};


#endif //GAME_PLAYER_H
