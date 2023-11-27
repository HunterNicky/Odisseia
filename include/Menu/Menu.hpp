#pragma once

#include "..\Ente.hpp"
#include "..\Estados\Estado.hpp"
#include "..\Observadores\ControleMenu.hpp"
#include "Botoes/Botao.hpp"
#include "Menu/Botoes/Texto.hpp"
#include <list>

namespace Observadores {
class ControleMenu;
}

namespace Menu {
class Menu : public Estados::Estado {
protected:
  static Estados::MaquinaDeEstado *pMaquinaDeEstado;
  static Observadores::ControleMenu *pControleMenu;
  std::list<Botoes::Botao *> lBotao;
  std::list<Botoes::Botao *>::iterator it;
  Botoes::Texto titulo;
  sf::RectangleShape fundo;
  sf::Texture imgFundo;
  unsigned int numOpc;
  unsigned int numSelec;

public:
  Menu(const int id, int numOpc, const sf::Vector2f pos,
       const sf::Vector2f size, const std::string texto,
       const unsigned int tamF);
  virtual ~Menu();
  virtual void executar() = 0;
  virtual void inicializaBotao() = 0;
  virtual void ajustarTexto() {}
  virtual void addCaracter(char caracter) {}
  virtual void removerCaracter() {}
  void select(const bool direcao);
  void update(const double dt);
  virtual void draw();
};
} // namespace Menu