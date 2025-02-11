#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>


namespace Observadores {

class Observer {
protected:
  std::map<sf::Keyboard::Key, std::string> keyboard;
  std::map<sf::Keyboard::Key, char> caracteres;

private:
  void startKeys();

public:
  Observer();
  virtual ~Observer();
  virtual void notifyPressed(const sf::Keyboard::Key key) = 0;
  virtual void notifyReleased(const sf::Keyboard::Key key) = 0;
  std::string getKeyString(const sf::Keyboard::Key key);
};

} // namespace Observadores