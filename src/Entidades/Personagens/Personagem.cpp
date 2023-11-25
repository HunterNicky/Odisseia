#include "Entidades/Personagens/Personagem.hpp"
#include "Gerenciadores/Colisao/CalculadorFisico.hpp"
#include <iostream>
namespace Entidades {
namespace Personagens {
Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size,
                       const Entidades::ID id)
    : Entidade(pos, size, id), ataque(false), jumpTime(0) {}
Personagem::~Personagem() {}

void Personagem::verificaSolo(const sf::Vector2f mtv) {
  if (mtv.y < 0.f) {
    onFloor = true;
    jumpTime = 0.f;
  } else {
    onFloor = false;
  }
}

void Personagem::setOnFloor(const bool floor) { this->onFloor = floor; }

void Personagem::setAtaque(const bool ataque) { this->ataque = ataque; }

const int Personagem::getNum_vidas() const { return num_vidas; }

const float Personagem::getJumpTime() const { return jumpTime; }

const bool Personagem::getAtacando() { return ataque; }

void Personagem::move() {
  Entidade::body->setPosition(pos);
  gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}
} // namespace Personagens
} // namespace Entidades
