#pragma once
#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"

namespace Entidades {
namespace Obstaculos {
class Obstaculo : public Entidade {
protected:
  static Gerenciadores::GerenciadorFisico *gFisico;
  bool danoso;
public:
  Obstaculo(const sf::Vector2f pos, const sf::Vector2f size,
            const Entidades::ID id);
  ~Obstaculo();
  virtual void verificaSolo(sf::Vector2f mtv);
  virtual void tratarColisao(Entidade *entidade, const sf::Vector2f mtv) = 0;
  virtual void executar() = 0;
  virtual void update() = 0;
  virtual void salvar(std::ostringstream *entrada) = 0;
};
} // namespace Obstaculos
} // namespace Entidades
