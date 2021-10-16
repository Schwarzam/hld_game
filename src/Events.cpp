//
// Created by gusta on 15/10/2021.
//

#include "Events.h"

Events::Events() {

}

void Events::processInputs(const sf::Event &event) {
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::W){

            }
            if(event.key.code == sf::Keyboard::S){

            }
    }
}
