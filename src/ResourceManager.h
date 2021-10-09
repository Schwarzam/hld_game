//
// Created by gustavo on 05/10/2021.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <SFML/Audio.hpp>
template<typename RESOURCE,typename IDENTIFIER = int>
class ResourceManager
{
public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER& id,Args&& ... args);

    RESOURCE& get(const IDENTIFIER& id)const;

private:
    std::unordered_map<IDENTIFIER,std::unique_ptr<RESOURCE>> _map;
};

template<typename IDENTIFIER>
class ResourceManager<sf::Music,IDENTIFIER>
{
public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER& id,Args&& ... args);

    sf::Music& get(const IDENTIFIER& id)const;

private:
    std::unordered_map<IDENTIFIER,std::unique_ptr<sf::Music>> _map;
};

#include "ResourceManager.tpp"
#endif //GAME_RESOURCEMANAGER_H
