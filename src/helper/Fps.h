//
// Created by gusta on 23/10/2021.
//

#ifndef GAME_FPS_H
#define GAME_FPS_H
#include <SFML/System/Clock.hpp>
#include <string>
#include <sstream>

class FPS
{
public:
    /// @brief Constructor with initialization.
    ///
    FPS() : mFrame(0), mFps(0) {}

    /// @brief Update the frame count.
    ///


    /// @brief Get the current FPS count.
    /// @return FPS count.

    std::string getFPS() {
        update();
        std::ostringstream ss;
        ss << mFps;
        return ss.str();
    }

private:
    unsigned int mFrame;
    unsigned int mFps;
    sf::Clock mClock;

public:
    void update()
    {
        if(mClock.getElapsedTime().asSeconds() >= 1.f)
        {
            mFps = mFrame;
            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;
    }
};


#endif //GAME_FPS_H
