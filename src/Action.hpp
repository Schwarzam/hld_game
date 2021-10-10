//
// Created by gusta on 06/10/2021.
//

#ifndef GAME_ACTION_HPP
#define GAME_ACTION_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

class Action
{
public:
    enum Type
    {
        RealTime=1,
        Pressed=1<<1,
        Released=1<<2
    };

    explicit Action(const sf::Keyboard::Key& key,int type=Type::RealTime|Type::Pressed);
    explicit Action(const sf::Mouse::Button& button,int type=Type::RealTime|Type::Pressed);

    bool test()const;

    bool operator==(const sf::Event& event)const;
    bool operator==(const Action& other)const;


private:
    template<typename> friend class ActionTarget;
    sf::Event _event;
    int _type;
};

#endif //GAME_ACTION_HPP
