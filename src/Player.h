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
#include <stack>
#include <SFML/System/Clock.hpp>
#include "TileMap.h"

class Player : public sf::Drawable {
public:
    Player();
    explicit Player(TileMap* map);
    void processEvents();
    sf::Vector2f get_position();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Texture texture;
    sf::Sprite sprite;

    float velocity = 100;
    sf::Vector2f movement = sf::Vector2f(0, 0);
    sf::Clock clock;

    TileMap* map{};
};


#endif //GAME_PLAYER_H
