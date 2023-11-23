#pragma once

#include "..\Estados\Estado.hpp"
#include "..\Estados\Jogo.hpp"
#include "Fases/Fase1.hpp"
#include "Menu/Botoes/Botao.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "Menu/MenuOpcoes.hpp"
#include "Menu/MenuRanking.hpp"


#define TAMANHO_BOTAO_X 200.f
#define TAMANHO_BOTAO_Y 50.f
#define POS_BOTAO_X 640.f
#define POS_BOTAO_Y 200.f
namespace Estados {
class Jogo;
}

namespace Menu {
class MenuPrincipal : public Menu {
private:
  static Estados::MaquinaDeEstado *pMaquinaDeEstado;
  Fases::Fase1 *fase;
  Estados::Jogo *pJogo;
  MenuOpcoes *pOpcao;

public:
  MenuPrincipal(Estados::Jogo *pJogo);
  ~MenuPrincipal();
  void inicializaBotao() override;
  void carregarJogo();
  void executar() override;
  void update(const double dt) override;
  void draw() override;
};
} // namespace Menu
