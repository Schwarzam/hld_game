//
// Created by gusta on 15/10/2021.
//

#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H


#include <SFML/Window/Event.hpp>

class Events {
public:
    Events();

    void processInputs(const sf::Event& event);
};


#endif //GAME_EVENTS_H
