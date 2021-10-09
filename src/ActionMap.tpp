//
// Created by gustavo on 09/10/2021.
//

template<typename T>
void ActionMap<T>::map(const T& key,const Action& action)
{
    _map.emplace(key,action);
}

template<typename T>
const Action& ActionMap<T>::get(const T& key)const
{
    return _map.at(key);
}
