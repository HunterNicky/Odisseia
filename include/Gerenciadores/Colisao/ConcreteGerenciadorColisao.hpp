#pragma once

#include "Entidades/Entidade.hpp"
#include "Gerenciadores/Colisao/VerificaColisao_QuadTree.hpp"
#include "Lista/ListaDeEntidades.hpp"
#include "PadraoProjeto_Mediator.hpp"
#include "VerificaColisao_QuadTree.hpp"
#include <SFML/Graphics.hpp>

namespace Gerenciadores {
namespace Colisao {
class ConcreteGerenciadorColisao : public PadraoProjeto_Mediator {
private:
  static ConcreteGerenciadorColisao *instance;
  VerificaColisao_QuadTree VerificaColisao_QuadTree;
  ConcreteGerenciadorColisao();

public:
  virtual ~ConcreteGerenciadorColisao();
  static ConcreteGerenciadorColisao *getInstance();
  void setList(Lista::ListaDeEntidades *LE) override;
  void Notify(Entidades::Entidade *entidade) override;
  void atualizarVerificaColisao_QuadTree();
  void checkCollision(Entidades::Entidade *entidade,
                      Entidades::Entidade *entidade2,
                      const sf::Vector2f mtv) const;
};
} // namespace Colisao
} // namespace Gerenciadores