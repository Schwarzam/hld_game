//
// Created by gustavo on 05/10/2021.
//

#include "Configuration.h"

void Configuration::initialize(){
    initTextures();
    initPlayerInputs();
}
void Configuration::initPlayerInputs(){
    playerInputs.map(PlayerInputs::W,Action(sf::Keyboard::W));
    playerInputs.map(PlayerInputs::A,Action(sf::Keyboard::A));
    playerInputs.map(PlayerInputs::D,Action(sf::Keyboard::D));
}

void Configuration::initTextures() {
    //textures.load(Textures::Player,"media/Player/Ship.png");
};

