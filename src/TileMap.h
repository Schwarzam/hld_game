//
// Created by gusta on 14/10/2021.
//

#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H


#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <string>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, sf::Vector2u utilSize, const int* tiles, unsigned int width, unsigned int height);

    bool validatePos(sf::Vector2f pos);


private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Vector2f offset;
};

#endif //GAME_TILEMAP_H
