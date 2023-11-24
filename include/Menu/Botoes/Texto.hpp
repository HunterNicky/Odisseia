#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>


namespace Menu {
namespace Botoes {
class Texto {
private:
  sf::Font fonte;
  std::string texto;
  sf::Text sfTexto;
  sf::Vector2f pos;
  sf::Vector2f size;
  sf::Color color;
  unsigned int sizeFont;

public:
  Texto(const sf::Vector2f pos, const sf::Vector2f size,
        const std::string texto, unsigned int sizeFont);
  ~Texto();
  void setTexto(const std::string texto);
  void setPos(const sf::Vector2f pos);
  void setSize(const sf::Vector2f size);
  void setColor(const sf::Color color);
  void setFontSize(const unsigned int tamanhoFonte);
  void setTextFont(std::string font);
  void setTamanhoBorda(const float tamBorda);
  const sf::Vector2f getPos() const;
  const sf::Vector2f getSize() const;
  const sf::Text *getSfTexto() const;
  const std::string getText() const;
};
} // namespace Botoes
} // namespace Menu