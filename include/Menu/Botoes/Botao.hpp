#pragma once

#include "Ente.hpp"
#include "Texto.hpp"

namespace Menu {
namespace Botoes {
class Botao : public Ente {
private:
  Texto texto;
  sf::Texture *padraoT;
  sf::Texture *selecionadoT;
  sf::RectangleShape *body;

public:
  Botao(const sf::Vector2f pos, std::string stdTexto);
  ~Botao();
  void selecionado(const bool select);
  void draw();
  void update();
  void executar();
};
} // namespace Botoes
} // namespace Menu