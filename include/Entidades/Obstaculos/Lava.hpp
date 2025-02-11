#pragma once

#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Obstaculo.hpp"

#define TEMPO_QUEIMADURA 1.f
#define CAMINHO_BLOCO_LAVA "data\\Sprites\\blocos\\lava.png"

namespace Entidades {
namespace Obstaculos {
class Lava : public Obstaculo {
private:
  float danoTime;
  static unsigned int queimadura;
  Animacao::AnimacaoBloco bloco;
  Animacao::AnimacaoContext contexto;

public:
  Lava(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
  Lava(nlohmann::json atributos, const int pos, const Entidades::ID id);
  ~Lava();
  void animacao();
  void queimar(Entidade *entidade);
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos
} // namespace Entidades