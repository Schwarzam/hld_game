//
// Created by gusta on 15/10/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Player : public sf::Drawable {
public:
    Player();

private:

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_PLAYER_H
