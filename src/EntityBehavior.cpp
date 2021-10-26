//
// Created by gusta on 26/10/2021.
//

#include <fstream>
#include "EntityBehavior.h"

void EntityBehavior::animation() {
    std::string o = "media/" + entityName + ".json";
    std::ifstream file("media/" + entityName + ".json");
    file >> animation_json;

    this->switchTime = 1.0f/animation_json["FPS"].get<float>();

    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = _ptexture->getSize().x / float(animation_json["GRID"]["x"].get<int>());
    uvRect.height = _ptexture->getSize().y / float(animation_json["GRID"]["y"].get<int>());

    _sprite.setTextureRect(uvRect);
    _sprite.setOrigin(uvRect.width/2, uvRect.height);

    //Feet only area to do collisions
    uvRectFeet.width = _ptexture->getSize().x / float(animation_json["GRID"]["x"].get<int>());
    uvRectFeet.height = animation_json["FEET_AREA"].get<int>();

    _feetSprite.setTextureRect(uvRectFeet);
    _feetSprite.setOrigin(uvRectFeet.width/2, uvRectFeet.height);
}

void EntityBehavior::updateAnimation() {
    std::string action = actionsMap.at(direction);
    currentImage.y = animation_json[action]["LINHA"]; //ROW

    animationTime = clock.restart().asSeconds();
    if (animationTime > 1){
        animationTime = 1;
    }

    totalTime += animationTime;

    if (totalTime >= switchTime){
        totalTime -= switchTime;

        currentImage.x ++;
        if (currentImage.x >= animation_json[action]["FRAMES"]){
            currentImage.x = animation_json[action]["COLUNA_INICIAL"];
        }

        uvRect.left = currentImage.x * uvRect.width;
        uvRect.top = currentImage.y * uvRect.height;
        _sprite.setTextureRect(uvRect);


        uvRectFeet.left = currentImage.x * uvRect.width;
        uvRectFeet.top = (currentImage.y + 1) * uvRect.height - uvRectFeet.height;

        _feetSprite.setTextureRect(uvRectFeet);
    }
}

void EntityBehavior::chooseBehavior() {

//    animation_json["movements"];
}
