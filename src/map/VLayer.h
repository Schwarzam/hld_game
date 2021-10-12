//
// Created by gustavo on 10/10/2021.
//

#ifndef GAME_V_LAYER_H
#define GAME_V_LAYER_H

#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Map;

class VLayer
{
public:
    VLayer(const VLayer&) = delete;
    VLayer& operator=(const VLayer&) = delete;

    VLayer(std::string type,int z,bool isStatic,bool isVisible);
    virtual ~VLayer() = default;

    virtual void sort() = 0;

    int getZ()const;
    void setZ(int z);

    const std::string& getType()const;

    virtual void remove(void* data,bool del = true);

    bool isStatic()const;
    bool isVisible() const;
    void setVisible(bool visibility);

    static VLayer* create(const std::string& type, int z, bool isStatic, bool isVisible = true);

protected:
    const bool _isStatic;

    sf::RenderTexture _renderTexture;
    sf::Sprite _sprite;
    sf::FloatRect _lastViewport;

private:
    friend class Map;
    virtual void draw(sf::RenderTarget& target, const sf::RenderStates& states,const sf::FloatRect& viewport) = 0;

    const std::string _type;
    bool _visibility;
    int _z;
};

#endif //GAME_V_LAYER_H
