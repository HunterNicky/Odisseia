#pragma once
#include "Obstaculo.hpp"

#define TAM_PLATAFORMA_X 200.f
#define TAM_PLATAFORMA_Y 60.0f

namespace Entidades {
namespace Obstaculos {
class Caixa : public Obstaculo {
private:
  bool PortalAtivo;
  Animacao::AnimacaoBloco bloco;
  Animacao::AnimacaoContext contexto;

public:
  Caixa(const sf::Vector2f pos, const sf::Vector2f, const Entidades::ID id,
        const std::string path);
  Caixa(nlohmann::json atributos, const int pos, const Entidades::ID id);
  ~Caixa();
  void animacao();
  void colocarTextura(const char c);
  const bool getPortalAtivo() const;
  void setPortalAtivo(const bool ativo);
  void tratarColisao(Entidade *entidade);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos

} // namespace Entidades