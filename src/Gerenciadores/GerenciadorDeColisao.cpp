#include "..\..\include\Gerenciadores\GerenciadorDeColisao.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/QuadTree.hpp"
#include <iostream>
#include <vector>

namespace Gerenciadores {
GerenciadorDeColisao *GerenciadorDeColisao::instance = nullptr;

GerenciadorDeColisao::GerenciadorDeColisao()
    : quadTree(
          sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(10000.f, 2000.f)),
          0) {}
GerenciadorDeColisao::~GerenciadorDeColisao() { delete (instance); }

void GerenciadorDeColisao::setList(Lista::ListaDeEntidades *LE) {
  this->LE = LE;
  for (unsigned int i = 0; i < this->LE->getSize(); i++) {
    quadTree.insert(this->LE->operator[](i));
  }
}

GerenciadorDeColisao *GerenciadorDeColisao::getInstance() {
  if (instance == nullptr) {
    instance = new GerenciadorDeColisao();
  }
  return instance;
}

void GerenciadorDeColisao::Notify(Entidades::Entidade *entidade) {
  atualizarQuadTree();
  sf::Vector2f mtv(0.f, 0.f);
  sf::FloatRect collisionRect;
  std::vector<Entidades::Entidade *> colliEnte;
  if (quadTree.detectCollision(entidade, colliEnte, collisionRect, mtv)) {
    for (auto &entidade2 : colliEnte) {
      checkCollision(entidade, entidade2, mtv);
    }
  } else {
    entidade->verificaSolo(mtv);
  }
}

void GerenciadorDeColisao::checkCollision(Entidades::Entidade *entidade,
                                          Entidades::Entidade *entidade2,
                                          const sf::Vector2f mtv) const {
  if (entidade2 != nullptr) {
    entidade->tratarColisao(entidade2, mtv);
  } else {
    entidade->verificaSolo(mtv);
  }
}

void GerenciadorDeColisao::atualizarQuadTree() {
  quadTree.clear();
  for (unsigned int i = 0; i < this->LE->getSize(); i++) {
    quadTree.insert(this->LE->operator[](i));
  }
}
} // namespace Gerenciadores