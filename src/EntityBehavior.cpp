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
    if (actualMove.empty()){
        return;
    }

    animationTime = animation_clock.restart().asSeconds();
    moveDuration += animationTime;

    if (moveDuration > actualMove["duration"].get<float>()){
        chooseBehavior();
        moveDuration = 0;
    }

    if (animationTime > 1){
        animationTime = 1;
    }

    totalTime += animationTime;

    if (totalTime >= switchTime){
        totalTime -= switchTime;

        if (actualMove["frames"].is_number()){
            currentImage.y = actualMove["linha"].get<int>(); //ROW
            currentImage.x ++;
            if (currentImage.x >= actualMove["frames"].get<int>()){
                currentImage.x = actualMove["coluna"].get<int>();
            }
        }else{
            if (frameNum >= actualMove["frames"].size()){
                frameNum = 0;
            }

            currentImage.x = actualMove["frames"][frameNum][1].get<int>();
            currentImage.y = actualMove["frames"][frameNum][0].get<int>();
            frameNum ++;
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
    if (moveProbabilites == 0){
        for (auto& [key, value] : animation_json["movements"].items()) {
            if (value.contains("probabilitie"))
                moveProbabilites += value["probabilitie"].get<int>();
        }
    }

    //Random move
    int k = rand() % moveProbabilites;

    int prob = 0;
    for (auto [key, value] : animation_json["movements"].items()) {
        if (value.contains("probabilitie"))
            prob += value["probabilitie"].get<int>();

        if (k >= prob - value["probabilitie"].get<int>() && k < prob){
            actualMove = value;
            break;
        }
    }
}
