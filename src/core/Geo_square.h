//
// Created by gustavo on 10/10/2021.
//

#ifndef GAME_GEO_SQUARE_H
#define GAME_GEO_SQUARE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <iostream>

class Geo_square {
public:
    explicit Geo_square(float scale);
    Geo_square(float scale,float width, float height);
    virtual ~Geo_square() = default;

    virtual sf::Vector2f mapCoordsToPixel(const sf::Vector2i& coord) const;
    virtual sf::Vector2i mapPixelToCoords(const sf::Vector2f& pos) const;

    static Geo_square* factory(const std::string& name,int scale); //< factory
    const sf::ConvexShape& getShape() const;
    float getScale()const;

    virtual sf::IntRect getTextureRect(const sf::Vector2i& pos) const;

    virtual sf::Vector2i round(const sf::Vector2f& pos) const;
    virtual int distance(const sf::Vector2i& p1, const sf::Vector2i& p2) const;

protected:
    const float _scale;
    const float _width;
    const float _height;
    sf::ConvexShape _shape;
};

#endif //GAME_GEO_SQUARE_H
