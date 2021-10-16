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
            inputs.push_back(event.key.code);
    }
}

std::vector<char> Events::get_inputs() {
    return inputs;
}
