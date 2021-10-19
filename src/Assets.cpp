//
// Created by gusta on 19/10/2021.
//

#include "Assets.h"
#include <iostream>

Assets::Assets(){
    filenames.emplace_back("blocos");
    filenames.emplace_back("fantasma");
    filenames.emplace_back("chapcahpacete");
    filenames.emplace_back("sofa");
};

void Assets::load_all() {
    std::string name;
    for (std::string& file : filenames){
        assets[file] = new sf::Texture;
        assets[file]->loadFromFile(get_path(file));
    }
}

std::string Assets::get_path(std::string name) {
    return "media/" + name + ".png";
}
