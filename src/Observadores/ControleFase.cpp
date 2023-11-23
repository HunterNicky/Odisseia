#include "Observadores/ControleFase.hpp"
#include "Estados/MaquinaDeEstado.hpp"
#include "Menu/MenuPausa.hpp"
#include <ostream>

namespace Observadores {
Estados::MaquinaDeEstado *ControleFase::pMaquinaDeEstado =
    Estados::MaquinaDeEstado::getInstance();

ControleFase::ControleFase()
    : Observer(), pFase(nullptr), pPausa(nullptr), cima("Up"), baixo("Down"),
      enter("Enter"), fechar("Escape") {}

ControleFase::~ControleFase() {}

void ControleFase::setFase(Menu::MenuPausa *pPausa) { this->pPausa = pPausa; }

void ControleFase::jogadorMorreu() {}

void ControleFase::notifyPressed(const sf::Keyboard::Key key) {
  if (pPausa && pMaquinaDeEstado->getEstadoAtual()->getAtivo()) {
    if (keyboard[key] == fechar) {
      pMaquinaDeEstado->popEstado();
    } else if (keyboard[key] == cima) {
      pPausa->select(true);
    } else if (keyboard[key] == baixo) {
      pPausa->select(false);
    }
  }
}

void ControleFase::notifyReleased(const sf::Keyboard::Key key) {}
} // namespace Observadores