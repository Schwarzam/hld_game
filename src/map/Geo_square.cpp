//
// Created by gustavo on 10/10/2021.
//

#include <cmath>
#include "Geo_square.h"


Geo_square::Geo_square(float scale) : _scale(scale), _width(1.5), _height(1.5)
{
    _shape.setPointCount(4);

    _shape.setPoint(0,sf::Vector2f(0,0));
    _shape.setPoint(1,sf::Vector2f(0,_height));
    _shape.setPoint(2,sf::Vector2f(_width,_height));
    _shape.setPoint(3,sf::Vector2f(_width,0));

    _shape.setOrigin(_width/2.0,_height/2.0);
    _shape.setScale(scale,scale);
}

Geo_square::Geo_square(float scale, float width, float height) : _scale(scale), _height(height), _width(width) {
}

sf::Vector2f Geo_square::mapCoordsToPixel(const sf::Vector2i &coord) const {
    return sf::Vector2f(coord.x * _scale * _width,
                       coord.y * _scale * _height);
}

sf::Vector2i Geo_square::mapPixelToCoords(const sf::Vector2f &pos) const {
    return round(sf::Vector2f(pos.x/_scale / _width,
                              pos.y/_scale / _height));
}

Geo_square *Geo_square::factory(const std::string &name, int scale) {
    Geo_square* geo = nullptr;
    geo = new Geo_square(scale);
    return geo;
}

const sf::ConvexShape &Geo_square::getShape() const {
    return _shape;
}

float Geo_square::getScale()const
{
    return _scale;
}

sf::IntRect Geo_square::getTextureRect(const sf::Vector2i &pos) const {
    sf::Vector2f p = mapCoordsToPixel(pos);
    return sf::IntRect(p.x,
                       p.y,
                       _width * _scale,
                       _height * _scale);
}

sf::Vector2i Geo_square::round(const sf::Vector2f &pos) const {
    sf::Vector2f res = pos;
    if(res.x>=0)
        res.x+=0.5;
    else
        res.x-=0.5;

    if(res.y>=0)
        res.y+=0.5;
    else
        res.y-=0.5;

    return sf::Vector2i(res.x,res.y);
}

int Geo_square::distance(const sf::Vector2i &p1, const sf::Vector2i &p2) const {
    float x = p1.x - p2.x;
    x = x*x;

    float y = p1.y - p2.y;
    y = y*y;

    return std::ceil(sqrt(x + y));
}


