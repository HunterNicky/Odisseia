#include "..\..\include\Gerenciadores\GerenciadorDeEvento.hpp"

namespace Gerenciadores {
GerenciadorDeEvento *GerenciadorDeEvento::pEvento = nullptr;
GerenciadorGrafico *GerenciadorDeEvento::pGrafico =
    GerenciadorGrafico::getInstance();

GerenciadorDeEvento::GerenciadorDeEvento() : removido(false) {}

GerenciadorDeEvento::~GerenciadorDeEvento() {
  lObserver.clear();
  delete (pEvento);
}

GerenciadorDeEvento *GerenciadorDeEvento::getInstance() {
  if (pEvento == nullptr) {
    pEvento = new GerenciadorDeEvento();
  }
  return pEvento;
}

void GerenciadorDeEvento::addObserver(Observadores::Observer *observer) {
  if (observer) {
    lObserver.push_back(observer);
  }
}

void GerenciadorDeEvento::removeObserver(Observadores::Observer *observer) {
  if (observer) {
    lObserver.remove(observer);
    delete (observer);
    removido = true;
  }
}

void GerenciadorDeEvento::stage() {
  sf::Event event;
  while (pGrafico->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      pGrafico->close();
    } else if (event.type == sf::Event::KeyPressed && !removido) {
      for (auto obs : lObserver) {
        if (obs && !removido)
          obs->notifyPressed(event.key.code);
        if (removido)
          break;
      }
    } else if (event.type == sf::Event::KeyReleased && !removido) {
      for (auto obs : lObserver) {
        if (obs && !removido)
          obs->notifyReleased(event.key.code);
        if (removido)
          break;
      }
    }
    removido = false;
  }
}

} // namespace Gerenciadores
