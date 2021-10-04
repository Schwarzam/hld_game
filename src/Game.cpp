//
// Created by gusta on 01/10/2021.
//
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include "Game.h"

Game::Game() : _window(sf::VideoMode(800, 600), "02_Game_Archi"), _player(150){
    _player.setFillColor(sf::Color::Blue);
    _player.setPosition(10,20);
}

void Game::run(){
    while(_window.isOpen()){
        processEvents();
        //update();
        render();
    }
}


void Game::update(sf::Time deltaTime) {

}

void Game::processEvents() {
    sf::Event event;
    while(_window.pollEvent(event)) {
        if ((event.type == sf::Event::Closed) or ((event.type == sf::Event::KeyPressed) and (event.key.code == sf::Keyboard::Escape))){
            _window.close();
        }
    }
}

//void Game::update() {}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}


void Game::run(int minimum_frame_per_seconds) {
    /*Allow free run but if exceeds (lower) frame_per_second it splits time to compensate*/

    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f/minimum_frame_per_seconds);

    while (_window.isOpen()){
        processEvents();
        timeSinceLastUpdate = clock.restart();

        while (timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
        render();
    }
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
