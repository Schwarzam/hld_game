//
// Created by gustavo on 10/10/2021.
//

#include "VLayer.h"
#include "Layer.h"
#include "Tile.h"
#include <utility>

VLayer::VLayer(std::string type,int z,bool isStatic,bool isVisible) :
        _isStatic(isStatic),
        _type(std::move(type)),
        _visibility(isVisible),
        _z(z)
{
}

VLayer::~VLayer() = default;

int VLayer::getZ()const
{
    return _z;
}

void VLayer::setZ(int z)
{
    _z = z;
}

const std::string& VLayer::getType()const
{
    return _type;
}

bool VLayer::isStatic()const
{
    return _isStatic;
}

bool VLayer::isVisible() const
{
    return _visibility;
}

void VLayer::setVisible(bool visibility)
{
    _visibility = visibility;
}

VLayer* VLayer::create(const std::string& layerType, int z, bool isStatic, bool isVisible)
{
    VLayer* layer = nullptr;
    if(layerType == "tile")
    {
        layer = new Layer<Tile>(layerType,z,isStatic,isVisible);
    }
    else if(layerType == "sprite")
    {
        layer = new Layer<sf::Sprite>(layerType,z,isStatic,isVisible);
    }
    else if(layerType == "sprite_ptr")
    {
        layer = new Layer<sf::Sprite*>(layerType,z,isStatic,isVisible);
    }
    else if(layerType == "entity")
    {
        layer = new Layer<Entity*>(layerType,z,isStatic,isVisible);
    }

    return layer;

}








