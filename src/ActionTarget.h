//
// Created by gustavo on 08/10/2021.
//

#ifndef GAME_ACTIONTARGET_H
#define GAME_ACTIONTARGET_H


#include <SFML/Window/Event.hpp>
#include <list>
#include "Action.h"

class ActionTarget {
public:
    using FuncType = std::function<void(const sf::Event&)>;

    ActionTarget();

    void processEvents()const;
    bool processEvent(const sf::Event& event) const;

    void bind(const Action& action, const FuncType& callback);
    void unbind(const Action& action);

private:
    std::list<std::pair<Action, FuncType>> _eventsRealTime;
    std::list<std::pair<Action, FuncType>> _eventsPoll;
};



#endif //GAME_ACTIONTARGET_H
