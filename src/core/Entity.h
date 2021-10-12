//
// Created by gustavo on 12/10/2021.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <SFML-utils/ES.hpp>
#include <SFML-utils/Map.hpp>
#include <SFML-utils/Core.hpp>

class Level;
class Entity : public sfutils::es::Entity<Entity>, public sf::Drawable
{

public:
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    Entity(sfutils::es::EntityManager<Entity>* manager,std::uint32_t id);

    sf::Vector2f getPosition()const;
    void setPosition(const sf::Vector2f& pos);

    std::string name;

    using FuncType = std::function<void(Entity& self,const sf::Vector2i& myCoord,Entity& enemi,const sf::Vector2i& enemyCoord,Level& level)>;

    FuncType onHit;
    FuncType onHitted;

private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
};

#endif //GAME_ENTITY_H
