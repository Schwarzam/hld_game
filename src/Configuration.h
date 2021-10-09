//
// Created by gustavo on 05/10/2021.
//

#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H

#include <SFML/Graphics.hpp>

#include "ActionMap.h"
#include "ResourceManager.h"

class Configuration
{
public:
    Configuration() = delete;
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    enum Textures : int {Player};
    static ResourceManager<sf::Texture,int> textures;

    enum PlayerInputs : int {W, A, S, D};
    static ActionMap<int> playerInputs;

    static void initialize();

private:

    static void initTextures();

    static void initPlayerInputs();
};

#endif //GAME_CONFIGURATION_H
