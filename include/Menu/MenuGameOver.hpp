#pragma once

#include "Fases/Fase.hpp"
#include "Menu.hpp"


#define TAMANHO_GO_X 100.f
#define TAMANHO_GO_Y 100.f
#define POS_TEXTO_GO_X 640.f
#define POS_TEXTO_GO_Y 100.f
#define POS_PONTUACAO_X 540.f
#define POS_PONTUACAO_Y 100.f
#define POS_TEXTO_X 440.f
#define POS_TEXTO_Y 100.f

#define CAMINHO_FONTE_MENU "data/Font/menus.ttf"

namespace Menu {
class MenuGameOver : public Menu {
private:
  Fases::Fase *pFase;
  sf::RectangleShape *fundoCaracter;
  Botoes::Texto texto;
  Botoes::Texto pontuacao;

public:
  MenuGameOver(Fases::Fase *pFase);
  ~MenuGameOver();
  void setFase(Fases::Fase *pFase);
  void inicializaBotao();
  void salvarPontuacao();
  void ajustarTexto();
  void addCaracter(char caracter);
  void removerCaracter();
  void executar();
  void update(const double dt);
  void draw();
};
} // namespace Menu