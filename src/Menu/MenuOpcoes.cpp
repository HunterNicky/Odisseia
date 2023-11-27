#include "Menu/MenuOpcoes.hpp"
#include "Fases/Fase.hpp"
#include "Menu/Botoes/Botao.hpp"

namespace Menu {
MenuOpcoes::MenuOpcoes()
    : Menu(1, 2,
           sf::Vector2f(POS_TEXTO_OPTION_X - TAM_TEXTO_OPTION_X * 1.5,
                        POS_TEXTO_OPTION_Y - TAM_TEXTO_OPTION_Y / 2),
           sf::Vector2f(TAM_TEXTO_OPTION_X, TAM_TEXTO_OPTION_Y), "OPCOES",
           150) {
  inicializaBotao();
  titulo.setColor(sf::Color::White);
}

MenuOpcoes::~MenuOpcoes() { /*
      if(pFase_Planicie != nullptr){
          delete pFase_Planicie;
      }
      if(pFase_Castelo != nullptr){
          delete pFase_Castelo;
      }*/
}

void MenuOpcoes::executar() {
  switch (numSelec) {
  case 0: // Fase 1
    pFase_Planicie = new Fases::Fase_Planicie();
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pFase_Planicie));
    break;
  case 1: // Fase 2
    pFase_Castelo = new Fases::Fase_Castelo();
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pFase_Castelo));
    break;
  case 2:
    pMaquinaDeEstado->popEstado();
    break;
  default:
    break;
  }
}
void MenuOpcoes::inicializaBotao() {
  Botoes::Botao *pBotao = nullptr;
  pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f - 100),
                             std::string(" Fase 1"));
  pBotao->selecionado(true);

  Menu::lBotao.push_back(pBotao);
  Menu::it = Menu::lBotao.begin();

  pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f),
                             std::string(" Fase 2"));
  Menu::lBotao.push_back(pBotao);

  pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f + 100),
                             std::string(" Voltar"));
  Menu::lBotao.push_back(pBotao);
  numOpc = 3;
}

void MenuOpcoes::update(const double dt) { Menu::update(dt); }
void MenuOpcoes::draw() { Menu::draw(); }
} // namespace Menu