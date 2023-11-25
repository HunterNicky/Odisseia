#include "Gerenciadores/Colisao/ConcreteGerenciadorColisao.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/Colisao/VerificaColisao_QuadTree.hpp"
#include <iostream>
#include <vector>

namespace Gerenciadores {
namespace Colisao {
ConcreteGerenciadorColisao *ConcreteGerenciadorColisao::instance = nullptr;

ConcreteGerenciadorColisao::ConcreteGerenciadorColisao()
    : VerificaColisao_QuadTree(
          sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(10000.f, 3000.f)),
          0) {}
ConcreteGerenciadorColisao::~ConcreteGerenciadorColisao() { delete (instance); }

void ConcreteGerenciadorColisao::setList(Lista::ListaDeEntidades *LE) {
  this->LE = LE;
  for (unsigned int i = 0; i < this->LE->getSize(); i++) {
    VerificaColisao_QuadTree.insert(this->LE->operator[](i));
  }
}

ConcreteGerenciadorColisao *ConcreteGerenciadorColisao::getInstance() {
  if (instance == nullptr) {
    instance = new ConcreteGerenciadorColisao();
  }
  return instance;
}

void ConcreteGerenciadorColisao::Notify(Entidades::Entidade *entidade) {
  atualizarVerificaColisao_QuadTree();
  sf::Vector2f mtv(0.f, 0.f);
  sf::FloatRect collisionRect;
  std::vector<Entidades::Entidade *> colliEnte;
  if (VerificaColisao_QuadTree.detectCollision(entidade, colliEnte,
                                               collisionRect, mtv)) {
    for (auto &entidade2 : colliEnte) {
      checkCollision(entidade, entidade2, mtv);
    }
  } else {
    entidade->verificaSolo(mtv);
  }
}

void ConcreteGerenciadorColisao::checkCollision(Entidades::Entidade *entidade,
                                                Entidades::Entidade *entidade2,
                                                const sf::Vector2f mtv) const {
  if (entidade2 != nullptr) {
    entidade->tratarColisao(entidade2, mtv);
  } else {
    entidade->verificaSolo(mtv);
  }
}

void ConcreteGerenciadorColisao::atualizarVerificaColisao_QuadTree() {
  VerificaColisao_QuadTree.clear();
  for (unsigned int i = 0; i < this->LE->getSize(); i++) {
    VerificaColisao_QuadTree.insert(this->LE->operator[](i));
  }
}
} // namespace Colisao
} // namespace Gerenciadores