//
// Created by gustavo on 05/10/2021.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <SFML/Audio.hpp>

template <typename RES_TYPE, typename ID = int>
class ResourceManager {
    public:
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;

        ResourceManager() = default;

        template<typename ... Arguments>
        void load(const ID& id, Arguments&& ... args);

        sf::Music & get(const ID& id) const;

    private:
        std::unordered_map<ID, std::unique_ptr<RES_TYPE>> _map;
};


template<typename ID>
class ResourceManager<sf::Music, ID>{
    public:
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;

        ResourceManager() = default;

        template<typename ... Args>
        void load(const ID& id, Args&& ... args);

        sf::Music& get(const ID& id) const;
    private:
        std::unordered_map<ID, std::unique_ptr<sf::Music>> _map;
};

#endif //GAME_RESOURCEMANAGER_H
