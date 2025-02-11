#pragma once

#include "Fases/Fase_Planicie.hpp"
#include "Fases/Fase_Castelo.hpp"
#include "Menu.hpp"
#include "Menu/Botoes/Botao.hpp"
#include "Menu/Botoes/Texto.hpp"

#define TAM_TEXTO_OPTION_X 100.f
#define TAM_TEXTO_OPTION_Y 100.f
#define POS_TEXTO_OPTION_X 640.f
#define POS_TEXTO_OPTION_Y 100.f

namespace Menu {
class MenuOpcoes : public Menu {
private:
  Fases::Fase_Planicie *pFase_Planicie;
  Fases::Fase_Castelo *pFase_Castelo;

public:
  MenuOpcoes();
  ~MenuOpcoes();
  // void setFase(Fases::Fase* pFase);
  void executar();
  void inicializaBotao();
  void update(const double dt);
  void draw();
};
} // namespace Menu