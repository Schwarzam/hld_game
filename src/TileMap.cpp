//
// Created by gusta on 14/10/2021.
//

#include <cstring>
#include <fstream>

#include "TileMap.h"

bool TileMap::load(const std::string &tileset, sf::Vector2u tileSize, sf::Vector2u utilSize, const int *tiles,
                   unsigned int width, unsigned int height) {
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * utilSize.x, j * utilSize.y);
            quad[1].position = sf::Vector2f((i + 1) * utilSize.x, j * utilSize.y);
            quad[2].position = sf::Vector2f((i + 1) * utilSize.x, (j * utilSize.y) + tileSize.y);
            quad[3].position = sf::Vector2f(i * utilSize.x, (j * utilSize.y) + tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}

bool TileMap::validatePos(sf::Vector2f pos) {



    return true;
}

bool TileMap::load(std::string map) {
    std::ifstream i(map);
    i >> j1;

    m_tileset.loadFromFile("media/bloco_novo2_G.png");
    m_vertices.setPrimitiveType(sf::Quads);

    int width = j1["map"]["size"]["width"].get<int>();
    int height = j1["map"]["size"]["height"].get<int>();

    m_vertices.resize(width * height * 4);

    int tileNumber = 0;
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // find its position in the tileset texture
            int tu = 0;
            int tv = 0;

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            sf::Vector2i utilSize = sf::Vector2i(j1["map"]["tiles"][tileNumber]["utilx"].get<int>(), j1["map"]["tiles"][tileNumber]["utily"].get<int>());
            sf::Vector2i tileSize = sf::Vector2i(j1["map"]["tiles"][tileNumber]["width"].get<int>(), j1["map"]["tiles"][tileNumber]["height"].get<int>());

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * utilSize.x, j * utilSize.y);
            quad[1].position = sf::Vector2f((i + 1) * utilSize.x, j * utilSize.y);
            quad[2].position = sf::Vector2f((i + 1) * utilSize.x, (j * utilSize.y) + tileSize.y);
            quad[3].position = sf::Vector2f(i * utilSize.x, (j * utilSize.y) + tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

            tileNumber ++;
        }

    return false;
}
