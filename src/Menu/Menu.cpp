#include "../../include/Menu/Menu.hpp"
#include "Observadores/ControleMenu.hpp"
namespace Menu {
Estados::MaquinaDeEstado *Menu::pMaquinaDeEstado =
    Estados::MaquinaDeEstado::getInstance();
Observadores::ControleMenu *Menu::pControleMenu =
    Observadores::ControleMenu::getInstance();

Menu::Menu(const int id, int numOpc, const sf::Vector2f pos,
           const sf::Vector2f size, const std::string texto,
           const unsigned int tamF)
    : Estado(static_cast<Estados::MaquinaDeEstado *>(pMaquinaDeEstado), id),
      titulo(pos, size, texto, tamF), numOpc(numOpc), numSelec(0) {
  pControleMenu->setMenu(this);
}

Menu::~Menu() {
  Botoes::Botao *botao = NULL;
  while (lBotao.size() != 0) {
    botao = lBotao.back();
    delete (botao);
    lBotao.pop_back();
  }
  lBotao.clear();
}

void Menu::update(const double dt) {
  std::list<Botoes::Botao *>::iterator it2;
  it2 = lBotao.begin();
  pGrafico->setViewCenter(sf::Vector2f(1280.f / 2, 720.f / 2));
}

void Menu::draw() {
  std::list<Botoes::Botao *>::iterator it2;
  for (it2 = lBotao.begin(); it2 != lBotao.end(); it2++) {
    Botoes::Botao *botao = *it2;
    botao->draw();
  }
  pGrafico->drawText(titulo.getSfTexto());
}

void Menu::select(const bool direcao) {
  (*it)->selecionado(false);
  if (direcao) {
    if (it == lBotao.begin()) {
      it = --lBotao.end();
      numSelec = numOpc - 1;
    } else {
      numSelec--;
      it--;
    }
  } else {
    it++;
    numSelec++;
    if (it == lBotao.end()) {
      it = lBotao.begin();
      numSelec = 0;
    }
  }
  (*it)->selecionado(true);
}
} // namespace Menu