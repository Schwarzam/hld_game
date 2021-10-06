//
// Created by gustavo on 05/10/2021.
//

#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H


class Configuration {
public:
    Configuration() = delete;
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    enum Textures : int {Player};
    static ActionMap<int> player_inputs;

    void Configuration::initialize(){
        initTextures();
        initPlayerInputs();
    }
    void Configuration::initPlayerInputs(){
        player_inputs.map(PlayerInputs::Up)
    }

    //
};


#endif //GAME_CONFIGURATION_H
