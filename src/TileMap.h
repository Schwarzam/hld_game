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
#include <nlohmann/json.hpp>
#include "Assets.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load_file(const std::string& name);
    static bool validatePos(const sf::Vector2f& pos);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Vector2f offset;
    std::shared_ptr<sf::Texture> m_tileset;

    static nlohmann::json j1;
};

#endif //GAME_TILEMAP_H
