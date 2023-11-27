#pragma once

#include "Entidades/Obstaculos/Obstaculo.hpp"
#include <SFML/Graphics.hpp>

namespace Entidades {
class Entidade;
}
namespace Gerenciadores {
namespace Colisao {
class CalculadorFisico {
private:
  CalculadorFisico();
  static CalculadorFisico *instance;
  sf::Vector2f forcaPadrao;
  double dt;

public:
  ~CalculadorFisico();
  void update(double dt);
  static CalculadorFisico *getInstance();
  void calVel(Entidades::Entidade *entidade);
  void calAcc(Entidades::Entidade *entidade);
  void calColision(Entidades::Entidade *entidade,
                   Entidades::Entidade *entidade1);
  void executarFisica(Entidades::Entidade *entidade);
  void setForcaPadrao(const sf::Vector2f forcaPadrao);
  const sf::Vector2f calDrag(Entidades::Entidade *entidade) const;
  float getDeltaTime() const;
};

} // namespace Colisao
} // namespace Gerenciadores