#include "..\..\include\Observadores\Observer.hpp"

namespace Observadores {
Observer::Observer() : caracteres() { startKeys(); }

Observer::~Observer() { caracteres.clear(); }

std::string Observer::getKeyString(const sf::Keyboard::Key key) {
  return keyboard[key];
}
void Observer::startKeys() {
  caracteres[sf::Keyboard::Num0] = '0';
  caracteres[sf::Keyboard::Num1] = '1';
  caracteres[sf::Keyboard::Num2] = '2';
  caracteres[sf::Keyboard::Num3] = '3';
  caracteres[sf::Keyboard::Num4] = '4';
  caracteres[sf::Keyboard::Num5] = '5';
  caracteres[sf::Keyboard::Num6] = '6';
  caracteres[sf::Keyboard::Num7] = '7';
  caracteres[sf::Keyboard::Num8] = '8';
  caracteres[sf::Keyboard::Num9] = '9';
  caracteres[sf::Keyboard::A] = 'a';
  caracteres[sf::Keyboard::B] = 'b';
  caracteres[sf::Keyboard::C] = 'c';
  caracteres[sf::Keyboard::D] = 'd';
  caracteres[sf::Keyboard::E] = 'e';
  caracteres[sf::Keyboard::F] = 'f';
  caracteres[sf::Keyboard::G] = 'g';
  caracteres[sf::Keyboard::H] = 'h';
  caracteres[sf::Keyboard::I] = 'i';
  caracteres[sf::Keyboard::J] = 'j';
  caracteres[sf::Keyboard::K] = 'k';
  caracteres[sf::Keyboard::L] = 'l';
  caracteres[sf::Keyboard::M] = 'm';
  caracteres[sf::Keyboard::N] = 'n';
  caracteres[sf::Keyboard::O] = 'o';
  caracteres[sf::Keyboard::P] = 'p';
  caracteres[sf::Keyboard::Q] = 'q';
  caracteres[sf::Keyboard::R] = 'r';
  caracteres[sf::Keyboard::S] = 's';
  caracteres[sf::Keyboard::T] = 't';
  caracteres[sf::Keyboard::U] = 'u';
  caracteres[sf::Keyboard::V] = 'v';
  caracteres[sf::Keyboard::X] = 'x';
  caracteres[sf::Keyboard::W] = 'w';
  caracteres[sf::Keyboard::Z] = 'z';

  keyboard[sf::Keyboard::W] = "W";
  keyboard[sf::Keyboard::A] = "A";
  keyboard[sf::Keyboard::S] = "S";
  keyboard[sf::Keyboard::D] = "D";
  keyboard[sf::Keyboard::Up] = "Up";
  keyboard[sf::Keyboard::Left] = "Left";
  keyboard[sf::Keyboard::Down] = "Down";
  keyboard[sf::Keyboard::Right] = "Right";
  keyboard[sf::Keyboard::Enter] = "Enter";
  keyboard[sf::Keyboard::Space] = "Space";
  keyboard[sf::Keyboard::Escape] = "Escape";
  keyboard[sf::Keyboard::LShift] = "LShift";
  keyboard[sf::Keyboard::BackSpace] = "BackSpace";
}
} // namespace Observadores
