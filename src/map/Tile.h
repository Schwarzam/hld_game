//
// Created by gusta on 11/10/2021.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H


#include <SFML/Graphics/Drawable.hpp>
#include "Geo_square.h"

class Tile : public sf::Drawable
{
public:
    Tile(const Tile&) = delete;
    Tile& operator=(const Tile&) = delete;

    Tile(Tile&&) = default;
    Tile& operator=(Tile&&) = default;

    Tile(const Geo_square& geometry,const sf::Vector2i& pos);
    ~Tile() override;

    void setFillColor(const sf::Color &color);

    void setPosition(float x,float y);
    void setPosition(const sf::Vector2f& pos);

    sf::Vector2f getPosition()const;

    void setTexture(const sf::Texture *texture,bool resetRect=false);
    void setTextureRect(const sf::IntRect& rect);

    sf::FloatRect getGlobalBounds()const;
    sf::FloatRect getLocalBounds()const;


protected:
    sf::ConvexShape _shape;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
};


#endif //GAME_TILE_H
