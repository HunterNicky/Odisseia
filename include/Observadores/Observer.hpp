#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

namespace Observadores{

    class Observer {
    private:
        std::map<sf::Keyboard::Key, std::string> keyboard;
        void startKeys();
    public:
        Observer();
        virtual ~Observer();
        virtual void notifyPressed(const std::string key) = 0;
        virtual void notifyReleased(const std::string key) = 0;
        std::string getKeyString(const sf::Keyboard::Key key);
    };

} 