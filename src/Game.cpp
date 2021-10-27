//
// Created by gusta on 01/10/2021.
//
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Game.h"

Game::Game() : _window(sf::VideoMode(1200, 720),"Game hld", sf::Style::Resize),
            _player(Player())
{
    view.setSize(_window.getSize().x, _window.getSize().y);
    view.setCenter(_player.get_position().x, _player.get_position().y);

    setZoom(0.4);
    _window.setView(view);

    entities.emplace_back(std::pair(0, &_player));
}


void Game::runWithMinimumTimeSteps(int minimum_frame_per_seconds)
{
    sf::Clock clock;

    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f/minimum_frame_per_seconds);

    Entity *e = Game::startEntity("aranha");
    e->setPosition(sf::Vector2f(280, 220));
    e->animation();

    while (_window.isOpen())
    {
        processEvents();

        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update();
        }

        update();
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
    setZoom(0.4);

    while(_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)//Close window
            _window.close();

        else if (event.type == sf::Event::KeyPressed) //keyboard input
        {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
            if (event.key.code == sf::Keyboard::O){
                setZoom(0.95f);
                _window.setView(view);
            }
            if (event.key.code == sf::Keyboard::L) {
                setZoom(1.05f);
                _window.setView(view);
            }
        }

        else if (event.type == sf::Event::Resized) //keyboard input
        {
            view.setSize(_window.getSize().x, _window.getSize().y);
            _window.setView(view);
        }


    }
}


void Game::update()
{
    for (auto& entity : entities){
        entity.second->processEvents();
    }
    //_player.processEvents();
    //_player.update(deltaTime);
}

void Game::render()
{
    sortRender();
    //Clear screen
    _window.clear(sf::Color(150, 150, 150));

    //Draw
    _window.draw(map);

    for (auto& entity : entities){
        _window.draw(*entity.second);
    }

    for (auto& entity : entities){
        sf::Vertex point(sf::Vector2f(3, 3), sf::Color::Red);
        point.position = entity.second->getFeetPosition();
        _window.draw(&point, 1, sf::Points);
    }


    //Count FPS
    _window.setTitle(fps.getFPS());

    //Update the window
    _window.display();
}

bool Game::startMap() {
    map.load_file("maps/editor1.json");
    return true;
}

void Game::setZoom(float z) {
    if (int(_window.getSize().x) == int(view.getSize().x)){
        view.setSize(z * view.getSize());
    }
    _window.setView(view);
}

