#pragma once

#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Obstaculo.hpp"

#define TAM_PLATAFORMA_X 200.f
#define TAM_PLATAFORMA_Y 60.0f
namespace Entidades {
namespace Obstaculos {
class ObstaculoFacil : public Obstaculo {
private:
  Animacao::AnimacaoBloco bloco;
  Animacao::AnimacaoContext contexto;

public:
  ObstaculoFacil(const sf::Vector2f pos, const sf::Vector2f,
                 const Entidades::ID id);
  ObstaculoFacil(nlohmann::json atributos, const int pos,
                 const Entidades::ID id);
  ~ObstaculoFacil();
  void tratarColisao(Entidade *entidade);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos

} // namespace Entidades