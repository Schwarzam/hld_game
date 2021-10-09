//
// Created by gustavo on 08/10/2021.
//

#ifndef GAME_ACTIONTARGET_H
#define GAME_ACTIONTARGET_H


#include <SFML/Window/Event.hpp>
#include <list>
#include "Action.h"
#include "ActionMap.h"

template<typename T = int>
class ActionTarget {
public:
    ActionTarget(const ActionTarget<T>&) = delete;
    ActionTarget<T>& operator = (const ActionTarget<T>&) = delete;

    using FuncType = std::function<void(const sf::Event&)>;

    ActionTarget(const ActionMap<T>& map);

    void processEvents()const;
    bool processEvent(const sf::Event& event) const;

    void bind(const T& key, const FuncType& callback);
    void unbind(const T& key);

private:
    std::list<std::pair<T, FuncType>> _eventsRealTime;
    std::list<std::pair<T, FuncType>> _eventsPoll;

    const ActionMap<T>& _actionMap;
};

#include "ActionTarget.tpl"
#endif //GAME_ACTIONTARGET_H
