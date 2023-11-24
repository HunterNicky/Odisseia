#include "Gerenciadores/QuadTree.hpp"
#include "Entidades/Entidade.hpp"
#include <valarray>

namespace Gerenciadores {
Quadtree::Quadtree(sf::FloatRect boundary, int capacity) {
  this->boundary = boundary;
  this->capacity = capacity;
  for (int i = 0; i < 4; ++i) {
    nodes[i] = nullptr;
  }
}

Quadtree::~Quadtree() { clear(); }

bool Quadtree::isSubdivided() { return nodes[0] != nullptr; }

void Quadtree::subdivide() {
  sf::Vector2f center = boundary.getPosition() + 0.5f * boundary.getSize();
  sf::Vector2f halfSize = 0.5f * boundary.getSize();

  nodes[0] =
      new Quadtree(sf::FloatRect(center.x - halfSize.x, center.y - halfSize.y,
                                 halfSize.x, halfSize.y),
                   capacity);
  nodes[1] = new Quadtree(
      sf::FloatRect(center.x, center.y - halfSize.y, halfSize.x, halfSize.y),
      capacity);
  nodes[2] = new Quadtree(
      sf::FloatRect(center.x - halfSize.x, center.y, halfSize.x, halfSize.y),
      capacity);
  nodes[3] = new Quadtree(
      sf::FloatRect(center.x, center.y, halfSize.x, halfSize.y), capacity);
}

void Quadtree::insert(Entidades::Entidade *entidade) {
  if (!boundary.intersects(entidade->getBody()->getGlobalBounds()))
    return;

  if (entities.size() < capacity || !isSubdivided()) {
    entities.push_back(entidade);
  } else {
    if (!isSubdivided())
      subdivide();

    for (int i = 0; i < 4; ++i) {
      nodes[i]->insert(entidade);
    }
  }
}

void Quadtree::query(sf::FloatRect rect,
                     std::vector<Entidades::Entidade *> &result) {
  if (!boundary.intersects(rect))
    return;

  for (auto &entity : entities) {
    if (entity->getBody()->getGlobalBounds().intersects(rect)) {
      result.push_back(entity);
    }
  }

  if (isSubdivided()) {
    for (int i = 0; i < 4; ++i) {
      nodes[i]->query(rect, result);
    }
  }
}

void Quadtree::clear() {
  entities.clear();

  for (int i = 0; i < 4; ++i) {
    if (nodes[i] != nullptr) {
      nodes[i]->clear();
      delete nodes[i];
      nodes[i] = nullptr;
    }
  }
}

bool Quadtree::detectCollision(Entidades::Entidade *entidade,
                               std::vector<Entidades::Entidade *> &colliEnti,
                               sf::FloatRect &collisionRect,
                               sf::Vector2f &mtv) {
  if (!boundary.intersects(entidade->getBody()->getGlobalBounds()))
    return false;

  bool collisionDetected = false;
  sf::FloatRect collisionRect2 = entidade->getBody()->getGlobalBounds();
  for (auto &otherEntity : entities) {
    if (otherEntity != entidade &&
        otherEntity->getBody()->getGlobalBounds().intersects(
            entidade->getBody()->getGlobalBounds())) {
      collisionRect = otherEntity->getBody()->getGlobalBounds();

      float overlapX = std::min(collisionRect2.left + collisionRect2.width,
                                collisionRect.left + collisionRect.width) -
                       std::max(collisionRect2.left, collisionRect.left);

      float overlapY = std::min(collisionRect2.top + collisionRect2.height,
                                collisionRect.top + collisionRect.height) -
                       std::max(collisionRect2.top, collisionRect.top);

      if (overlapX - overlapY < -std::abs(entidade->getVel().y)) {
        mtv.x = (collisionRect2.left + collisionRect2.width / 2.f <
                 collisionRect.left + collisionRect.width / 2.f)
                    ? -overlapX
                    : overlapX;
      }else if(overlapY - overlapX < -std::abs(entidade->getVel().x)) {
        mtv.y = (collisionRect2.top + collisionRect2.height / 2.f <
                 collisionRect.top + collisionRect.height / 2.f)
                    ? -overlapY
                    : overlapY;
      }
      colliEnti.push_back(otherEntity);
      collisionDetected = true;
    }
  }

  if (isSubdivided()) {
    for (int i = 0; i < 4; ++i) {
      sf::FloatRect childCollisionRect;
      sf::Vector2f childMTV;

      if (nodes[i]->detectCollision(entidade, colliEnti, childCollisionRect,
                                    childMTV)) {
        collisionDetected = true;
        if (std::abs(childMTV.x) < std::abs(mtv.x))
          mtv.x = childMTV.x;
        if (std::abs(childMTV.y) < std::abs(mtv.y))
          mtv.y = childMTV.y;

        if (childCollisionRect.width < collisionRect.width)
          collisionRect.width = childCollisionRect.width;
        if (childCollisionRect.height < collisionRect.height)
          collisionRect.height = childCollisionRect.height;
      }
    }
  }
  return collisionDetected;
}
} // namespace Gerenciadores
