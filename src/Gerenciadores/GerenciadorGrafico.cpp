#include "..\..\include\Gerenciadores\GerenciadorGrafico.hpp"
#include <iostream>
#include <string>

namespace Gerenciadores {
GerenciadorGrafico *GerenciadorGrafico::instance = nullptr;

GerenciadorGrafico *GerenciadorGrafico::getInstance() {
  if (instance == nullptr) {
    instance = new GerenciadorGrafico();
  }
  return instance;
}

GerenciadorGrafico::GerenciadorGrafico()
    : window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Odisseia Temporalis")),
      view(sf::Vector2f(1280.f / 2, 720.f / 2), sf::Vector2f(1280, 720)) {}

GerenciadorGrafico::~GerenciadorGrafico() { delete (instance); }

void GerenciadorGrafico::display() {
  if (isWindowOpen()) {
    window->setView(view);
    window->display();
  }
}

void GerenciadorGrafico::clear() {
  if (isWindowOpen()) {
    window->clear();
  }
}

void GerenciadorGrafico::close() {
  if (isWindowOpen()) {
    window->close();
  }
}

void GerenciadorGrafico::draw(const sf::Drawable *drawable) {
  if (isWindowOpen()) {
    window->draw(*drawable);
  }
}

const bool GerenciadorGrafico::isWindowOpen() const { return window->isOpen(); }

const bool GerenciadorGrafico::pollEvent(sf::Event &event) {
  return window->pollEvent(event);
}

void GerenciadorGrafico::setViewCenter(const sf::Vector2f center) {
  if (isWindowOpen()) {
    view.setCenter(sf::Vector2f(center.x, center.y));
  }
}

const sf::Vector2f GerenciadorGrafico::getViewCenter() const {
  if (isWindowOpen()) {
    return view.getCenter();
  } else {
    return sf::Vector2f(0, 0);
  }
}

void GerenciadorGrafico::drawText(const sf::Text *text) {
  if (isWindowOpen()) {
    window->draw(*text);
  }
}

// Ideia: código do Matheus Burda
sf::Texture *GerenciadorGrafico::loadTexture(std::string filepath) {
  std::map<std::string, sf::Texture *>::iterator it = texturaMap.begin();
  while (it != texturaMap.end()) {
    if (it->first == filepath)
      return it->second;
    it++;
  }

  sf::Texture *textura = new sf::Texture();

  if (!textura->loadFromFile(filepath)) {
    std::cout << "Textura não carregada " << filepath << std::endl;
  }

  texturaMap.insert(std::pair<std::string, sf::Texture *>(filepath, textura));

  return textura;
}

} // namespace Gerenciadores
