//
// Created by gusta on 19/10/2021.
//

#ifndef GAME_ASSETS_H
#define GAME_ASSETS_H


#include <string>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>
#include <memory>


class Assets {
public:
    static std::shared_ptr<sf::Texture> Acquire(const std::string& name );
    static void Murder();

private:
    static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
};



#endif //GAME_ASSETS_H
