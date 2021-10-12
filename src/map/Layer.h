//
// Created by gusta on 11/10/2021.
//

#ifndef GAME_LAYER_H
#define GAME_LAYER_H

#include <list>
#include "VLayer.h"

template<typename CONTENT>
class Layer : public VLayer
{
public:
    Layer(const Layer&) = delete;
    Layer& operator=(const Layer&) = delete;

    Layer(const std::string& type,int z, bool isStatic,bool isVisible);
    virtual ~Layer();

    CONTENT* add(const CONTENT& content,bool resort=true);
    CONTENT* add(CONTENT&& content,bool resort=true);

    void remove(void* data,bool del = false) override;
    std::list<CONTENT*> getByCoords(const sf::Vector2i& coords,const Map& map);
    bool remove(const CONTENT* content_ptr,bool resort=true);
    void sort() override;

private:
    virtual void draw(sf::RenderTarget& target,const sf::RenderStates& states,const sf::FloatRect& viewport) override;
    std::list<CONTENT> _content;

};

template<typename CONTENT>
class Layer<CONTENT*> : public VLayer
{
public:
    Layer(const Layer&) = delete;
    Layer& operator=(const Layer&) = delete;
    Layer(const std::string& type,int z,bool isStatic,bool isVisible);
    virtual ~Layer();

    CONTENT* add(CONTENT* content,bool resort=true);
    void remove(void* data, bool del = true) override;
    std::list<CONTENT*> getByCoords(const sf::Vector2i& coords,const Map& map);
    bool remove(const CONTENT* content_ptr,bool resort=true);
    void sort() override;
    void setAutofree(bool autofree);

private:
    bool _autofree;
    void draw(sf::RenderTarget& target,const sf::RenderStates& states,const sf::FloatRect& viewport) override;
    std::list<CONTENT*> _content;
};


#endif //GAME_LAYER_H
