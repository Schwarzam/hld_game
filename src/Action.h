//
// Created by gusta on 06/10/2021.
//

#ifndef GAME_ACTION_H
#define GAME_ACTION_H


#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

class Action {
public:
    enum Type {
        RealTime = 1,
        Pressed = 1<<1,
        Released = 1<<2
    };

    Action(const sf::Keyboard::Key& key, int type=Type::RealTime|Type::Pressed);
    Action(const sf::Mouse::Button&, int type=Type::RealTime|Type::Pressed);

    bool test()const;

    bool operator==(const sf::Event& event)const;
    bool operator==(const Action& other) const;
private:
    friend class ActionTarget;
    sf::Event _event;
    int _type;
};


#endif //GAME_ACTION_H
