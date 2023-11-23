#pragma once

#include "..\Personagens\Personagem.hpp"
#include "Entidades/Entidade.hpp"
#include "Obstaculo.hpp"


#define TEMPO_QUEIMADURA 1.f

namespace Entidades {
namespace Obstaculos {
class Lava : public Obstaculo {
private:
  unsigned int queimadura;

public:
  Lava(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
  ~Lava();
  void queimar(Entidade *entidade);
  void tratarColisao(Entidade *entidade);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos
} // namespace Entidades