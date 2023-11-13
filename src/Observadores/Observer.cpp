#include "..\..\include\Observadores\Observer.hpp"

namespace Observadores{
    Observer::Observer():
    keyboard(){
        startKeys();
    }

    Observer::~Observer(){
        keyboard.clear();
    }

    std::string Observer::getKeyString(const sf::Keyboard::Key key){
        return keyboard[key];
    }
    void Observer::startKeys()
    {
        keyboard[sf::Keyboard::W] = "W";
        keyboard[sf::Keyboard::A] = "A";
        keyboard[sf::Keyboard::S] = "S";
        keyboard[sf::Keyboard::D] = "D";
        keyboard[sf::Keyboard::Up] = "Up";
        keyboard[sf::Keyboard::Left] = "Left";
        keyboard[sf::Keyboard::Down] = "Down";
        keyboard[sf::Keyboard::Right] = "Right";
        keyboard[sf::Keyboard::Enter] = "Enter";
        keyboard[sf::Keyboard::Escape] = "Escape";
    }
}

