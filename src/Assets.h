//
// Created by gusta on 19/10/2021.
//

#ifndef GAME_ASSETS_H
#define GAME_ASSETS_H


#include <string>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>


class Assets {
public:
    Assets();

    void load_all();
    static std::string get_path(std::string name);

private:
    std::vector<std::string> filenames;
    std::unordered_map<std::string, sf::Texture*> assets;
};


#endif //GAME_ASSETS_H
