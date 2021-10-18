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
    //_player.setPosition(100,100);
    view.setSize(_window.getSize().x, _window.getSize().y);
    view.setCenter(_player.get_position().x, _player.get_position().y);
    _window.setView(view);
}

void Game::runWithFixedTimeSteps(int frame_per_seconds)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Time TimePerFrame = sf::seconds(1.f/frame_per_seconds);

    while (_window.isOpen())
    {
        processEvents();

        bool repaint = false;

        //fix time delta between frames
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            repaint = true;
            update(TimePerFrame);
        }

        if(repaint)
            render();
    }
}

void Game::runWithVariableTimeSteps()
{
    sf::Clock clock;

    while (_window.isOpen())
    {
        processEvents();
        update(clock.restart());
        render();
    }
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
    //Clear screen
    _window.clear();

    //Draw
    _window.draw(map);
    _window.draw(_player);

    //Update the window
    _window.display();
}

bool Game::startMap() {
    int level[] = {
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
    };

    if (!map.load("media/bloco_novo2_G.png", sf::Vector2u(160, 160), sf::Vector2u(160, 120), level, 5, 3))
        return false;
    return true;
}



//void Game::run(int frame_per_seconds) {
//    /*Time since last game update to perform multiple updates if need. This control the updates per frame rate*/
//
//    sf::Clock clock;
//    sf::Time timeSinceLastUpdate = sf::Time::Zero;
//    sf::Time TimePerFrame = sf::seconds(1.f/frame_per_seconds);
//
//    while (_window.isOpen()){
//        processEvents();
//        bool repaint = false;
//
//        timeSinceLastUpdate += clock.restart();
//
//        while (timeSinceLastUpdate > TimePerFrame){
//            timeSinceLastUpdate -= TimePerFrame;
//            repaint = true;
//            update(TimePerFrame);
//        }
//        if(repaint) render();
//    }
//}
