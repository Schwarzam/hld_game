//
// Created by gustavo on 05/10/2021.
//

#include "Configuration.h"

ResourceManager<sf::Texture,int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;

void Configuration::initialize()
{
    initTextures();
    initPlayerInputs();
}

void Configuration::initTextures()
{
    textures.load(Textures::Player,"media/chapcahpacete.png");
}

void Configuration::initPlayerInputs()
{
    playerInputs.map(PlayerInputs::W,Action(sf::Keyboard::W));
    playerInputs.map(PlayerInputs::A,Action(sf::Keyboard::A));
    playerInputs.map(PlayerInputs::S,Action(sf::Keyboard::S));
    playerInputs.map(PlayerInputs::D,Action(sf::Keyboard::D));
}

