#pragma once

#include "Entidades/Entidade.hpp"
#include "Gerenciadores/QuadTree.hpp"
#include "Lista/ListaDeEntidades.hpp"
#include "Mediator.hpp"
#include "QuadTree.hpp"
#include <SFML/Graphics.hpp>


namespace Gerenciadores {
class GerenciadorDeColisao : public Mediator {
private:
  static GerenciadorDeColisao *instance;
  Quadtree quadTree;
  GerenciadorDeColisao();

public:
  virtual ~GerenciadorDeColisao();
  static GerenciadorDeColisao *getInstance();
  void setList(Lista::ListaDeEntidades *LE) override;
  void Notify(Entidades::Entidade *entidade) override;
  void atualizarQuadTree();
  void checkCollision(Entidades::Entidade *entidade,
                      Entidades::Entidade *entidade2,
                      const sf::Vector2f mtv) const;
};

} // namespace Gerenciadores