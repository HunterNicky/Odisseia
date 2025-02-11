#include "..\..\..\include\Menu\Botoes\Botao.hpp"

namespace Menu {
namespace Botoes {
Botao::Botao(const sf::Vector2f pos, std::string stdTexto)
    : Ente(pos, sf::Vector2f(200, 100)),
      texto(pos, sf::Vector2f(200, 100), stdTexto, 30) {
  padraoT = new sf::Texture;
  selecionadoT = new sf::Texture;
  padraoT->loadFromFile("data/Botao/botao.png");
  selecionadoT->loadFromFile("data/Botao/botaoselect.png");

  texto.setColor(sf::Color::Black);

  body = new sf::RectangleShape(sf::Vector2f(200, 100));
  body->setPosition(pos);
  body->setTexture(padraoT);
}

Botao::~Botao() { delete body; }

void Botao::selecionado(const bool select) {
  if (select) {
    body->setTexture(selecionadoT);
  } else {
    body->setTexture(padraoT);
  }
}

void Botao::draw() {
  pGrafico->draw(body);
  pGrafico->drawText(texto.getSfTexto());
}
void Botao::update() {}
void Botao::executar() {}
} // namespace Botoes
} // namespace Menu
