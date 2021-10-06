//
// Created by gustavo on 05/10/2021.
//

#include "ResourceManager.h"

template<typename RES_TYPE, typename ID>
template<typename... Arguments>
void ResourceManager<RES_TYPE, ID>::load(const ID &id, Arguments &&... args) {
    std::unique_ptr<RES_TYPE> ptr(new RES_TYPE);
    if (not ptr-> loadFromFile(std::forward<Arguments>(args)...))
        throw std::runtime_error("Could not load file");

    _map.emplace(id, std::move);
}

template<typename RES_TYPE, typename ID>
sf::Music & ResourceManager<RES_TYPE, ID>::get(const ID &id) const {
    return *_map.at(id);
}

template<typename ID>
template<typename... Args>
void ResourceManager<sf::Music, ID>::load(const ID& id, Args &&... args) {
    std::unique_ptr<sf::Music> ptr(new sf::Music);
    if (not ptr->openFromFile(std::forward<Args>(args)...))
        throw std::runtime_error("Could not open file.");
    _map.emplace(id, std::move(ptr));
};

template<typename ID>
sf::Music& ResourceManager<sf::Music, ID>::get(const ID& id) const {
    return *_map.at(id);
}