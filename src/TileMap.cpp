//
// Created by gusta on 14/10/2021.
//

#include <cstring>
#include <fstream>
#include "TileMap.h"

nlohmann::json TileMap::j1;

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = m_tileset.get();

    // draw the vertex array
    target.draw(m_vertices, states);
}

bool TileMap::validatePos(const sf::Vector2f& pos) {
    int arrPos = int(pos.x/j1["tilewidth"].get<int>()) + ( int(pos.y/j1["tileheight"].get<int>()) * j1["width"].get<int>());

    if (j1["layers"][0]["data"][arrPos] != 0){
        return true;
    }
    return false;
}


bool TileMap::load_file(const std::string &name) {
    std::ifstream file(name);
    file >> j1;

    m_tileset = Assets::Acquire("blocos");
    m_vertices.setPrimitiveType(sf::Quads);

    int width = j1["width"].get<int>();
    int height = j1["height"].get<int>();

    m_vertices.resize(width * height * 4);

    sf::Vector2i utilSize = sf::Vector2i(j1["tilewidth"].get<int>(), j1["tileheight"].get<int>());
    sf::Vector2i tileSize = sf::Vector2i(j1["tilesizex"].get<int>(), j1["tilesizey"].get<int>());

    for (int i = 0; i < width; ++i){ //One column by time
        int tileNumber = i;
        for (int j = 0; j < height; ++j)
        {
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            if (j1["layers"][0]["data"][tileNumber].get<int>() != 0){
                // define its 4 corners
                quad[0].position = sf::Vector2f(i * utilSize.x - 0.1f, j * utilSize.y - 0.1f);
                quad[1].position = sf::Vector2f((i + 1) * utilSize.x - 0.1f, j * utilSize.y - 0.1f);
                quad[2].position = sf::Vector2f((i + 1) * utilSize.x, (j * utilSize.y) + tileSize.y);
                quad[3].position = sf::Vector2f(i * utilSize.x, (j * utilSize.y) + tileSize.y);

                int tu = j1["layers"][0]["data"][tileNumber].get<int>() - 1;
                int tv = 0;

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            };

            tileNumber = tileNumber + width;
        }
    }

    return false;
}

nlohmann::json TileMap::getObjects() {
    return j1["layers"][1];
}
