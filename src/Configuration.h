//
// Created by gustavo on 05/10/2021.
//

#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H

#include "ActionMap.h"

class Configuration {
public:
    Configuration() = delete;
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    enum Textures : int {Player};
    static void initialize();

    enum PlayerInputs  : int {W,A,D};
    static ActionMap<int> playerInputs;

private:
    static void initTextures();
    static void initPlayerInputs();
    //
};


#endif //GAME_CONFIGURATION_H
