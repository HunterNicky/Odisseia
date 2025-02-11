#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

namespace Entidades {
class Entidade;
}

namespace Gerenciadores {
namespace Colisao {
class VerificaColisao_QuadTree {
private:
  static const int MAX_CAPACITY = 4;

  sf::FloatRect boundary;
  unsigned int capacity;
  std::vector<Entidades::Entidade *> entities;
  VerificaColisao_QuadTree *nodes[4];

  bool isSubdivided();
  void subdivide();

public:
  VerificaColisao_QuadTree(sf::FloatRect boundary, int capacity);
  ~VerificaColisao_QuadTree();

  void insert(Entidades::Entidade *entidade);
  void query(sf::FloatRect rect, std::vector<Entidades::Entidade *> &result);
  void clear();

  bool detectCollision(Entidades::Entidade *entidade,
                       std::vector<Entidades::Entidade *> &colliEnti,
                       sf::FloatRect &collisionRect, sf::Vector2f &mtv);
};

} // namespace Colisao
} // namespace Gerenciadores
