#include "Observadores/ControleJogador.hpp"
#include "Estados/Estado.hpp"

namespace Observadores {
Estados::MaquinaDeEstado *ControleJogador::pMaquinaDeEstado =
    Estados::MaquinaDeEstado::getInstance();

ControleJogador::ControleJogador(Entidades::Personagens::Jogador *pJogador,
                                 Fases::Fase *pFase)
    : Observer(), pJogador(pJogador), pFase(pFase), pular("W"), esquerda("A"),
      direita("D"), correr("LShift"), atacar("Space"), fechar("Escape") {}

ControleJogador::~ControleJogador() {}

void ControleJogador::setJogador(Entidades::Personagens::Jogador *pJogador) {
  this->pJogador = pJogador;
}
void ControleJogador::jogadorNeutralizado() {
  // pMaquinaDeEstado->popEstado(); //retira o estado atual
  Menu::MenuGameOver *pGameOver = new Menu::MenuGameOver(pFase);
  pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pGameOver));
}
void ControleJogador::notifyPressed(const sf::Keyboard::Key key) {
  if (pJogador && pMaquinaDeEstado->getEstadoAtual()->getAtivo()) {
    if (keyboard[key] == atacar) {
      pJogador->atacar();
    }
    if (keyboard[key] == direita) {
      pJogador->direcionar(true);
    } else if (keyboard[key] == esquerda) {
      pJogador->direcionar(false);
    }
    if (keyboard[key] == pular) {
      pJogador->pular();
    } else if (keyboard[key] == correr) {
      pJogador->correr();
    }
    if (keyboard[key] == fechar) {
      Menu::MenuPausa *pPausa =
          new Menu::MenuPausa(static_cast<Fases::Fase *>(pFase));
      pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado *>(pPausa));
    }
  }
}

void ControleJogador::notifyReleased(const sf::Keyboard::Key key) {
  if (pJogador) {
    if (keyboard[key] == direita) {
      pJogador->parar();
    } else if (keyboard[key] == esquerda) {
      pJogador->parar();
    } else if (keyboard[key] == correr) {
      pJogador->parar();
    } else if (keyboard[key] == pular) {
      pJogador->setOnFloor(false);
      pJogador->pular();
    }
  }
}
} // namespace Observadores
