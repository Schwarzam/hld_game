//
// Created by gusta on 01/10/2021.
//
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include "Game.h"


Game::Game() : _window(sf::VideoMode(1200, 720),"Game hld", sf::Style::Resize),
               _player(Player(&map))
{
    view.setSize(_window.getSize().x, _window.getSize().y);
    view.setCenter(_player.get_position().x, _player.get_position().y);
    view.zoom(0.3);
    _window.setView(view);

    entities.emplace_back(std::pair(0, &_player));
}


void Game::runWithMinimumTimeSteps(int minimum_frame_per_seconds)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f/minimum_frame_per_seconds);

    while (_window.isOpen())
    {
        processEvents();

        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }

        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvents()
{
    //to store the events
    sf::Event event;

    //events loop
    view.setCenter(_player.get_position().x, _player.get_position().y);
    _window.setView(view);

    while(_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)//Close window
            _window.close();

        else if (event.type == sf::Event::KeyPressed) //keyboard input
        {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
        }

        else if (event.type == sf::Event::Resized) //keyboard input
        {
            view.setSize(_window.getSize().x, _window.getSize().y);
            _window.setView(view);
        }

    }


}


void Game::update(sf::Time deltaTime)
{
    _player.processEvents();
    //_player.update(deltaTime);
}

void Game::render()
{
    updatePairRender();
    sortRender();
    //Clear screen
    _window.clear();

    //Draw
    _window.draw(map);

    for (auto& entity : entities){
        _window.draw(*entity.second);
    }

    sf::Vertex point(sf::Vector2f(3, 3), sf::Color::Red);
    point.position = _player.get_position();
    _window.draw(&point, 1, sf::Points);

    //Update the window
    _window.display();
}

bool Game::startMap() {
    int level[] = {
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
    };

//    if (!map.load("media/bloco_novo2_G.png", sf::Vector2u(160, 160), sf::Vector2u(160, 120), level, 5, 3))
//        return false;
//    return true;

    map.load_file("maps/editor1.json");
}


void Game::startEntity(const std::string& name) {
    entities.emplace_back(std::pair(0.0, new Entity(name)));
}

void Game::sortRender() {
    std::sort(entities.begin(), entities.end());
}

void Game::updatePairRender() {
    for (auto& i : entities){
        i.first = i.second->getPosY();
    }
}
