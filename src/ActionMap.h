//
// Created by gustavo on 09/10/2021.
//

#ifndef GAME_ACTIONMAP_H
#define GAME_ACTIONMAP_H

#include <unordered_map>
#include "Action.hpp"
template<typename T = int>
class ActionMap
{
public:
    ActionMap(const ActionMap<T>&) = delete;
    ActionMap<T>& operator=(const ActionMap<T>&) = delete;

    ActionMap() = default;

    void map(const T& key,const Action& action);
    const Action& get(const T& key)const;

private:
    std::unordered_map<T,Action> _map;
};

#include "ActionMap.tpp"
#endif //GAME_ACTIONMAP_H