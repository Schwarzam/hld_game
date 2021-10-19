//
// Created by gusta on 19/10/2021.
//

#include "Assets.h"
#include <iostream>

std::unordered_map<std::string, std::shared_ptr<sf::Texture>> Assets::textures;

std::shared_ptr<sf::Texture> Assets::Acquire(const std::string &name) {
    const auto i = textures.find( name );
    if( i != textures.end() ){
        return i->second;
    }
    else{
        auto pTex = std::make_shared<sf::Texture>();
        pTex->loadFromFile( "media/" + name + ".png");
        textures.insert({name, pTex});
        return pTex;
    }
}