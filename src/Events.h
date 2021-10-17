//
// Created by gusta on 15/10/2021.
//

#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H


#include <SFML/Window/Event.hpp>
#include <unordered_map>
#include <stack>

class Events {
public:
    Events();

    void processInputs(const sf::Event& event);
    std::stack<char>& get_inputs();

private:
    std::stack<char> inputs;
};


#endif //GAME_EVENTS_H
