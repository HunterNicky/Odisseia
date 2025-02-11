#include "..\..\include\Menu\MenuPrincipal.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Fases/Fase_Castelo.hpp"
#include "Fases/Fase_Planicie.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "Menu/MenuPrincipal.hpp"
#include <fstream>
#include <string>

namespace Menu {
Estados::MaquinaDeEstado *MenuPrincipal::pMaquinaDeEstado =
    Estados::MaquinaDeEstado::getInstance();

MenuPrincipal::MenuPrincipal(Estados::Jogo *pJogo)
    : Menu(0, 5, sf::Vector2f(POS_BOTAO_X - TAMANHO_BOTAO_X/2, POS_BOTAO_Y - TAMANHO_BOTAO_Y),
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "ODISSEIA", 180),
      pJogo(pJogo), pOpcao(nullptr) {
  fase = nullptr;
  inicializaBotao();
  titulo.setColor(sf::Color::Green);
  titulo.setTextFont(CAMINHO_FONTE_TITULO);
  subTitulo = new Botoes::Texto(
      sf::Vector2f(POS_BOTAO_X - TAMANHO_BOTAO_X, POS_BOTAO_Y*1.5),
      sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "Temporalis", 180);
  subTitulo->setTextFont(CAMINHO_FONTE_TITULO);
  subTitulo->setColor(sf::Color::Green);
}

MenuPrincipal::~MenuPrincipal() {
  if (fase != nullptr) {
    delete fase;
  }
  pGrafico->close();
}

void MenuPrincipal::update(const double dt) {
  Menu::update(dt);
  pControleMenu->setMenu(this);
}

void MenuPrincipal::carregarJogo() {
  nlohmann::json arquivoEntidades;
  nlohmann::json arquivoFase;
  std::ifstream arquivo1("data/Save/arquivoEntidades.json");
  std::ifstream arquivo2("data/Save/arquivoFase.json");
  arquivo1 >> arquivoEntidades;
  arquivo2 >> arquivoFase;

  if (!arquivo1) {
    std::cout << "ERRO AO ABRIR ARQUIVO_ENTIDADES!" << std::endl;
  }
  if (!arquivo2) {
    std::cout << "ERRO AO ABRIR ARQUIVO_FASE!" << std::endl;
  }
  if (arquivoFase[0]["IdFase"][0] == 1) {
    Fases::Fase_Planicie *pFase_Planicie = new Fases::Fase_Planicie(arquivoEntidades, arquivoFase);
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pFase_Planicie));
  } else {
    Fases::Fase_Castelo *pFase_Castelo = new Fases::Fase_Castelo(arquivoEntidades, arquivoFase);
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pFase_Castelo));
  }
}

void MenuPrincipal::executar() {
  switch (numSelec) {
  case 0:
    fase = new Fases::Fase_Planicie(1);
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(fase));
    break;
  case 1:
    pOpcao = new MenuOpcoes();
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pOpcao));
    break;
  case 2:
    carregarJogo();
    break;
  case 3: {
    MenuRanking *pRanking = new MenuRanking();
    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pRanking));
  } break;
  case 4:
    pGrafico->close();
    pMaquinaDeEstado->popEstado();
    break;
  default:
    break;
  }
}

void MenuPrincipal::inicializaBotao() {
  Botoes::Botao *pBotao = NULL;

  pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 - 50),
                             std::string(" Novo Jogo"));
  pBotao->selecionado(true);

  Menu::lBotao.push_back(pBotao);
  Menu::it = Menu::lBotao.begin();

  pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 50),
                             std::string(" Opcoes"));
  Menu::lBotao.push_back(pBotao);

  pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 150),
                             std::string(" Carregar"));
  Menu::lBotao.push_back(pBotao);

  pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 250),
                             std::string(" Ranking"));
  Menu::lBotao.push_back(pBotao);

  pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 350),
                             std::string(" Sair"));
  Menu::lBotao.push_back(pBotao);
  numOpc = 3;
}

void MenuPrincipal::draw() {
  Menu::draw();
  pGrafico->drawText(subTitulo->getSfTexto());
}
} // namespace Menu
