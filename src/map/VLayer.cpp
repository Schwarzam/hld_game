//
// Created by gustavo on 10/10/2021.
//

#include "VLayer.h"

#include <utility>

VLayer::VLayer(std::string type, int z, bool isStatic, bool isVisible) :
    _isStatic(isStatic),
    _type(std::move(type)),
    _visibility(isVisible),
    _z(z){
}

int VLayer::getZ() const {
    return _z;
}

void VLayer::setZ(int z) {
    _z = z;
}

const std::string &VLayer::getType() const {
    return _type;
}

bool VLayer::isStatic() const {
    return _isStatic;
}

bool VLayer::isVisible() const {
    return _visibility;
}

void VLayer::setVisible(bool visibility)
{
    _visibility = visibility;
}

VLayer *VLayer::create(const std::string &type, int z, bool isStatic, bool isVisible) {
    VLayer* layer = nullptr;
    if(layerType == "tile")
    {
        layer = new sfutils::map::Layer<sfutils::map::Tile>(layerType,z,isStatic,isVisible);
    }
    else if(layerType == "sprite")
    {
        layer = new sfutils::map::Layer<sf::Sprite>(layerType,z,isStatic,isVisible);
    }
    else if(layerType == "sprite_ptr")
    {
        layer = new sfutils::map::Layer<sf::Sprite*>(layerType,z,isStatic,isVisible);
    }
    else if(layerType == "entity")
    {
        layer = new sfutils::map::Layer<sfutils::map::Entity*>(layerType,z,isStatic,isVisible);
    }

    return layer;
}








