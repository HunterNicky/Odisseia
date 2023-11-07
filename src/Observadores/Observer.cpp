#include "..\..\include\Observadores\Observer.hpp"

namespace Observadores{
    Observer::Observer():
    keyboard(){
        startKeys();
    }

    Observer::~Observer(){
        keyboard.clear();
    }

    std::string Observer::getKeyString(sf::Keyboard::Key key){
        return keyboard[key];
    }
    void Observer::startKeys()
    {
        keyboard[sf::Keyboard::W] = "W";
        keyboard[sf::Keyboard::A] = "A";
        keyboard[sf::Keyboard::S] = "S";
        keyboard[sf::Keyboard::D] = "D";
        keyboard[sf::Keyboard::Escape] = "Escape";
    }
}

