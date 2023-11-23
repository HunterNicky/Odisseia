#pragma once

#include "SFML/Graphics.hpp"
#include <vector>


namespace Entidades {
class Entidade;
}

namespace Gerenciadores {
class Quadtree {
private:
  static const int MAX_CAPACITY = 4;

  sf::FloatRect boundary;
  unsigned int capacity;
  std::vector<Entidades::Entidade *> entities;
  Quadtree *nodes[4];

  bool isSubdivided();
  void subdivide();

public:
  Quadtree(sf::FloatRect boundary, int capacity);
  ~Quadtree();

  void insert(Entidades::Entidade *entidade);
  void query(sf::FloatRect rect, std::vector<Entidades::Entidade *> &result);
  void clear();

  bool detectCollision(Entidades::Entidade *entidade,
                       std::vector<Entidades::Entidade *> &colliEnti,
                       sf::FloatRect &collisionRect, sf::Vector2f &mtv);
};
} // namespace Gerenciadores
