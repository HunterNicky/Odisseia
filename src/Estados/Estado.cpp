#include "..\..\include\Estados\Estado.hpp"

namespace Estados {

Estado::Estado(MaquinaDeEstado *pMaquinaDeEstado, const unsigned int id)
    : Ente(sf::Vector2f(0, 0), sf::Vector2f(0, 0)),
      pMaquinaDeEstado(pMaquinaDeEstado), id(id), ativo(true) {}

Estado::~Estado() {}

void Estado::setMaquinaDeEstado(MaquinaDeEstado *pMaquinaDeEstado) {
  this->pMaquinaDeEstado = pMaquinaDeEstado;
}

const bool Estado::getAtivo() const { return ativo; }

unsigned int Estado::getID() const { return id; }

void Estado::setAtivo(const bool ativo) { this->ativo = ativo; }
} // namespace Estados
