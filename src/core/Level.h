//
// Created by gustavo on 12/10/2021.
//

#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

#include <SFML-utils/es/Application.hpp>
#include <SFML-utils/Map.hpp>

#include "Entity.h"
#include "Configuration.h"

class Level : private sfutils::es::Application<Entity>
{
public:
    Level(const Level&) = delete;
    Level& operator=(const Level&) = delete;

    Level(sf::RenderWindow& window,const std::string& filename);
    ~Level();

    void update(sf::Time deltaTime);

    bool processEvent(sf::Event& event);
    void processEvents();
    void draw(sf::RenderTarget& window);

    struct Param {
        explicit Param(sf::Vector2i&,
                       Entity&,
                       sfutils::map::Layer<Entity*>&,
                       sfutils::map::Map&);

        sf::Vector2i& coord;
        Entity& entity;
        sfutils::map::Layer<Entity*>& layer;
        sfutils::map::Map& map;
    };

    using FuncType = std::function<void(Param& param)>;
    static FuncType defaultFunc;

    FuncType onPickup;

    sfutils::es::EntityManager<Entity>& entityManager();
    sfutils::map::Layer<sf::ConvexShape>& getHighlightLayer()const;
    const sf::ConvexShape getShape()const;


    Entity& createEntity(const sf::Vector2i& coord);
    void destroyEntity(Entity& e);
    void destroyEntity(std::uint32_t id);
    void setPosition(Entity& e,const sf::Vector2i& old,const sf::Vector2i& n);

    void createSound(Configuration::Sounds sound_id,const sf::Vector2i& coord);
    void createSound(Configuration::Sounds sound_id,const sf::Vector2f& pos);

    sf::Vector2i mapPixelToCoords(const sf::Vector2f& pos)const;
    sf::Vector2f mapCoordsToPixel(const sf::Vector2i& pos)const;

    sf::Vector2i mapCoordsToScreen(const sf::Vector2i& pos)const;
    sf::Vector2i mapScreenToCoords(const sf::Vector2i& pos)const;

    std::list<Entity*> getByCoords(const sf::Vector2i& coord);

    std::list<sf::Vector2i> getPath(const sf::Vector2i& origin,const sf::Vector2i& dest)const;
    sf::Vector2i getPath1(const sf::Vector2i& origin,const sf::Vector2i& dest)const;
    int getDistance(const sf::Vector2i& origin,const sf::Vector2i& dest)const;

    sf::Vector2i getMinCoord()const;
    sf::Vector2i getMaxCoord()const;

private:
    friend class Game;

    sfutils::map::Map* _map;
    sfutils::map::MapViewer _viewer;

    std::unordered_map<sf::Vector2i,std::list<Entity*>> _byCoords;

    sf::ConvexShape* _mouse_light;
    sfutils::map::Layer<sf::ConvexShape>* _mouseLayer;
    sfutils::map::Layer<Entity*>* _entitiesLayer;

    std::list<std::unique_ptr<sf::Sound>> _sounds;
    sf::Listener _listener;
};


#endif //GAME_LEVEL_H
